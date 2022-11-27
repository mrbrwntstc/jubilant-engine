#!/bin/bash

# Build script for engine
set echo on

# fresh directory to store binaries
rm -rf ../bin
mkdir -p ../bin

# get a list of all the .c files
c_filenames=$(find . -type f -name "*.c")

# echo "Files: " $c_filenames

assembly="engine"
compiler_flags="-g -shared -fdeclspec -fPIC"
# -fms-extensions
# -Wall -Werror
include_flags="-Isrc -I$VULKAN_SDK/include"
#linker_flags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L$VULKAN_SDK/lib -L/usr/X11R6/lib"
linker_flags="-lvulkan -L$VULKAN_SDK/lib"
defines="-D_DEBUG -DKEXPORT"

echo "Building $assembly"
clang $c_filenames $compiler_flags -o ../bin/lib$assembly.so $defines $include_flags $linker_flags
