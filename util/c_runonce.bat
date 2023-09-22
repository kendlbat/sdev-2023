@echo off
echo Running %1
echo ---
gcc %1 -o temp.exe && temp.exe && del temp.exe
echo ---
echo Finished running %1
