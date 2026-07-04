#!/bin/bash

USAGE_STR="usage: run.sh [repo_path] [stub_path]
Don't use it before commit all you need, or file may be deleted!"

if [ "$#" -ne 2 ]; then
	echo $USAGE_STR
	exit
fi

if [ ! -d "$1" ]; then
	echo "can not find $1"
	echo $USAGE_STR
	exit
fi

if [ ! -d "$2" ]; then
	echo "can not find $2"
	echo $USAGE_STR
	exit
fi

echo "Norminette: "
norminette "$1" || exit
echo ""

for EXAM_DIR in $(cd "$2" && ls -d */); do
	echo -n "Put stubs in $EXAM_DIR: "
	cp "$2/$EXAM_DIR/"* "$1/$EXAM_DIR/" || continue
	echo "done"
	echo -n "Compile and Run $EXAM_DIR: "
	echo -ne $(cd "$1/$EXAM_DIR/" && cc -o app -Wall -Wextra -Werror *.c && ./app > output)
	echo "done"
	if [ -z $(diff "$2/$EXAM_DIR/expected_output" "$1/$EXAM_DIR/output") ]; then
		echo "$EXAM_DIR: Success"
	fi
	echo ""
done

echo -n "Clean: "
echo -ne $(cd "$1" && git clean -f && echo "done") 
