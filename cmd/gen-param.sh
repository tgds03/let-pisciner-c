#!/bin/bash

USAGE_STR="usage: $0 [stub_path]"

if [ "$#" -ne 1 ]; then
	echo -e $USAGE_STR
	exit
fi

export TIMEOUT=5
export SHELL_PATH="$(cd "$(dirname "$0")" && pwd -P)/.."
export LIB_PATH="$SHELL_PATH/lib"
export INCLUDE_PATH="$SHELL_PATH/include"
export STUB_PATH="$SHELL_PATH/${1,,}"

if [ ! -d "$STUB_PATH" ]; then
	echo "can not find exam $1"
	echo -e $USAGE_STR
	exit
fi

for EXAM_NAME in $(cd "$STUB_PATH" && ls -d */); do
	echo ""
	STUB_FILE="$STUB_PATH/${EXAM_NAME}stub.c"
	echo "[$EXAM_NAME] $STUB_FILE"

	echo -n "[$EXAM_NAME] find genparam script: "
	SCRIPT=$(cat "$STUB_FILE" | sed -nE "s/^\/\/ genparam>> (.*)$/\1/p")
	if [ -n "$SCRIPT" ]; then
		echo "done"
	else
		echo "can't find scripts. skip."
		continue
	fi

	echo -n "[$EXAM_NAME] find target function: "
	TARGETNAME="$(cat "$STUB_FILE" | sed -nE "s/FUNCTION\((.+)\)/\1/p" | awk -F ',' '{print $2}' | sed -E "s/\s//g")"
	if [ -n "$TARGETNAME" ]; then
		echo "done ($TARGETNAME)"
	else
		echo "can't find target function."
		TARGETNAME="undefined"
	fi

	export RANDSEED="$TARGETNAME"
	echo -e "$SCRIPT" | "$SHELL_PATH/cmd/_genparam-interpret" "$STUB_PATH/${EXAM_NAME}input" "$STUB_PATH/${EXAM_NAME}args"
	find . \( -name 'input' -o -name 'args' \) -empty -exec rm {} \;

done
