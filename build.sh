#!/bin/bash -e
source dos_setenv.sh
make
cp main.exe /home/samuel/Dropbox
#/home/samuel/programme/dosbox-svn/src/dosbox -exit main.exe
# /home/samuel/programme/dosbox-svn/src/dosbox main.exe
dosbox -exit main.exe
#dosbox main.exe

