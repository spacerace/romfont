#!/bin/bash

for file in new_roms/*
do
	folder=`basename $file`
	echo $file $folder
	mkdir $folder
	./gen_imgforwholerom.sh $file $folder
done
