#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../$com

output=$( $com ls 'jfoaeijafjofeawo' 2>&1 || true)

[ "$output" = "" ]
