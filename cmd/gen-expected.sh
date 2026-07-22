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

export TIMEOUT=5
export SHELL_PATH="$(cd "$(dirname "$0")" && pwd -P)/.."
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
	$(cd "$REPO_PATH" && git clean -qdf) && echo "done" 
}
trap clean EXIT SIGINT SIGTERM

NORM_OPT=()
if [ -f "$STUB_PATH/env" ]; then
	source "$STUB_PATH/env"
fi
echo ""
echo "Norminette: "
norminette $NORM_OPT "$REPO_PATH" || exit

for EXAM_NAME in $(cd "$STUB_PATH" && ls -d */); do
	echo ""
	echo -n "[$EXAM_NAME] compile: "
	EXAM_DIR="$EXAM_NAME" "$SHELL_PATH/cmd/compile_exam.sh" && echo "done" || continue
	echo -n "[$EXAM_NAME] run and create expected_output: "
	EXAM_DIR="$EXAM_NAME" "$SHELL_PATH/cmd/execute_exam.sh" && echo "done" || continue
	echo -n "[$EXAM_NAME] move expected_output to stubcmd/extract-genparam-input.pl path: "
	mv "$REPO_PATH/$EXAM_NAME/output" "$STUB_PATH/$EXAM_NAME/expected_output" && echo "done"
done
