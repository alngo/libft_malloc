#!/usr/bin/env bash
expected_exit_code=6
./test.out
if [ $? -ne $expected_exit_code ]; then
  echo "Unexpected exit code: $expected_exit_code expected but was $?"
  exit 1
fi
exit 0
