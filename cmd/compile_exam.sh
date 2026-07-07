#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env"
fi

echo ""
echo -n "Put stubs in $EXAM_DIR: "
cp "$STUB_PATH/$EXAM_DIR/"* "$REPO_PATH/$EXAM_DIR/" || continue
echo "done"

echo -n "Compile and Run $EXAM_DIR: "
if [ -z "$COMPILE_CMD" ]; then
	echo $LIB_PATH
	$(cd "$REPO_PATH/$EXAM_DIR/" && cc -o app -Wall -Wextra -Werror *.c -L "$LIB_PATH" -l common -I "$INCLUDE_PATH" && ./app > output) || continue
else
	$(cd "$REPO_PATH/$EXAM_DIR/" && $COMPILE_CMD && ./app > output) || continue
fi
echo "done"
