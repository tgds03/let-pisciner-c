#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

echo ""
echo -n "Put stubs in $EXAM_DIR: "
cp "$STUB_PATH/$EXAM_DIR/"* "$REPO_PATH/$EXAM_DIR/" || exit 1
echo "done"

getentrypoint() {
	local filelist=*.c
	local entryfile=""
	for file in "$REPO_PATH/$EXAM_DIR/"*.c; do
		content=cc -E -I$INCLUDE_PATH -I"$INCLUDE_PATH/fake_libc" $file | $SHELL_PATH/getentry.py
		echo $content
#if [ -n $(cat $file | grep )
	done
}

echo -n "Compile and Run $EXAM_DIR: "
if [ -z "$COMPILE_CMD" ]; then
	TARGET_PATH=$(echo "$REPO_PATH/$EXAM_DIR/"*.c | awk '{print $1}')
	STUB_MD5=$(md5sum "$STUB_PATH/$EXAM_DIR/stub.c" | awk '{print $1}')
	$(cd "$REPO_PATH/$EXAM_DIR/" && \
		cc -fsanitize=address -g -o app -Wall -Wextra -Werror *.c $SHELL_PATH/entrypoint.c \
			-L$LIB_PATH -l common -I$INCLUDE_PATH \
			-DTARGET_PATH=\"$TARGET_PATH\" -DSTUB_C_MD5=\"$STUB_MD5\" \
	) || exit 1
else
	$(cd "$REPO_PATH/$EXAM_DIR/" && $COMPILE_CMD) || exit 1
fi
echo "done"
