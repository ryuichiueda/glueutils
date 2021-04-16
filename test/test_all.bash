#!/bin/bash -evx

dir=$(dirname $0)

$dir/test_switch12.bash
$dir/test_log2.bash
$dir/test_ignerr.bash

echo OK
