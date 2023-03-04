@ECHO OFF

if not exist Build mkdir Build
pushd Build

Rem ----------------(Compiler flags)-----------------

set PROGRAM=Coisa
set COMPILER_FLAGS=-MD -Zi
set INCLUDE_FLAGS=
set LINK_FLAGS=-LIBPATH:..\External\lib raylib.lib user32.lib gdi32.lib winmm.lib shell32.lib -SUBSYSTEM:CONSOLE
Rem ----------------(o.luanda)-----------------

cl %COMPILER_FLAGS% -Fe%PROGRAM% ..\Code\main.cpp -link%LINK_FLAGS%
popd
