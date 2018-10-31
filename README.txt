Makefile

VGAROMS                    - a lot of roms from video cards

bin-fonts:
_avga2_8x16.bin            - Commodore 386SX-25 AVGA2/CL-GD5402 8x16
_avga2_8x8.bin             -    ""                              8x8
_elsavic_8x14.bin          - elsa vic 8x14
_et4000_8x16.bin
_et4000_8x8.bin
_mirov968_8x14.bin
_ncr_gd5428_8x14.bin
_s3virgegx2_8x14.bin
_s3virgegx2_8x16.bin

bgrep                     - binary grep

bin2header.c   
bin2header binfile arrayname

extractbin.c   
extractbin binfile <addr 4hexdigits> <size byte decimal> <outfile>

headers		- generated header files

screenshots    - screenshots

viewfont.c     - sdl application to binary font files.
autodetects 8x8, 8x14, 8x15, 8x16 by font sizes 2048b/3584b/3840b/4096b
