#!/bin/bash

if [ -n "$(ls "$STUB_PATH/$EXAM_DIR")" ]; then
	cp -r "$STUB_PATH/$EXAM_DIR/"* "$REPO_PATH/$EXAM_DIR/" || exit 1
fi

getentrypoint() {
	local filelist=*.c
	local entryfile="${SHELL_PATH}entrypoint.c"
	for file in "$REPO_PATH/$EXAM_DIR/"*.c; do
		content=$(cc -E -I"$INCLUDE_PATH" -I"$INCLUDE_PATH/fake_libc" $file | "$SHELL_PATH/cmd/getentry.py") || return 1
		if [ -n "$content" ]; then
			if [ -z "$entryfile" ]; then
				echo "Found multiple main function in $EXAM_DIR."
				return 1
			else
				entryfile=""
			fi
		fi
	done
	echo "$entryfile"
	return 0
}

getcmd() {
	local CC_OUTFILE='app';
	local CC_OPTION=("sanitize=address");
	local CC_WARNING=('all' 'extra' 'error' 'no-unused-result');
	local CC_INCLUDE=($INCLUDE_PATH);
	local CC_LIBPATH=($LIB_PATH);
	local CC_LIBRARY=('common');
	local CC_DEFINE=("TARGET_PATH=\"$TARGET_PATH\"" "STUB_C_MD5=\"$STUB_MD5\"");
	local CC_TARGET=('*.c' "$entrypoint");
	local COMPILE_CMD="cc -o $CC_OUTFILE -g3 -Og "

	if [ -f "$1" ]; then
		source <(cat "$1" | sed -E '/COMPILE_CMD/d');
	fi

	for opt in "${CC_OPTION[@]}"; do COMPILE_CMD+="-f$opt "; done;
	for opt in "${CC_WARNING[@]}"; do COMPILE_CMD+="-W$opt "; done;
	for opt in "${CC_TARGET[@]}"; do COMPILE_CMD+="$opt "; done;

	for opt in "${CC_DEFINE[@]}"; do COMPILE_CMD+="-D$opt "; done;
	for opt in "${CC_INCLUDE[@]}"; do COMPILE_CMD+="-I$opt "; done;
	for opt in "${CC_LIBPATH[@]}"; do COMPILE_CMD+="-L$opt "; done;
	for opt in "${CC_LIBRARY[@]}"; do COMPILE_CMD+="-l$opt "; done;


	if [ -f "$1" ]; then
		source <(cat "$1" | sed -nE '/COMPILE_CMD/p');
	fi

	echo -n "$COMPILE_CMD"
}

TARGET_PATH=$(echo "$REPO_PATH/$EXAM_DIR"*.{c,h} | awk '{print $1}')
STUB_MD5=$(md5sum <(echo $TARGET_PATH) | awk '{print $1}')
entrypoint=$(getentrypoint)
if [ $? -eq 1 ]; then
	exit 1
fi

CMD=$(getcmd "$STUB_PATH/${EXAM_DIR}/env")
echo "$CMD"
cd "$REPO_PATH/$EXAM_DIR/" && eval "$CMD" || exit 1
