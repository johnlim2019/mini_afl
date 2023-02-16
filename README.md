Setting up the afl
```
cd $HOME
git clone https://github.com/google/AFL.git
cd AFL
make
```
Compiling code and running fuzzer on compiiled binary
```
$HOME/AFL/afl-gcc path/to/your/source.c -o ./path/to/compile/binary
$HOME/AFL/afl-fuzz -i path/to/input/seed/ -o /path/to/compiled/binary @@
```
the @@ refers to the test_seed files in the test_seed folder

the binary should expect to take in as an argument a filepath to file that contain inputs used in the test.