#!/bin/bash

# Build script for testbed
set echo on

# fresh directory to store binaries
mkdir -p ../bin

# get a list of all the .c files
c_filenames=$(find . -type f -name "*.c")

# echo "Files: " $c_filenames

assembly="testbed"
compiler_flags="-g -fdeclspec -fPIC"
# -fms-extensions
# -Wall -Werror
include_flags="-Isrc -I../engine/src"
linker_flags="-L../bin/ -lengine -Wl,-rpath,."
defines="-D_DEBUG -DKIMPORT"

echo "Building $assembly"
echo clang $c_filenames $compiler_flags -o ../bin/$assembly $defines $include_flags $linker_flags
clang $c_filenames $compiler_flags -o ../bin/$assembly $defines $include_flags $linker_flags
