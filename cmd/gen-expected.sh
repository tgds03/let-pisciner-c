#!/bin/bash

USAGE_STR="usage: $0 [repo_path] [stub_path]"

echo $(pwd)
SHELL_PATH=$(cd "$(dirname "$0")" && pwd -P)
export LIB_PATH="$SHELL_PATH/../lib"
export INCLUDE_PATH="$SHELL_PATH/../include"
export REPO_PATH="$1"
export STUB_PATH="$2"

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
	echo "can not find $STUB_PATH"
	echo -e $USAGE_STR
	exit
fi

echo ""
echo "Norminette: "
norminette "$REPO_PATH" || exit

for EXAM_NAME in $(cd "$STUB_PATH" && ls -d */); do
	EXAM_DIR="$EXAM_NAME" ./cmd/compile_exam.sh
	echo -n "run exam and create expected_output: "
	"$REPO_PATH/$EXAM_NAME/app" > "$STUB_PATH/$EXAM_NAME/expected_output" && echo "done"
done
