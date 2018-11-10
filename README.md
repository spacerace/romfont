# What is this?
 
I have diassembled and/or searched BIOS and VGA-ROMs for fonts and extracted these. 
Also I have written a few tools to support this job. 
All extracted fonts and screenshots are available here. I have written a big
table to show what is covered. Also had a look and wrote about fonts of open
source BIOSes/source available.

If you have exotic ROMs or links to other open source BIOSes please let me know.
Testing a ROM for known fonts and add it to this list only takes a few minutes and
if there is one with a yet unknown font, I am happy to extract and document it :)  
I am really intersted in ROMs of old laptops with weird LCD-fonts and embedded
devices (like POS systems, cash registers, money machines and other stuff). 
Also if you have localized graphic cards, that bring a local charset (ex. greek),
I am happy to extract their' fonts. 
 
I already extracted more than 110 ROM-fonts. Most likely I am not updating this
counter for every font, so check the font-bin and font-images folder, if there
is something new relevant to you. 

# The tool
I have written a tool to browse a ROM image and search for 8x8, 8x14, 8x16 charsets
and export.
It can be found here on github in another repo, called "romfont-extractor". 
 
  ls
  
# Already extracted fonts
```
LEGEND: "ok" - font already extracted
        "XX" - font not included in ROM (newer cards dont ship 8x14 usually)
        "  " - not yet done
        "??" - something strange
        "LO" - only lower 128 characters available

Filename of ROM                                  8x8  8x14 8x16  Bus    Memory   Date         Comments (BIOS manuf., year, version, ...)
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
ATI.X550.128.040512.rom                         | ok | xx | ok |      |        |            |
Asus.6200.16.050106.rom                         | ?? | ?? | ?? |      |        |            | NV44, 2004 Nvidia, Version 5.44.02.11.00 / AS05
CLGD5442.ROM                                    | ok | ok | ok |      |        |            | CL-GD540x/542x VGA BIOS Version 1.20, 1992-1993 Cirrus Logic, 1987-1990 Quadtel
avga1-a11.bin                                   | ?? | ?? | ?? |      |        |            |
AVGA2.ROM                                       | ok | ok | ok |      |        |            |
Commodore386SX-25_AVGA2.bin                     | ok | ok | ok | ISA  |   512k | 03/19/92   | Acumos AVGA2, DeskTop VGA BIOS (340-000-11-Rev1.00), 1984-1991 Phoenix
Connect3D.9500NP.128.Infineon30.021212.rom      | ok | xx | ok | AGP  |        | 2002/12/12 | R300, Infineon Memory BIOS - P/N 113-94232-101, 1988-2002 ATI BK-ATI VER008.004.008.004
Diamond Stealth 64 Video VRAM PCI 3.00.bin      | ok | ok | ok | PCI  |        | 07/05/95   | Stealth 64 Video VRAM Vers. 3.00, Diamond MultiMedia Systems
ELSAVIC2.ROM                                    | ok | ok | ok | AGP  |        | 11/23/98   | ELSA VICTORY II 4.03.00, 98-98 ELSA, 90-98 Elpin Systems
Elsa.FireGLV3200.128.040910.rom                 | ok | xx | ok | PCIE |  128MB | 2004/09/10 | RV380, 1988-2003, ATI BK-ATI VER008.015.121.000
FujitsuSiemens.QuadroFX1700.512.080123.rom      | ?? | ?? | ?? |      |  512MB |            | ??? compressed font ??? cant find font on first look
FujitsuSiemens.X300Mobility.32.050608.rom       | ok | xx | ok |      |   32MB |            |
G400.ROM                                        | ok | xx | ok |      |        |            | Matrox
GENOA.ROM                                       | ok | ok | ok |      |        |            | Tseng
Gigabyte.6200.16.050711.rom                     | ?? | ?? | ?? |      |        |            | ??? compressed font ??? cant find font on first look
Leadtek.6200.16.050128.rom                      | ?? | ?? | ?? |      |        |            | ??? compressed font ??? cant find font on first look
M32.ROM                                         | ok | ok | ok | PCI  |        |            | ATI
M64GX.ROM                                       | ok | ok | ok |      |        |            |
MGAMIL2.ROM                                     | ok | xx | ok |      |        |            |
MIROV968.ROM                                    | ok | ok | ok |      |        |            | Same like V7MERC
MORSE KP800 VGA CL-GD520A-32PC-B.bin            | ok | ok | ok |      |        |            | CL Award
NCR VLB VGA CL-GD5428-80QC-A.bin                | ok | ok | ok |      |        |            |
R128GL.ROM                                      | ok | xx | ok |      |        |            |
RIVA128A.ROM                                    | ok | xx | ok |      |        |            | STB
S3T64V2.ROM                                     | ok | ok | ok | PCI  |        |            | S3
S3VIRGX2.ROM                                    | ok | ok | ok | PCI  |        |            | S3
Sapphire.9600NP.256.unknown.031028.rom          | ok | xx | ok |      |  256MB |            |
Sapphire.9600PRO.128.Samsung28.030829.rom       | ok | xx | ok |      |  128MB |            |
TNT2M64.ROM                                     | ok | ok | ok |      |        |            |
TSVGA 9020-12 ET4000 ISA VGA.bin                | ok | ok | ok | ISA  |        |            |
Tseng ET3000AX ISA VGA-VGA ULTRA.bin            | ok | ok | ok | ISA  |        |            |
V7MERC.ROM                                      | ok | ok | ok |      |        |            |
V7_Vega                                         | ok | ok | ok |      |        |            | uses 3dfx font set, different fonts than V7MERC
video_seven_vega_vga_62L1989V5_435-0016-47.bin  | ok | ok | ok |      |        |            |
VANTA.ROM                                       | ok | ok | ?? |      |        |            | 8x16 not complete in ROM
VANTAGE.ROM                                     | xx | ok | ok |      |        |            | has no 8x8 font
VDOO3PCI.ROM                                    | ok | ok | ok |      |        |            | 3dfx Elpin
WIN1KXHR.ROM                                    | ok | ok | ok |      |        |            | ESLA
WONDER16.ROM                                    | ok | ok | ok |      |        |            |
XGA.ROM                                         | ok | ok | ok |      |        |            | Phoenix
et4000_stb.vbi                                  | ok | xx | ok |      |        |            |
et4000w32isa.BIN                                | ok | ok | ok |      |        |            |
et4000_weirdlowerL.bin                          | ok | ok | ok | ISA  |512k/1M |            | Has a weird lower L in 8x14 and 8x16 charsets. Typical TSENG change to a PC font.
OakTechnolgy-unknown-1.bin                      | ok | ok | ok |      |        |            |
OakTechnolgyVGA-KO77.bin                        | ok | ok | ok |      |        |            |
QuadtelS3_86C801_86C805EnhancedVGABIOS2.13.01   | ok | ok | ok |      |        |            |
QuadtelVGABIOSVersion1.21.00.bin                | ok | ok | ok |      |        |            |
SVGA141.ROM                                     | ok | ok | ok |      |        |            |
s3_764.bin                                      | ok | ok | ok |      |        |            |
TridentTVGA8900C_S27C256.bin                    | ?? | ?? | ?? |      |        |            |
tgui9400cxi.vbi                                 | ok | ok | ok |      |        |            |
tvga-c4.3.rom                                   | ok | ok | ok |      |        |            |
tvga-d3.0.rom                                   | ok | ok | ok |      |        |            |
tvga9000i-d4.01e                                | ?? | ?? | ?? |      |        |            |
tvga9000i-v2.vbi                                | ok | ok | ok |      |        |            |
tvga9000a_d211.bin                              | ok | ok | ok |      |        |            |
tvga9000a_d301.bin                              | ok | ok | ok |      |        |            |
tvga8800cs                                      | ok | ok | ok |      |        |            |
tvga8800cs_2                                    | ok | ok | ok |      |        |            |
BLADEXP.vbi                                     | ok | ok | ok |      |        |            |
BLADE3D_AGP.vbi                                 | ok | ok | ok |      |        |            |
BLADE3D_AGP_HIS.vbi                             | ok | ok | ok |      |        |            |
BLADE3D_PCI.vbi                                 | ok | ok | ok |      |        |            |
vgaedge.bin                                     | ok | ok | ok |      |        |            |
TsengLabsVGA-4000BIOSV1.1.bin                   | ok | ok | ok |      |        |            |
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
ATIEgaWonder800p.bin                            | ok | ok | ok |      |        |            |
ami-ega.rom                                     | ok | ok | xx |      |        |            | VERY SPECIAL FONTS, 2 different 8x8 (1 is mirrored) and one 8x14
genoa-ega-2.41.rom                              | ok | ok | xx |      |        |            |
ibm-ega.rom                                     | ok | ok | xx |      |        |            |
NSILogic-SmartEGAPlus-04-086-01Rev1.45-U21.bin  | ok | ok | xx |      |        |            |
wd-pega.rom                                     | ok | ok | xx |      |        |            |
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
IBM VGA                                         | ok | ok | ok |      |        |            | has a full 8x8 charset in 8x8, 8x14 and 8x16
IBM_PC_BIOS_1981-04-24_HALF_8x8.bin             | LO | XX | XX | ---  | ------ |            | IBM PC BIOS, only lower 128 characters, no "graphical" chars.
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
=> IN THIS SECTION: LOCALIZED VIDEO ROMS (greek, ...)
CGA_PRAVETZ.ROM                                 | ok | xx | xx |      |        |            | 4 different kyrillic fonts
acer500-II_cga_rom.bin                          | ok | xx | ?? |      |        |            | 2 different greek 8x8, somewhat strange 8x16 TBD
ati_small_wonder_rev1_GR-ROM.bin                | ok | xx | ?? |      |        |            | 4 different greek 8x8
clone2_cga_rom.bin                              | xx | ?? | ?? |      |        |            |
clone_cga_rom.bin                               | xx | ?? | ?? |      |        |            |
hyundai_mono-graphics-board_e40080004           | xx | ?? | ?? |      |        |            |
ibm5155_cga_rom_memotek_greek                   | ok | xx | xx |      |        |            | 10 different greek fonts?
tvga9000a_japan.vbi                             | ok | ok | ok |      |        |            |
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
mda.rom                                         | ?? | ?? | ?? |      |        |            | 8k ROM only font data, what is this? not extracted yet, some problems
50146chareuro.rom                               | ok | xx | ok |      |        |            | Tandy 1000, 8x8 and 8x14 in both a 8x16 array with padding zero bytes
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
=> IN THIS SECTION: SYSTEM BIOS
ali1429g.amw (AMI WINBIOS)                      | LO | xx | xx |      |        |            |
amic206.bin                                     | xx | xx | xx |      |        |            | NO FONT at all
ami386.bin                                      | LO | xx | xx |      |        |            |
amxtv132.rom                                    | LO | xx | xx |      |        |            |
award-2.05.rom                                  | LO | xx | xx |      |        |            |
DTK.PII-151B-BIOS.version.1.06B.bin             | xx | xx | xx |      |        |            | NO FONT at all
dtk_erso_2.42_2764.bin                          | LO | xx | xx |      |        |            |
genxt.bin                                       | LO | xx | xx |      |        |            |
JukoD16X-BIOSversion1.2.bin                     | xx | xx | xx |      |        |            | NO FONT at all
LongshineLCS-6821N-BIOSversion1.04.bin          | xx | xx | xx |      |        |            | NO FONT at all
olivetti-m24-1.21.rom                           | LO | xx | xx |      |        |            |
opt495sx.ami                                    | LO | xx | xx |      |        |            |
phoenix-2.51.rom                                | LO | xx | xx |      |        |            |
ToshibaT1000-BIOSROM-V4.10.bin                  | ?? | xx | xx |      |        |            | lo and hi in different places
toshibaT5200cbiosv3.bin                         | ok | xx | ok |      |        |            | VERY SPECIAL contains each 2 different fonts, 8x8 and 8x16
VTech-LaserTurboXT-BIOS-V1.11-27C64D.bin        | LO | xx | xx |      |        |            | VERY SPECIAL
VTech-LaserXT3-BIOS-V1.26-27C64.bin             | LO | xx | xx |      |        |            | VERY SPECIAL
wang3050_bios_rom                               | ok | ok | ok |      |        |            |
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
ibmjap.rom                                      | ok | ok | ok |      |        |            | Japanese PS/2 BIOS
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
=> IN THIS SECTION: FONTS THAT ARE AVAILABLE IN SOURCE
seabios                                         | ok | ok | ok | ---  | ------ |            | from official source
bochs                                           | LO | XX | XX | ---  | ------ |            | from official source
3dfx                                            | ok | ok | ok |      |        |            | from leaked source
IBM PC BIOS V1                                  | LO | XX | XX |      |        |   1981     | from IBM's source
IBM PC BIOS V2,V3                               | LO | XX | XX |      |        |   1981     | from IBM's source
IBM AT BIOS V1,V2,V3                            | LO | XX | XX |      |        |   1981     | from IBM's source
IBM XT BIOS V1,V2,V3                            | LO | XX | XX |      |        |   1981     | from IBM's source
IBM XT286 BIOS V1                               | LO | XX | XX |      |        |   1981     | from IBM's source
------------------------------------------------+----+----+----+------+--------+------------+------------------------------------------------------------------------------------------------
```

# OTHER SOURCES

The folder 'other_sources' contains subfolders, which each holds a set of files for a ROM-font.
They were not extracted from ROMs, they are already available as source. These
sources were adapted and simple bin-generators were added to create the binary
font files. 
These are available:
```
ibm_pc             -  original IBM PC, V1/V2/V3
ibm_xt             -  IBM XT, V1/V2/V3
ibm_xt286          -  IBM XT 286, only one BIOS available
ibm_at             -  IBM AT, V1/V2/V3
seabios            -  qemu seabios, 8x8, 8x14, 8x16
3dfx_leadked_bios  -  original source code, 8x8, 8x14, 8x16, 9x14, 9x16
bochs_bios         -  bochs bios, 8x8, only lower half of charset implemented
```
Not all are yet converted to C (most of them in ASM) and bins are generated.
The original sources are provided already. 
 
# comparing fonts / observations:
* IBM has used a font for the very first PC BIOS, that has changed in second
  version of BIOS. After this release the font remained the same on these machines:
  - IBM PC v2, v3
  - IBM XT v1, v2, v3
  - IBM XT v1
  - IBM AT v1, v2, v3 
  The only change from first to second version is 1 single bit, that makes a huge
  difference when looking at it (ASCII 0x04, bottom line 0x00 changes to 0x08).
  This font only has the lower 128 characters.
* IBM uses exactly same 8x8,8x14,8x16 on VGA and XGA. (full 256 item charset)
* qemu seabios 8x8 and 8x14 are exact matches to IBM's VGA and XGA fonts.
  These files are in fntcol16.zip from simtel. VGA-ROM.F08 and VGA-ROM.F14.
  qemu source comment claims this is public domain. I doubt IBM would release
  a font to public domain. Does this mean, qemu relied on claims by package
  creator and now they use a illegal copy?
* bochs bios 8x8 only brings lower 128 chars that are exactly matching IBM's second font.
  Same as with seabios 8x8 font (licensing).
* 3dfx uses 8x8+8x14 IBM font, but looks like they use NVidia 8x16 font.
* The Voodoo3 8x8,8x14,8x16 match exactly the leaked ones from 3dfx.
* The AVGA2 has totally unique fonts - TODO - bit by bit compare - what are the differences?

Have a look at `MD5SUMs` file, it is sorted by sum. This means, you will se which
cards share same font.
If you want to compare you may use a image viewer and view the zoomed images
of the desired fonts.

The folder `lowercharset` holds the lower 128 characters of all 8x8 fonts to
see, which one uses the original IBM PC's or the second version of this font.

