# Valgrind issue

## Use Valgrind 3.22
Download https://sourceware.org/pub/valgrind/valgrind-3.22.0.tar.bz2
```
./configure --prefix=$HOME/tmp/valgrind-3.22/ --libexecdir=$HOME/tmp/valgrind-3.22
make install
```

## Run valgrind on example
```
make clean all
~/tmp/valgrind-3.22/bin/valgrind --tool=memcheck --leak-check=full --leak-resolution=high --num-callers=20 --show-leak-kinds=all --errors-for-leak-kinds=all --keep-debuginfo=yes --error-exitcode=99 ./unw_backtrace
```

# Fixed by
Fix UMRs indicated by valgrind (x86_64) #454
bregma merged 1 commit into libunwind:master from peadar:fix-umr-x86_64  on Feb 23, 2023
#### src/x86/Ginit.c

https://github.com/libunwind/libunwind/commit/b3549c98c4e4b1e0b67216aefc92ab7f80f4788e
Replaced validate_mem() for x86_64 targets with a generic unw_address_is_valid().
#### src/x86_64/Ginit.c ->  src/mi/Gaddress_validator.c

## Nov 28, 2023
https://github.com/libunwind/libunwind/commit/995590e02db1d930bd805346994b90770d1aaa4d
995590e0 Fix edge condition in unw_address_is_valid
#### src/mi/Gaddress_validator.c

