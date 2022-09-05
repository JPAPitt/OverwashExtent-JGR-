@echo off
set MATLAB=H:\WindowsPrograms\MATLAB\R2021a
call "H:\WindowsPrograms\MATLAB\R2021a\sys\lcc64\lcc64\mex\lcc64opts.bat"
"H:\WindowsPrograms\MATLAB\R2021a\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"H:\WindowsPrograms\MATLAB\R2021a\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
