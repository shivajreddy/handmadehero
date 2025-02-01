@echo off

:: Set up the Visual Studio environment (this takes like 1-2 seconds :/)
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: Create and go to build directory
mkdir ..\build
pushd ..\build

:: Compile the code
echo Compiling...
cl -Zi ..\code\win32_handmade.cpp user32.lib

:: Check if compilation succeeded before running
if exist win32_handmade.exe (
    echo Running the executable...
    win32_handmade.exe
) else (
    echo Compilation failed. Exe not found.
)
popd
