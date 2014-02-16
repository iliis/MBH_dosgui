#!/bin/bash -e
source dos_setenv.sh
make
dosbox -exit main.exe
