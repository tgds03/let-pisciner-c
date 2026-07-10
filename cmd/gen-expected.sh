#!/bin/bash

USAGE_STR="usage: $0 [repo_path] [stub_path]"

if [ "$#" -ne 2 ]; then
	echo -e $USAGE_STR
	exit
fi

export REPO_PATH=$(cd "$1" && pwd -P)

if [ ! -d "$REPO_PATH" ]; then
	echo "can not find dir $1"
	echo -e $USAGE_STR
	exit
fi

export SHELL_PATH="$(cd "$(dirname "$0")" && pwd -P)/../"
export LIB_PATH="$SHELL_PATH/lib"
export INCLUDE_PATH="$SHELL_PATH/include"
export STUB_PATH="$SHELL_PATH/${2,,}"

if [ ! -d "$STUB_PATH" ]; then
	echo "can not find exam $2"
	echo -e $USAGE_STR
	exit
fi

clean() {
	echo ""
	echo -n "Clean: "
	$(cd "$REPO_PATH" && git clean -qf) && echo "done" 
}
trap clean EXIT SIGINT SIGTERM

echo ""
echo "Norminette: "
norminette "$REPO_PATH" || exit

for EXAM_NAME in $(cd "$STUB_PATH" && ls -d */); do
	EXAM_DIR="$EXAM_NAME" ./cmd/compile_exam.sh
	echo -n "run exam and create expected_output: "
	if [ -f "$REPO_PATH/$EXAM_NAME/input" ]; then
		cat "$REPO_PATH/$EXAM_NAME/input" | "$REPO_PATH/$EXAM_NAME/app" \
			> "$STUB_PATH/$EXAM_NAME/expected_output" && echo "done"
	else
		echo '' | "$REPO_PATH/$EXAM_NAME/app" \
			> "$STUB_PATH/$EXAM_NAME/expected_output" && echo "done"
	fi
done
