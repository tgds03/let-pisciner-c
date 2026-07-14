#!/bin/bash

if [ -f "$STUB_PATH/$EXAM_DIR/env" ]; then
	source "$STUB_PATH/$EXAM_DIR/env" 
fi

if [ -f "$REPO_PATH/$EXAM_DIR/input" ]; then
	inputcmd="cat $REPO_PATH/$EXAM_DIR/input"
else
	inputcmd="echo \"\""
fi

if [ -f "$REPO_PATH/$EXAM_DIR/args" ]; then
	executecmd="xargs -I {} -a $REPO_PATH/$EXAM_DIR/args \
					bash -c \"echo -e \\\"\nexecute ./app {}:\\\" >> output 2>> errlog; \
					./app {} >> output 2>> errlog\""
else
	executecmd="echo -e \"\nexecute ./app:\" >> output 2>> errlog; ./app >> output 2>> errlog"
fi

cat /dev/null > "$REPO_PATH/$EXAM_DIR/output"
cat /dev/null > "$REPO_PATH/$EXAM_DIR/errlog"
timeout -k 3s "$TIMEOUT"s bash -c "cd \"$REPO_PATH/$EXAM_DIR/\" && $inputcmd | $executecmd"
EXIT_CODE=$?

if [ $EXIT_CODE -ne 0 ]; then
	"$SHELL_PATH/cmd/errlog_summary.py" --exit-code=$EXIT_CODE --log-file="$REPO_PATH/$EXAM_DIR/errlog"
	exit $EXIT_CODE
fi
