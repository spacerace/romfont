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
    SDL_Event event;
    int x, y, c, quit = 0, infile_size, i, fy = 0;
    int font_type;
    char filename[128], temp[32];
    double zoomfactor_char = 0;
    int changed = 1;
    int x_char = 0;
    int y_char = 0;
   	struct stat stbuf;
   	uint8_t r = 0xff, g = 0x99, b = 0x00, a = 0xff;
   	FILE *f;
   	uint8_t zoomed_char = '\xb1';

	if(argc < 2) {
		printf("usage: %s <filename>\n", argv[0]);
	}

    strcpy(filename, argv[1]);
	f = fopen(filename, "r");
	if(f == NULL) {
		printf("cant open input file\n");
		exit(-1);
	}
	
	/* get filesize */
	stat(filename, &stbuf);
	infile_size = stbuf.st_size;

    printf("displaying '%s' (%dbytes)\n", filename, infile_size);
	
	switch(infile_size) {
		case 1024:
			printf("1/2 8x8 font (1024)\n");
			font_type = FTYPE8x8;
			fy = 8;
			memset(buffer, 0xff, 2048);
			zoomed_char = 0x0A;
			break;
		case 2048:
			printf("8x8 font (2048b)\n");
			font_type = FTYPE8x8;
			fy = 8;
			break;
		case 3584:
			printf("8x14 font (3584b)\n");
			font_type = FTYPE8x14;
			fy = 14;
			break;
		case 3840:
			printf("8x15 font (3840b)\n");
			font_type = FTYPE8x15;
			fy = 15;
			break;	
		case 4096:
			printf("8x16 font (4096b)\n");
			font_type = FTYPE8x16;
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
    /* create a empty surface for the zoomed charset (4x) */
    charset_zoomed = SDL_CreateRGBSurface(SDL_SWSURFACE, 700, 730, 32, rmask, gmask, bmask, amask);
    /* create a empty sutface for a zoomed char */
    ch = SDL_CreateRGBSurface(SDL_SWSURFACE, 200, 200, 32, rmask, gmask, bmask, amask);

    while(SDL_WaitEvent(&event) && !quit) {
		if(changed) {	/* screen has changed */
			/* clear all surfaces before writing to them */
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			SDL_FillRect(charset, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			SDL_FillRect(charset_zoomed, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			SDL_FillRect(ch, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			
			int fx = 8;
			
			/* draw the charset (unzoomed) */
			for(y = 0; y < 16; y++) {
				for(x = 0; x < 16; x++) {
					c = (y*16)+x;
					switch(font_type) {
						case FTYPE8x8:
							fy = 8;
							zoomfactor_char = 40;
							x_char = 15;
							y_char = 390;			
							break;
						case FTYPE8x14:
							fy = 14;
							zoomfactor_char = 27;
							x_char = 20;
							y_char = 275;					
							break;
						case FTYPE8x15:
							fy = 15;
							zoomfactor_char = 27;
							x_char = 20;
							y_char = 275;					
							break;
						case FTYPE8x16:
							fy = 16;
							zoomfactor_char = 27;
							x_char = 20;
							y_char = 275;
							break;
					}
					putc_(charset, x*(fx+1), y*(fy+1), fy, c, 255, 255, 255, 255);
					if(c == zoomed_char) {
							/* draw selected char highlighted in charset */
							putc_(charset, x*(fx+1), y*(fy+1), fy, c, r, g, b, a);
							/* prepre zoomed char */
							putc_(ch, 0, 0, fy, c, r, g, b, a);
					}
				}
			}

			/* draw the surfaces to screen */
			draw_zoomed(ch, x_char, y_char, zoomfactor_char);
			draw_zoomed(charset, 3, 3, 1);
			draw_zoomed(charset, 300, 10, 2.6);
			
			stringColor(screen, 160, 3, "      KEYS:", 0x00FFFFFF);
			stringColor(screen, 160, 20, "LRUD - navigate", 0x00FFFFFF);
			stringColor(screen, 160, 36, "123456 - RGB+-", 0x00FFFFFF);
			stringColor(screen, 160, 52, "qwertz - RGB+-10", 0x00FFFFFF);
			stringColor(screen, 160, 68, "ESC - quit", 0x00FFFFFF);
			
			snprintf(temp, 31, "R=%03d", r);
			stringColor(screen, 160, 86, temp, 0xFFF90AFF);
			snprintf(temp, 31, "G=%03d", g);
			stringColor(screen, 160, 102, temp, 0xFFF90AFF);
			snprintf(temp, 31, "B=%03d", b);
			stringColor(screen, 160, 118, temp,  0xFFF90AFF);
			
			snprintf(temp, 31, "c=%02x/%d", zoomed_char, zoomed_char);
			stringColor(screen, 160, 140, temp, 0xCC00FFFF);
		
			snprintf(temp, 31, "size=8x%d", fy);
			stringColor(screen, 160, 160, temp, 0xCCCCCCFF);
			
			SDL_UpdateRect(screen, 0, 0, 700, 730);
			printf(".");
			changed = 0;
		}
		
        switch(event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                    case SDLK_UP:
						zoomed_char -= 16;
						changed = 1;
						break;
					case SDLK_DOWN:
						zoomed_char += 16;
						changed = 1;
						break;
					case SDLK_LEFT:
						zoomed_char--;
						changed = 1;
						break;
					case SDLK_RIGHT:
						zoomed_char++;
						changed = 1;
						break;
					case SDLK_1:
						r+= 1;
						changed = 1;
						break;
					case SDLK_2:
						r-=1;
						changed = 1;
						break;
					case SDLK_3:
						g+=1;
						changed = 1;
						break;
					case SDLK_4:
						g-=1;
						changed = 1;
						break;
					case SDLK_5:
						b+=1;
						changed = 1;
						break;
					case SDLK_6:
						b-=1;
						changed = 1;
						break;
					case SDLK_q:
						r+= 10;
						changed = 1;
						break;
					case SDLK_w:
						r-=10;
						changed = 1;
						break;
					case SDLK_e:
						g+=10;
						changed = 1;
						break;
					case SDLK_r:
						g-=10;
						changed = 1;
						break;
					case SDLK_t:
						b+=10;
						changed = 1;
						break;
					case SDLK_z:
						b-=10;
						changed = 1;
						break;
                    default:
                        break;
                }
                break;
        }
    }
    
    fclose(f);
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
