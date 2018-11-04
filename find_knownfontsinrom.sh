#!/bin/bash

rom=$1

for font in font-bin/*.bin
do
	./findbin  $font $rom
done

