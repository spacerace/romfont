#include <stdio.h>
#include <stdint.h>

#include "seabios8x8.h"
#include "seabios8x14.h"
#include "seabios8x16.h"

int main() {
	int i;
	FILE *f;

	f = fopen("seabios8x8.bin", "w");
	for(i = 0; i < (256*8); i++) {
		fputc(seabios8x8[i], f);
	}
	fclose(f);
	
	f = fopen("seabios8x14.bin", "w");
	for(i = 0; i < (256*14); i++) {
		fputc(seabios8x14[i], f);
	}
	fclose(f);

	f = fopen("seabios8x16.bin", "w");
	for(i = 0; i < (256*16); i++) {
		fputc(seabios8x16[i], f);
	}
	fclose(f);
	

	return 0;

}
