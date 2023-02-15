#!/bin/bash
whoami
date
$HOME/AFL/afl-gcc add.c -o ./bin/add_afl_bin
$HOME/AFL/afl-fuzz -i ./test_seed -o ./ ./bin/add_afl_bin @@