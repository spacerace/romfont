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
	magick convert $out -scale 400% $outzoom

	rm $out

	echo ""
done

mkdir -p ./font-images/zoomed8x8
mkdir -p ./font-images/zoomed8x14
mkdir -p ./font-images/zoomed8x16

cp -v ./font-images/zoomed/*8x8*.png ./font-images/zoomed8x8
cp -v ./font-images/zoomed/*8x14*.png ./font-images/zoomed8x14
cp -v ./font-images/zoomed/*8x16*.png ./font-images/zoomed8x16
