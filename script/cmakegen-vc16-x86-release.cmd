@echo off

cmd /c call build.cmd vc16-x86 static mt release
if errorlevel 1 goto :error

goto :eof

:error
exit /b 1
