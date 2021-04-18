#!/bin/bash -exv

com=$(basename $0 | sed 's/test_//;s/\.bash//')
com=$(dirname $0)/../bin/$com

$com ls 'jfoaeijafjofeawo' #not failed due to ignerr
