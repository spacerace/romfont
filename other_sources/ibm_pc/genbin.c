#include <stdio.h>
#include <stdint.h>

#include "v1"
#include "v2"
#include "v3"

int main() {
	int i;
	FILE *f;

	f = fopen("IBM_PC_V1_8x8.bin", "w");
	for(i = 0; i < (128*8); i++) {
		fputc(IBM_PC_V1_8x8[i], f);
	}
	fclose(f);
	
	f = fopen("IBM_PC_V2_8x8.bin", "w");
	for(i = 0; i < (128*8); i++) {
		fputc(IBM_PC_V2_8x8[i], f);
	}
	fclose(f);

	f = fopen("IBM_PC_V3_8x8.bin", "w");
	for(i = 0; i < (128*8); i++) {
		fputc(IBM_PC_V3_8x8[i], f);
	}
	fclose(f);
	

	return 0;

}
