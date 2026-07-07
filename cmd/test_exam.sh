#!/bin/bash

if [ -z "$DIFF_CMD" ]; then
	DIFF_RESULT=$( diff "$STUB_PATH/$EXAM_DIR/expected_output" "$REPO_PATH/$EXAM_DIR/output" )
else
	DIFF_RESULT=$( eval "$DIFF_CMD" )
fi
if [ -z "$DIFF_RESULT" ]; then
	echo "$EXAM_DIR: Success"
else 
	echo "$EXAM_DIR: Failed"
	echo "$DIFF_RESULT"
fi
