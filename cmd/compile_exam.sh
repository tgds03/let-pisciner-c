#!/bin/bash

if [ -n "$(ls "$STUB_PATH/$EXAM_DIR")" ]; then
	cp "$STUB_PATH/$EXAM_DIR/"* "$REPO_PATH/$EXAM_DIR/" || exit 1
fi

getentrypoint() {
	local filelist=*.c
	local entryfile="$SHELL_PATH/entrypoint.c"
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
	local CC_WARNING=('all' 'extra' 'error');
	local CC_INCLUDE=($INCLUDE_PATH);
	local CC_LIBPATH=($LIB_PATH);
	local CC_LIBRARY=('common');
	local CC_DEFINE=("TARGET_PATH=\"$TARGET_PATH\"" "STUB_C_MD5=\"$STUB_MD5\"");
	local CC_TARGET=('*.c' "$entrypoint");

	if [ -f "$1" ]; then
		source "$1" 
	fi

	echo -n "cc -g ";
	echo -n "-o $CC_OUTFILE ";
	for opt in "${CC_OPTION[@]}"; do echo -n "-f$opt "; done;
	for opt in "${CC_WARNING[@]}"; do echo -n "-W$opt "; done;
	for opt in "${CC_TARGET[@]}"; do echo -n "$opt "; done;

	for opt in "${CC_DEFINE[@]}"; do echo -n "-D$opt "; done;
	for opt in "${CC_INCLUDE[@]}"; do echo -n "-I$opt "; done;
	for opt in "${CC_LIBPATH[@]}"; do echo -n "-L$opt "; done;
	for opt in "${CC_LIBRARY[@]}"; do echo -n "-l$opt "; done;
}

TARGET_PATH=$(echo "$REPO_PATH/$EXAM_DIR/"*.{c,h} | awk '{print $1}')
STUB_MD5=$(md5sum <(echo $TARGET_PATH) | awk '{print $1}')
entrypoint=$(getentrypoint)
if [ $? -eq 1 ]; then
	exit 1
fi

cd "$REPO_PATH/$EXAM_DIR/" && pwd && $(getcmd "$STUB_PATH/$EXAM_DIR/env") || exit 1
