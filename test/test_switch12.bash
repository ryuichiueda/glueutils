#!/bin/bash -e

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../$com

out1=$($com echo hoge)
out2=$($com echo hoge 2>&1)

[ "$out1" = "" ]
[ "$out2" = "hoge" ]
