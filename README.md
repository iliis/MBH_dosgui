MBH_dosgui
==========

MakerBot Heater DOS GUI (control software running on an industry PC)


Installation (Linux)
====================

clone git repo
download & install OpenWatcom from http://openwatcom.org/index.php/Downloads

	wget http://openwatcom.mirror.fr/open-watcom-c-linux-1.9
	chmod +x open-watcom-c-linux-1.9 
	./open-watcom-c-linux-1.9
	(install eg. to ~/programme/watcom)

modify owsetenv.sh to include $WATCOM, $LIB and to point to correct $INCLUDE ('h' instead of 'lh'):

	#!/bin/sh
	echo Open Watcom Build Environment
	export WATCOM=~/programme/watcom
	export PATH=~/programme/watcom/binl:$PATH
	export INCLUDE=~/programme/watcom/h:$INCLUDE
	export EDPATH=~/programme/watcom/eddat
	export WIPFC=~/programme/watcom/wipfc
	export LIB=~/programme/watcom/lib286/dos:$LIB

load owsetenv.sh

	source owsetenv.sh

compile code

	cd $PROJECTDIR
	make

execute e.g. with dosbox

	dosbox -quit main.exe

for your convenience, there's a build.sh script which calls make and executes the result
