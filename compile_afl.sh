#!/bin/bash
whoami
date
$HOME/AFL/afl-gcc add.c -o ./bin/add_afl_bin
$HOME/AFL/afl-fuzz -m 100 -i ./test_seed -o ./results -- ./bin/add_afl_bin @@