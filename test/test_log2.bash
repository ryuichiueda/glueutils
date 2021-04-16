#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../$com

$com tmp-hoge ls 'jfoaeijafjofeawo' || true

[ "$(wc -l < tmp-hoge ; rm tmp-hoge)" = "1" ]
