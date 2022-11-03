REM Build script for testbed
@ECHO off
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files
SET cFileNames=
FOR /R %%f in (*.c) do (
  SET cFileNames=!cFileNames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=testbed
SET compilerFlags=-g
REM -Wall -Werror
SET includeFlags=-Isrc -I../engine/src
SET linkerFlags=-L../bin -lengine.lib
SET defines=-D_DEBUG -DKIMPORT

ECHO "Building %assembly%..."
clang %cFileNames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%
