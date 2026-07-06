#!/bin/bash

if [ -f "$2/$EXAM_DIR/env" ]; then
	source "$2/$EXAM_DIR/env"
fi

echo ""
echo -n "Put stubs in $EXAM_DIR: "
cp "$2/$EXAM_DIR/"* "$1/$EXAM_DIR/" || continue
echo "done"

echo -n "Compile and Run $EXAM_DIR: "
if [ -z "$COMPILE_CMD" ]; then
	$(cd "$1/$EXAM_DIR/" && cc -o app -Wall -Wextra -Werror *.c && ./app > output) || continue
else
	$(cd "$1/$EXAM_DIR/" && $COMPILE_CMD && ./app > output) || continue
fi
echo "done"

if [ -z "$DIFF_CMD" ]; then
	DIFF_RESULT=$( diff "$2/$EXAM_DIR/expected_output" "$1/$EXAM_DIR/output" )
else
	DIFF_RESULT=$( eval "$DIFF_CMD" )
fi
if [ -z "$DIFF_RESULT" ]; then
	echo "$EXAM_DIR: Success"
else 
	echo "$EXAM_DIR: Failed"
	echo "$DIFF_RESULT"
fi
