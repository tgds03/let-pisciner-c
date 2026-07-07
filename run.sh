#!/bin/bash
USAGE_STR="usage: $0 [repo_path] [exam_name]\n\
Don't use it before commit all you need, or file may be deleted!"

SHELL_PATH=$(cd "$(dirname "$0")" && pwd -P)
export LIB_PATH="$SHELL_PATH/lib"
export INCLUDE_PATH="$SHELL_PATH/include"
export REPO_PATH="$1"
export STUB_PATH="$SHELL_PATH/${2,,}"

clean() {
	echo ""
	echo -n "Clean: "
	$(cd "$REPO_PATH" && git clean -qf) && echo "done" 
}
trap clean EXIT SIGINT SIGTERM

if [ "$#" -ne 2 ]; then
	echo -e $USAGE_STR
	exit
fi

if [ ! -d "$REPO_PATH" ]; then
	echo "can not find $REPO_PATH"
	echo -e $USAGE_STR
	exit
fi

if [ ! -d "$STUB_PATH" ]; then
	echo "can not find exam $2"
	echo -e $USAGE_STR
	exit
fi

echo ""
echo "Norminette: "
norminette "$REPO_PATH" || exit

for EXAM_NAME in $(cd "$SUTB_PATH" && ls -d */); do
	EXAM_DIR="$EXAM_NAME" "$SHELL_PATH/cmd/compile_exam.sh" || continue
	EXAM_DIR="$EXAM_NAME" "$SHELL_PATH/cmd/test_exam.sh"
done
