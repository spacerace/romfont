#!/bin/bash

file=$1
romsize=`ls -1l "$file"|cut -d ' ' -f 5`
chunksize=4096
chunks=$(($romsize/$chunksize))
echo "usage ... <infile> <tmpfolder>"
echo "size=$romsize chunks=$(($chunks)) chunksize=$chunksize"

folder=$2
rm -fv $folder
mkdir $folder
echo "working in folder $folder"

for i in `seq 0 $(($chunks-1))`
do
	start=$(($i*$chunksize))
	start=`printf "%04x" $start`
	./extractbin $file $start $chunksize $folder/$start.bin
done

for font in $folder/*.bin
do
	header=`basename $font`
	header=`echo $header | cut -d '.' -f 1`
	out="$folder/$header.bmp"

	echo "gen header from '$font': outfile=$out"
	./font2bmp $font $out

	outpng="$folder/$header.png"
	magick convert $out $outpng

	rm $out

	echo ""
done

