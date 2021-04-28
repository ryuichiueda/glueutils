#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../bin/$com

output=$( $com strace seq 100 | grep -E '^[0-9]+$' | sort -u | cat - <(seq 100) | sort | uniq -d | wc -l )

[ "$output" = "100" ]
