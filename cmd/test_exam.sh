#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

if [ -z "$DIFF_CMD" ] ; then
	DIFF_RESULT=$( diff "$STUB_PATH/$EXAM_DIR/expected_output" "$REPO_PATH/$EXAM_DIR/output" 2>&1 )
else
	DIFF_RESULT=$( eval "$DIFF_CMD" )
fi

if [ -n "$DIFF_RESULT" ]; then
	echo "Failed"
	echo "$DIFF_RESULT"
	exit 1
fi
