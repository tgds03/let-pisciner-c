#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

echo ""
echo -n "Put stubs in $EXAM_DIR: "
cp "$STUB_PATH/$EXAM_DIR/"* "$REPO_PATH/$EXAM_DIR/" || exit 1
echo "done"

echo -n "Compile and Run $EXAM_DIR: "
if [ -z "$COMPILE_CMD" ]; then
	$(cd "$REPO_PATH/$EXAM_DIR/" && cc -fsanitize=address -g -o app -Wall -Wextra -Werror *.c -L$LIB_PATH -l common -I$INCLUDE_PATH) || exit 1
else
	$(cd "$REPO_PATH/$EXAM_DIR/" && $COMPILE_CMD) || exit 1
fi
echo "done"
