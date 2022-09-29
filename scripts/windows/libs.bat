@echo off
title REPO LIBRARIES
echo Hello

mkdir ..\..\vendor
cd ..\..\vendor
set RELPATH=%cd%
echo %RELPATH%

git clone https://github.com/fmtlib/fmt
git clone https://github.com/gabime/spdlog
git clone https://github.com/fltk/fltk