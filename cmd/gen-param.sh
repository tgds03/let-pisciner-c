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
export STUB_PATH="$SHELL_PATH/$1"

if [ ! -d "$STUB_PATH" ]; then
	echo "can not find exam $1"
	echo -e $USAGE_STR
	exit
fi

generate() {
	echo -n "[$EXAM_NAME] find genparam $1 script: "
	SCRIPT=$(cat "$STUB_FILE" | "$SHELL_PATH/cmd/extract-genparam.pl" $1)
	if [ -z "$SCRIPT" ]; then
		echo "can't find scripts. skip."
		return
	fi
	echo -e "$SCRIPT" | perl > "$STUB_PATH/${EXAM_NAME}$1"
	if [ $? -eq '0' ]; then
		echo "done."
	fi
}

for EXAM_NAME in $(cd "$STUB_PATH" && ls -d */); do
	echo ""
	STUB_FILE="$STUB_PATH/${EXAM_NAME}stub.c"
	echo "[$EXAM_NAME] $STUB_FILE"

	export RANDSEED=$(md5sum $STUB_FILE | awk '{print $1}')
	echo "[$EXAM_NAME] md5: $RANDSEED"
	generate "input"
	generate "args"
done

find "$STUB_PATH" \( -name 'input' -o -name 'args' \) -empty -exec rm {} \;
