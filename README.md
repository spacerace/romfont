# What is this?
 
I have diassembled and/or searched VGA-ROMs for fonts and extracted these. 
Also I have written a few tools to support this job. 
All extracted fonts and screenshots are available here. 
 
 
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

# Already extracted fonts
```
LEGEND: "ok" - font already extracted
        "XX" - font not included in ROM (newer cards dont ship 8x14 usually)
        "  " - not yet done

Filename of ROM                                  8x8  8x14 8x16  Bus    Memory    Comments (BIOS manuf., year, version, ...)
------------------------------------------------+----+----+----+------+--------+--------------------------------------------------------------------------------------------------------
ATI.X550.128.040512.rom                         |    |    |    |      |        |
Asus.6200.16.050106.rom                         |    |    |    |      |        | NV44, 2004 Nvidia, Version 5.44.02.11.00 / AS05
CLGD5442.ROM                                    |    |    |    |      |        | CL-GD540x/542x VGA BIOS Version 1.20, 1992-1993 Cirrus Logic, 1987-1990 Quadtel
Commodore386SX-25_AVGA2.bin                     | ok | ok | ok | ISA  |   512k | 03/19/92, Acumos AVGA2, DeskTop VGA BIOS (340-000-11-Rev1.00), 1984-1991 Phoenix
Connect3D.9500NP.128.Infineon30.021212.rom      |    |    |    | AGP  |        | 2002/12/12, R300, Infineon Memory BIOS - P/N 113-94232-101, 1988-2002 ATI BK-ATI VER008.004.008.004
Diamond Stealth 64 Video VRAM PCI 3.00.bin      |    |    |    |      |        | 07/05/95, Stealth 64 Video VRAM Vers. 3.00, Diamond MultiMedia Systems
ELSAVIC2.ROM                                    |    | ok |    | AGP  |        | 11/23/98, ELSA VICTORY II 4.03.00, 98-98 ELSA, 90-98 Elpin Systems
Elsa.FireGLV3200.128.040910.rom                 |    |    | ok | PCIE |  128MB | 2004/09/10, RV380, 1988-2003, ATI BK-ATI VER008.015.121.000
FujitsuSiemens.QuadroFX1700.512.080123.rom      |    |    |    |      |  512MB | 
FujitsuSiemens.X300Mobility.32.050608.rom       | ok | XX | ok |      |   32MB |
G400.ROM                                        |    |    |    |      |        | Matrox
GENOA.ROM                                       |    |    |    |      |        | Tseng
Gigabyte.6200.16.050711.rom                     |    |    |    |      |        | 
Leadtek.6200.16.050128.rom                      |    |    |    |      |        |
M32.ROM                                         |    |    |    | PCI  |        | ATI
M64GX.ROM                                       |    |    |    |      |        |
MGAMIL2.ROM                                     |    | xx |    |      |        |
MIROV968.ROM                                    |    | ok |    |      |        |
MORSE KP800 VGA CL-GD520A-32PC-B.bin            |    |    |    |      |        | CL Award
NCR VLB VGA CL-GD5428-80QC-A.bin                |    | ok |    |      |        |
R128GL.ROM                                      |    |    |    |      |        |
RIVA128A.ROM                                    |    |    |    |      |        | STB
S3T64V2.ROM                                     |    |    |    | PCI  |        | S3
S3VIRGX2.ROM                                    |    | ok | ok | PCI  |        | S3
Sapphire.9600NP.256.unknown.031028.rom          |    |    |    |      |  256MB |
Sapphire.9600PRO.128.Samsung28.030829.rom       |    |    |    |      |  128MB |
Sapphire.9800XT.256.unknown.031003.rom          |    |    |    |      |  256MB |
TNT2M64.ROM                                     |    |    |    |      |        |
TSVGA 9020-12 ET4000 ISA VGA.bin                | ok |    | ok | ISA  |        |
Trident TVGA8900C (S27C256).bin                 |    |    |    | ISA  |        |
Tseng ET3000AX ISA VGA-VGA ULTRA.bin            |    |    |    | ISA  |        |
V7MERC.ROM                                      | ok | ok | ok |      |        |
VANTA.ROM                                       |    |    |    |      |        |
VANTAGE.ROM                                     |    |    |    |      |        |
VDOO3PCI.ROM                                    |    |    |    |      |        | 3dfx Elpin
WIN1KXHR.ROM                                    |    |    |    |      |        | ESLA
WONDER16.ROM                                    |    |    |    |      |        |
XGA.ROM                                         |    |    | ok |      |        | Phoenix
et4000_stb.vbi                                  |    | XX |    |      |        |
et4000w32isa.BIN                                |    |    | ok |      |        |
et4000_weirdlowerL.bin                          | ok | ok | ok | ISA  |512k/1M | Has a weird lower L in 8x14 and 8x16 charsets. Typical TSENG change to a PC font.
IBM_PC_BIOS_1981-04-24_HALF_8x8.bin             |LOW | XX | XX | ---  | ------ | IBM PC BIOS, only lower 128 characters, no "graphical" chars.
```
