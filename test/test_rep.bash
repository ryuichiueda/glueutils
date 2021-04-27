#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../bin/$com

output=$( $com 3 echo 3 | tr -d '\n' )

[ "$output" = "333" ]
