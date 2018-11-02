# What is this?
 
I have diassembled and/or searched VGA-ROMs for fonts and extracted these. 
Also I have written a few tools to support this job. 
All extracted fonts and screenshots are available here. I have written a big
table to show what is covered. Also had a look and wrote about fonts of open
source BIOSes/source available.

If you have exotic ROMs or links to other open source BIOSes please let me know.
 
 
# Already extracted fonts
```
LEGEND: "ok" - font already extracted
        "XX" - font not included in ROM (newer cards dont ship 8x14 usually)
        "  " - not yet done
        "LO" - only lower 128 characters available

Filename of ROM                                  8x8  8x14 8x16  Bus    Memory    Comments (BIOS manuf., year, version, ...)
------------------------------------------------+----+----+----+------+--------+--------------------------------------------------------------------------------------------------------
ATI.X550.128.040512.rom                         |    |    |    |      |        |
Asus.6200.16.050106.rom                         |    |    |    |      |        | NV44, 2004 Nvidia, Version 5.44.02.11.00 / AS05
CLGD5442.ROM                                    |    | ok |    |      |        | CL-GD540x/542x VGA BIOS Version 1.20, 1992-1993 Cirrus Logic, 1987-1990 Quadtel
Commodore386SX-25_AVGA2.bin                     | ok | ok | ok | ISA  |   512k | 03/19/92, Acumos AVGA2, DeskTop VGA BIOS (340-000-11-Rev1.00), 1984-1991 Phoenix
Connect3D.9500NP.128.Infineon30.021212.rom      |    |    |    | AGP  |        | 2002/12/12, R300, Infineon Memory BIOS - P/N 113-94232-101, 1988-2002 ATI BK-ATI VER008.004.008.004
Diamond Stealth 64 Video VRAM PCI 3.00.bin      |    | ok |    | PCI  |        | 07/05/95, Stealth 64 Video VRAM Vers. 3.00, Diamond MultiMedia Systems
ELSAVIC2.ROM                                    |    | ok |    | AGP  |        | 11/23/98, ELSA VICTORY II 4.03.00, 98-98 ELSA, 90-98 Elpin Systems
Elsa.FireGLV3200.128.040910.rom                 |    |    | ok | PCIE |  128MB | 2004/09/10, RV380, 1988-2003, ATI BK-ATI VER008.015.121.000
FujitsuSiemens.QuadroFX1700.512.080123.rom      |    |    |    |      |  512MB | 
FujitsuSiemens.X300Mobility.32.050608.rom       | ok | XX | ok |      |   32MB |
G400.ROM                                        |    |    |    |      |        | Matrox
GENOA.ROM                                       |    | ok |    |      |        | Tseng
Gigabyte.6200.16.050711.rom                     |    |    |    |      |        | 
Leadtek.6200.16.050128.rom                      |    |    |    |      |        |
M32.ROM                                         |    | ok |    | PCI  |        | ATI
M64GX.ROM                                       |    | ok |    |      |        |
MGAMIL2.ROM                                     |    | xx |    |      |        |
MIROV968.ROM                                    |    | ok |    |      |        |
MORSE KP800 VGA CL-GD520A-32PC-B.bin            |    | ok |    |      |        | CL Award
NCR VLB VGA CL-GD5428-80QC-A.bin                |    | ok |    |      |        |
R128GL.ROM                                      |    |    |    |      |        |
RIVA128A.ROM                                    |    |    |    |      |        | STB
S3T64V2.ROM                                     |    | ok |    | PCI  |        | S3
S3VIRGX2.ROM                                    |    | ok | ok | PCI  |        | S3
Sapphire.9600NP.256.unknown.031028.rom          |    |    |    |      |  256MB |
Sapphire.9600PRO.128.Samsung28.030829.rom       |    |    |    |      |  128MB |
Sapphire.9800XT.256.unknown.031003.rom          |    |    |    |      |  256MB |
TNT2M64.ROM                                     |    | ok |    |      |        |
TSVGA 9020-12 ET4000 ISA VGA.bin                | ok | ok | ok | ISA  |        |
Trident TVGA8900C (S27C256).bin                 |    |    |    | ISA  |        |
Tseng ET3000AX ISA VGA-VGA ULTRA.bin            |    | ok |    | ISA  |        |
V7MERC.ROM                                      | ok | ok | ok |      |        |
VANTA.ROM                                       |    | ok |    |      |        |
VANTAGE.ROM                                     |    | ok |    |      |        |
VDOO3PCI.ROM                                    |    | ok |    |      |        | 3dfx Elpin
WIN1KXHR.ROM                                    |    | ok |    |      |        | ESLA
WONDER16.ROM                                    |    | ok |    |      |        |
XGA.ROM                                         |    | ok | ok |      |        | Phoenix
et4000_stb.vbi                                  |    | XX |    |      |        |
et4000w32isa.BIN                                |    | ok | ok |      |        |
et4000_weirdlowerL.bin                          | ok | ok | ok | ISA  |512k/1M | Has a weird lower L in 8x14 and 8x16 charsets. Typical TSENG change to a PC font.
IBM_PC_BIOS_1981-04-24_HALF_8x8.bin             | LO | XX | XX | ---  | ------ | IBM PC BIOS, only lower 128 characters, no "graphical" chars.
                                                |    |    |    |      |        |
seabios                                         | OK | OK | OK | ---  | ------ |
bochs                                           | LO | XX | XX | ---  | ------ |
                                                |    |    |    |      |        |
                                                |    |    |    |      |        |
                                                |    |    |    |      |        |
                                                |    |    |    |      |        |                                                                                                                                                
```

# OTHER SOURCES

The folder 'other_sources' contains subfolders, which each holds a set of files for a ROM-font.
They were not extracted from ROMs, they are already available as source. These
sources were adapted and simple bin-generators were added to create the binary
font files. 
These are available:
```
ibm_pc                - original IBM PC, V1/V2/V3
ibm_xt                - IBM XT, V1/V2/V3
ibm_xt286             - IBM XT 286, only one BIOS available
ibm_at                - IBM AT, V1/V2/V3
seabios               - qemu seabios, 8x8, 8x14, 8x16
3dfx_leadked_bios     - original source code, 8x8, 8x14, 8x16, 9x14, 9x16
bochs_bios            - bochs bios, 8x8, only lower half of charset implemented
```
Not all are yet converted to C (most of them in ASM) and bins are generated.
The original sources are provided already. 
 
Observations:
* IBM AT V1-V3 share the same font. Only lower half of charset in 8x8 available.
* The seabios 8x8 and 8x14 are also used on real HW cards from different vendors.
* The 3dfx 8x8 font is the same as the seabios 8x8 font.

# comparison
Have a look at MD5SUMs file, it is sorted by sum. This means, you will se which
cards share same font.
If you want to compare you may use a image viewer and view the zoomed images
of the desired fonts.

*TODO* split 8x8 charsets into lower and upper half and compare these also, as
early PCs usually shipped lower 128 characters. This means vendors may have
taken IBM's lower half and added upper half from other sources.

# viewfont tool
The viewfont tool displays a charset in it's original size, zoomed and displays
a single char zoomed. User can navigate through charset with arrow key. 
Colors can be changed.
Font size is determined by size of bin-file given to viewfont.
2048 = 8x8
3584 = 8x14
4096 = 8x16

# other tools
https://github.com/tmbinc/bgrep


# Build
Most likely you dont need to build all this stuff, if you only want to look at 
the screenshots or get the extracted fonts. 
 
If you want to build: 
You need bash, libsdl-dev, libsdl-gfx-dev, imagemagick and gcc to build and run.
Either click on download as zip on github page or clone via commandline.
Once you have the source, do this in source folder: 
```
$ make
$ ./gen_headers.sh
$ ./gen_images.sh
```

