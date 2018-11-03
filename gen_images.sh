#!/bin/bash

for font in ./font-bin/*.bin
do
	fontfile=`basename $font`
	fontfile=`echo $fontfile | cut -d '.' -f 1`
	out="./font-images/$fontfile.bmp"

	echo "gen bmp image from '$font': outfile=$out"
	./font2bmp $font $out
	
	outpng="./font-images/$fontfile.png"
	magick convert $out $outpng

	outzoom="./font-images/zoomed/zoomed_$fontfile.png"
	magick convert $out -scale 400% $outzoom

	rm $out

	echo ""
done

mkdir -vp ./font-images/zoomed8x8
mkdir -vp ./font-images/zoomed8x14
mkdir -vp ./font-images/zoomed8x16

cp -v ./font-images/zoomed/*8x8*.png ./font-images/zoomed8x8
cp -v ./font-images/zoomed/*8x14*.png ./font-images/zoomed8x14
cp -v ./font-images/zoomed/*8x16*.png ./font-images/zoomed8x16
