#!/bin/bash
whoami
date
pwd
gcc add.c -o ./bin/add_bin
cd bin 
./add_bin ../test_seed/test_seed.txt