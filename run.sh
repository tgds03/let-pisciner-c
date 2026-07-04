#!/bin/bash

USAGE_STR='run.sh [repo_path] [stub_path]'

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
	echo "Compile: "
	$(cd "$2/$EXAM_DIR/" && cc -o app -Wall -Wextra -Werror *.c && ./app)
	echo ""
done
