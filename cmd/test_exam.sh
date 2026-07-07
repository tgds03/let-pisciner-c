#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

if [ -z "$DIFF_CMD" ]; then
	DIFF_RESULT=$( diff "$STUB_PATH/$EXAM_DIR/expected_output" "$REPO_PATH/$EXAM_DIR/output" 2>&1 )
else
	DIFF_RESULT=$( eval "$DIFF_CMD" )
fi
if [ -z "$DIFF_RESULT" ]; then
	echo "$EXAM_DIR: Success"
else 
	echo "$EXAM_DIR: Failed"
	echo "$DIFF_RESULT"
fi
