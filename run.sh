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

for EXAM_NAME in $(cd "$2" && ls -d */); do
	EXAM_DIR="$EXAM_NAME" ./check_exam.sh "$1" "$2"
done

echo ""
echo -n "Clean: "
$(cd "$1" && git clean -qf) && echo "done" 
