#!/bin/bash

diffresult="$(echo "$(diff -Z <(cat output.txt) result.txt)")"
if [ -z "$diffresult" ]
then
    :
else
    echo "Did not produce the expected result! See diff for details:"
    echo "$diffresult"
    exit 1
fi
