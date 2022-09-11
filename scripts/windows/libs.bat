@echo off
title REPO LIBRARIES
echo Hello

cd ..\..\vendor
set RELPATH=%cd%
echo %RELPATH%

git clone https://github.com/fmtlib/fmt