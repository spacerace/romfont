#!/bin/bash

romfolder=$1

echo "searching V1"
for r1 in $romfolder/*
do
	./findbin font-bin/IBM_PC_BIOS_1981-04-24_HALF_8x8.bin $r1
done

echo "searching V2"
for r2 in $romfolder/*
do
	./findbin font-bin/IBM_PC_V2_8x8.bin $r2
done
#./findbin  $font $rom
#font-bin/IBM_PC_BIOS_1981-04-24_HALF_8x8.bin
#font-bin/IBM_PC_V2_8x8.bin
