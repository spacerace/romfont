all:
	gcc -O2 -Wall tools/findbin.c -o findbin
	gcc -O2 -Wall tools/bin2header.c -o bin2header
	gcc -O2 -Wall tools/extractbin.c -o extractbin
	gcc -lSDL -lSDL_gfx -O2 -Wall tools/viewfont.c -o viewfont
	gcc -lSDL -lSDL_gfx -O2 -Wall tools/font2bmp.c -o font2bmp
	size bin2header viewfont extractbin font2bmp findbin
run:
	#./viewfont _et4000_8x8.bin
	#./viewfont _avga2_8x16.bin
clean:
	rm -rf bin2header extractbin viewfont font2bmp findbin
	
mrproper:
	make clean
	rm -rf font-headers/* font-images/*
	mkdir font-images/zoomed
