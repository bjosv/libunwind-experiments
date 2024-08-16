#!/bin/bash
set -x

# Build with debug if UNW_DEBUG_LEVEL is set (= 0..16)
if [[ -n $UNW_DEBUG_LEVEL ]] ; then
   DEBUG_CONF="--enable-debug"
fi

# Build and install current commit
rm -rf ~/tmp/libunwind
autoreconf -i

./configure --disable-tests CFLAGS="-g -O0" CXXFLAGS="-g -O0" --prefix=$HOME/tmp/libunwind $DEBUG_CONF

# exit code of 125 asks "git bisect" to "skip" the current commit
make install || exit 125

# Clean-up repo for next iteration
git clean -fdx
git co .

# Build example (which uses $HOME/tmp/libunwind)
cd $HOME/git/libunwind-experiments/examples/
make clean all
cd -

# Run valgrind on binary and exit with exitcode 0 (ok) or 99 (issue found)
valgrind --tool=memcheck --leak-check=full --leak-resolution=high --num-callers=20 --show-leak-kinds=all --errors-for-leak-kinds=all --keep-debuginfo=yes --error-exitcode=99 --track-origins=yes $HOME/git/libunwind-experiments/examples/unw_backtrace

