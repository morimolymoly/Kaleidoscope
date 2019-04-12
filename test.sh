#!/bin/bash

get_tok() {
  expected="$1"
  input="$2"
  actual=`echo "$input" | make run | tail -n1`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

echo "Testing get_tok"
get_tok -2 "def fuck"
echo OK
