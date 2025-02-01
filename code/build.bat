
REM call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

mkdir ..\build
pushd ..\build

pushd ..\code

pwd

cl ..\code\win32_handmade.cpp

