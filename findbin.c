#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>

void print_help() {
	printf("searches for a bin image in a file. prints all found offsets.\n");
	printf("usage:\n");
	printf("  findbin tokenfile imagetobesearched\n");
	printf("\n");
	return;
}

int main(int argc, char **argv) {
	FILE *ftoken, *fimage;
	char filename_token[128], filename_image[128];
//	uint32_t offset;
	uint32_t size_token, size_image;
	struct stat stbuf;

	
	if(argc < 3) { print_help(); exit(-1); }
	
	strcpy(filename_token, argv[1]);
	strcpy(filename_image, argv[2]);

	stat(filename_token, &stbuf);
	size_token = stbuf.st_size;

	stat(filename_image, &stbuf);
	size_image = stbuf.st_size;
	
	printf("searching for '%s' (%dbytes) in '%s' (%dbytes)\n", filename_token, size_token, filename_image, size_image);
	
	uint8_t *ptr_tok = malloc(size_token);
	uint8_t *ptr_img = malloc(size_image);
	
	ftoken = fopen(filename_token, "r");
	fimage = fopen(filename_image, "r");

	
	
	printf("%02x\n", *ptr_tok);
	printf("%02x\n", *(ptr_tok+1));
	
	fclose(ftoken);
	fclose(fimage);
	
	
	
}
