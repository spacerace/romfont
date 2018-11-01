#!/bin/bash


for font in ./font-bin/*.bin
do
	header=`basename $font`
	header=`echo $header | cut -d '.' -f 1`
	out="./font-images/$header.bmp"

	echo "gen header from '$font': outfile=$out"
	./font2bmp $font $out
	
	outpng="./font-images/$header.png"
	magick convert $out $outpng

	outzoom="./font-images/zoomed/zoomed_$header.png"
	magick convert $out -resize 400% $outzoom

	rm $out

	echo ""
done

