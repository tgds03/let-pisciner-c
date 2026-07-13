#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

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

TARGET_PATH=$(echo "$REPO_PATH/$EXAM_DIR/"*.c | awk '{print $1}')
STUB_MD5=$(md5sum <(echo $TARGET_PATH) | awk '{print $1}')

if [ -z "$COMPILE_CMD" ]; then
	entrypoint=$(getentrypoint)
	if [ $? -eq 1 ]; then
		exit 1
	fi
	$(cd "$REPO_PATH/$EXAM_DIR/" && \
		cc -fsanitize=address -g -o app -Wall -Wextra -Werror *.c $entrypoint \
			-L$LIB_PATH -l common -I$INCLUDE_PATH \
			-DTARGET_PATH=\"$TARGET_PATH\" -DSTUB_C_MD5=\"$STUB_MD5\" \
	) || exit 1
else
	$(cd "$REPO_PATH/$EXAM_DIR/" && $COMPILE_CMD) || exit 1
fi
