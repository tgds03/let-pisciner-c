#!/bin/bash

USAGE_STR="usage: $0 [repo_path] [stub_path]\n\
Don't use it before commit all you need, or file may be deleted!"

if [ "$#" -ne 2 ]; then
	echo -e $USAGE_STR
	exit
fi

if [ ! -d "$1" ]; then
	echo "can not find $1"
	echo -e $USAGE_STR
	exit
fi

if [ ! -d "$2" ]; then
	echo "can not find $2"
	echo -e $USAGE_STR
	exit
fi

echo ""
echo "Norminette: "
norminette "$1" || exit

for EXAM_DIR in $(cd "$2" && ls -d */); do
	echo ""
	echo -n "Put stubs in $EXAM_DIR: "
	cp "$2/$EXAM_DIR/"* "$1/$EXAM_DIR/" || continue
	echo "done"

	echo -n "Compile and Run $EXAM_DIR: "
	$(cd "$1/$EXAM_DIR/" && cc -o app -Wall -Wextra -Werror *.c && ./app > output) || continue
	echo "done"

	if [ -z "$(diff "$2/$EXAM_DIR/expected_output" "$1/$EXAM_DIR/output")" ]; then
		echo "$EXAM_DIR: Success"
	else 
		echo "$EXAM_DIR: Failed"
		diff "$2/$EXAM_DIR/expected_output" "$1/$EXAM_DIR/output"
	fi
done

echo ""
echo -n "Clean: "
$(cd "$1" && git clean -qf) && echo "done" 
