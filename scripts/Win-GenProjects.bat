@echo off
pushd ..\
call vender\bin\premake\premake5.exe vs2022
popd
pause