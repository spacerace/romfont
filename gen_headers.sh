#!/bin/bash



# generate 8x8 fonts
for font in ./font-bin/*8x8*
do
	header=`basename $font`
	header=`echo $header | cut -d '.' -f 1`
	out="./font-headers/$header.h"
	vn=$header

	echo "gen header from '$font':"
	echo "  outfile=$out, varname=$vn"
	./bin2header $font $vn 8 > $out

	echo ""
done

# generate 8x14 fonts
for font in ./font-bin/*8x14*
do
	header=`basename $font`
	header=`echo $header | cut -d '.' -f 1`
	out="./font-headers/$header.h"
	vn=$header

	echo "gen header from '$font':"
	echo "  outfile=$out, varname=$vn"
	./bin2header $font $vn 14 > $out
	echo ""
done


# generate 8x16 fonts
for font in ./font-bin/*8x16*
do
	header=`basename $font`
	header=`echo $header | cut -d '.' -f 1`
	out="./font-headers/$header.h"
	vn=$header

	echo "gen header from '$font':"
	echo "  outfile=$out, varname=$vn"
	./bin2header $font $vn 16 > $out
	echo ""
done


