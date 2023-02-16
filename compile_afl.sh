#!/bin/bash
whoami
date
# $HOME/AFL/afl-gcc add.c -o ./bin/add_afl_bin
# $HOME/AFL/afl-fuzz -m 1000 -i ./test_seed -o ./results -- ./bin/add_afl_bin @@
$HOME/AFL/afl-gcc test_cute.c -o ./bin/test_cute_bin
$HOME/AFL/afl-fuzz -i ./test_seed/test_cute -o ./results_test_cute -- ./bin/test_cute_bin @@
