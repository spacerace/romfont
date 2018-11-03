#!/bin/bash

for f in ./font-bin/*8x8.bin
do
	infile=`echo $f`
	file=`echo $f|cut -d '/' -f 3`
	outfile=./font-bin/lowercharset/lower_$file
	echo "$infile > $outfile"
	split -b 1024 $infile
	mv xaa $outfile
	rm xa*
done


