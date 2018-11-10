#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>

void help();

int main(int argc, char **argv) {
	uint32_t size, w = 8;
	FILE *f = fopen(argv[1], "r");
	struct stat stbuf;

	if(argc < 4) { help(); exit(-1); }

	stat(argv[1], &stbuf);
	if(f == NULL) {
		printf("cant open...\n");
		help();
		exit(-1);
	}
	size = stbuf.st_size;

	w = (uint32_t)strtoul(argv[3], NULL, 10);

	printf("/*\n");
	printf(" * file '%s', filesize %dbytes, linewidth=%dbytes\n", argv[1], size, w);
	printf(" * array created from bin-file by bin2header\n");
	printf(" * bin2header (c) 2013 Nils Stec, <nils.stec@gmail.com>\n");
	printf(" *\n");
	printf(" */\n\n");

	uint32_t count = 0;
	uint8_t data;
	uint8_t x_count = 0;

	printf("uint8_t %s[%d] = {\n", argv[2], size);

	while(count < size) {
		printf("\t");
		for(x_count = 0; x_count < w; x_count++) {
			data = getc(f);
			printf("0x%02x", data);
			count++;
			if(count == size) break;
			else {
				printf(", ");
			}
		}
		printf("\n");

	}
	printf("};\n");

	return 0;

}

void help() {
	printf("usage: bin2header <filename> <array-name> <linewidth>\n");
	printf("       linewidth = number of bytes per line\n");
	printf("write to file: bin2header <filename> <array-name> <linewidth> > header.h\n");
	return;
}
