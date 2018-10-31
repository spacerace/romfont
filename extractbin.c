#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <string.h>

void help() {
	printf("WARNING! THIS TOOL SIMPLY OVERWRITES FILES!\n");
	printf("./extractbin <infile> <start> <length> <outfile>\n");
}

int main(int argc, char **argv) {
	FILE *f, *fo;
	uint8_t *dptr;
	uint32_t start, end, size, count, infile_size, i;
	struct stat stbuf;
	char filename[128], filename_out[128];
	
	if(argc < 4) { help(); exit(-1); }

	strcpy(filename, argv[1]);
	start = (uint16_t)strtoul(argv[2], NULL, 16);
	size = (uint16_t)strtoul(argv[3], NULL, 10);
	strcpy(filename_out, argv[4]);
	end = start+size;
	
	f = fopen(filename, "r");
	if(f == NULL) {
		printf("cant open input file\n");
		exit(-1);
	}
	
	fo = fopen(filename_out, "w");
	if(fo == NULL) {
		printf("cant open output file\n");
		exit(-2);
	}
	
	stat(filename, &stbuf);
	infile_size = stbuf.st_size;
	
	printf("extracting from '%s'(%dbytes), 0x%05X-0x%05X (size 0x%05X/%dbytes)\n", filename, infile_size, start, end, size, size);
	printf("output file '%s'\n", filename_out);

	dptr = malloc(infile_size);
	
	for(count = 0; count < infile_size; count++) {
		*dptr = getc(f);
		dptr++;
	}
	
	printf("loaded %d bytes.\n", count);
	
	// rewind dptr and byte counter
	dptr -= infile_size;
	count = 0;
	
	// skip bytes, set dptr to start address
	for(i = 0; i <= start; i++) {
		dptr++;
	}
	
	for(i = 0; (i < size) ; i++) {
		fputc(*dptr, fo);
		dptr++;
	}
	
	fclose(fo);
	fclose(f);
	
	printf("written %d bytes.\n", size);
	
	return 0;
}


