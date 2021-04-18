#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../bin/$com

output=$( echo 1 | $com 10 awk '{print $1*2}')

[ "$output" = "1024" ]
