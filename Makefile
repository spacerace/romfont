all:
	gcc -O2 -Wall bin2header.c -o bin2header
	gcc -Wall -O2 extractbin.c -o extractbin
	gcc -lSDL -lSDL_gfx -O2 -Wall viewfont.c -o viewfont
	size bin2header viewfont extractbin
	
run:
	#./viewfont _et4000_8x8.bin
	./viewfont _avga2_8x16.bin

clean:
	rm -rf bin2header extractbin viewfont
