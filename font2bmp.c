#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <string.h>
#include <SDL/SDL_rotozoom.h>

#define FTYPE8x8	1
#define FTYPE8x16	2
#define FTYPE8x14	3
#define FTYPE8x15	4

int putc_(SDL_Surface *dst, int xoff, int yoff, int fy, int c, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void draw_zoomed(SDL_Surface *pic, int x, int y, double zoom);

/* SDL Stuff */
SDL_Surface *screen, *charset, *charset_zoomed, *ch;
uint32_t rmask, gmask, bmask, amask;

/* font buffer */
uint8_t buffer[4096];

int main(int argc, char **argv) {
    int x, y, c, infile_size, i, fy = 0;
    char filename[128], temp[128];

   	struct stat stbuf;

   	FILE *f, *f2;

	if(argc < 2) {
		printf("usage: %s <infile> <outfile>\n", argv[0]);
	}

    strcpy(filename, argv[1]);
	f = fopen(filename, "r");
	if(f == NULL) {
		printf("cant open input file\n");
		exit(-1);
	}
	
    strcpy(temp, argv[2]);
	f2 = fopen(temp, "w");
	if(f == NULL) {
		printf("cant open output file\n");
		exit(-1);
	}
	fclose(f2);
	
	/* get filesize */
	stat(filename, &stbuf);
	infile_size = stbuf.st_size;

    printf("displaying '%s' (%dbytes)\n", filename, infile_size);
	
	switch(infile_size) {
		case 2048:
			printf("8x8 font (2048b)\n");
			fy = 8;
			break;
		case 3584:
			printf("8x14 font (3584b)\n");
			fy = 14;
			break;
		case 3840:
			printf("8x15 font (3840b)\n");
			fy = 15;
			break;	
		case 4096:
			printf("8x16 font (4096b)\n");
			fy = 16;
			break;
		default:
			printf("not a font\n");
			exit(-2);
			break;
	}

	/* load font */
	for(i = 0; i < infile_size; i++) {
		buffer[i] = getc(f);
	}
	fclose(f);

	/* SDL Stuff */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif
	SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(700, 730, 16, SDL_HWSURFACE);

	/* create surfaces that fit 8x16, 8x8 uses only half */
	/* create a empty surface that fits a 8x16 font charset with 1px between chars */
    charset = SDL_CreateRGBSurface(SDL_SWSURFACE, 72*2, 144*2, 32, rmask, gmask, bmask, amask);
    
	int fx = 8;
			
	/* draw the charset (unzoomed) */
	for(y = 0; y < 16; y++) {
		for(x = 0; x < 16; x++) {
			c = (y*16)+x;
			putc_(charset, x*(fx+1), y*(fy+1), fy, c, 255, 255, 255, 255);
		}
	}
    
    SDL_BlitSurface(charset, NULL, screen, NULL);
        
    printf("writing to '%s'...\r\n", temp);
    if(SDL_SaveBMP(charset, temp) < 0) {
		printf("error saving bmp.\n");
	}
    
    
    return 0;
}

/* draw a char to surface dst */
int putc_(SDL_Surface *dst, int xoff, int yoff, int fy, int c, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	int x, y, line_data;
	int off = c*fy;
	int posx, posy;
	
	for(y = 0; y < fy; y++) {
		line_data = buffer[off+y];
		for(x = 0; x < 8; x++) {
			if((line_data>>x) & 0x01) {
				posx = xoff+8-x;
				posy = yoff+y;
				pixelRGBA(dst, posx, posy, r, g, b, a);
			}
		}
	}
	return 0;	
}

void draw_zoomed(SDL_Surface *pic, int x, int y, double zoom) {
	double angle = 0;
	SDL_Surface *tmp;
	SDL_Rect tmpRect;
	int w, h;
	SDL_Rect r;
	r = pic->clip_rect;
	r.x = x;
	r.y = y;
	
	tmpRect = pic->clip_rect;
	rotozoomSurfaceSize(tmpRect.w, tmpRect.h, angle, zoom, &w, &h);
	tmp = rotozoomSurface(pic, angle, zoom, SMOOTHING_OFF);
	
	SDL_BlitSurface(tmp, NULL, screen, &r);
	
	SDL_FreeSurface(tmp);
}
