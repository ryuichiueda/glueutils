#!/bin/bash -e

com=../$(echo $0 | sed 's/test_//;s/\.bash//')

out1=$($com echo hoge)
out2=$($com echo hoge 2>&1)

[ "$out1" = "" ]
[ "$out2" = "hoge" ]
