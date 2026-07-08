#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

echo -n "simple test $EXAM_DIR: "
EXIT_CODE=0
$(cd "$REPO_PATH/$EXAM_DIR/" && ./app > output 2> errlog) || EXIT_CODE=$?

if [ -z "$DIFF_CMD" ] ; then
	DIFF_RESULT=$( diff "$STUB_PATH/$EXAM_DIR/expected_output" "$REPO_PATH/$EXAM_DIR/output" 2>&1 )
else
	DIFF_RESULT=$( eval "$DIFF_CMD" )
fi

if [ -z "$DIFF_RESULT" ] && [ $EXIT_CODE -eq 0 ]; then
	echo "Success"
else
	echo "Failed (exit code: $EXIT_CODE)"

	if [ $EXIT_CODE -ne 0 ]; then
		"$SHELL_PATH/cmd/errlog_summary.py" --exit-code=$EXIT_CODE --log-file="$REPO_PATH/$EXAM_DIR/errlog"
	elif [ -n "$DIFF_RESULT" ]; then
		echo "$DIFF_RESULT"
	fi
fi
