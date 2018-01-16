#!/bin/sh

echo "Running unit tests:"

for i in tests/*_tests
do
    if test -f $i
    then
        if ./$i 2>> tests/tests.log
        then
            echo $i PASS
        else
            echo "ERROR in test $i:"
            echo "-----"
            tail tests/tests.log
            exit 1
        fi
    fi
done

echo ""
