#!/bin/bash -evx

dir=$(dirname $0)

$dir/test_flip12.bash
$dir/test_log2.bash
$dir/test_ignerr.bash
$dir/test_ign1.bash
$dir/test_ign2.bash
$dir/test_ign12.bash
$dir/test_juz.bash
$dir/test_rep.bash
$dir/test_con12.bash

echo OK
