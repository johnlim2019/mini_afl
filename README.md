Setting up the afl
```
cd $HOME
git clone https://github.com/google/AFL.git
cd AFL
make
```
Compiling code and running fuzzer on compiiled binary
```
$HOME/AFL/afl-gcc add.c -o ./bin/add_afl_bin
$HOME/AFL/afl-fuzz -m 50 -i ./test_seed -o ./results -- ./bin/add_afl_bin @@
```
`-m` refers to the memory assigned to the fuzzing process. The default is 20mb i think.

the @@ refers to the option to fuzz. 

if there are multiple options. We try to fuzz just one input option at a time. `bin -s -y @@ -f` will fuzz the third input option

the `--` separates the afl options form the program binary options.

the binary should expect to take in as an argument a filepath to file that contain inputs used in the test. This is the driver for the program we need to write
