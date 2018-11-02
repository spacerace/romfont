#include <stdio.h>
#include <stdint.h>

#include "bochs8x8.h"

int main() {
	int i;
	FILE *f;

	f = fopen("bochslower127_8x8.bin", "w");
	for(i = 0; i < (128*8); i++) {
		fputc(bochs8x8_lower[i], f);
	}
	fclose(f);
	
	return 0;

}
