#include <stdio.h>
#include <stdint.h>

void print_help() {
	printf("searches for a bin image in a file. prints all found offsets.\n");
	printf("usage:\n");
	printf("  findbin imagetofind imagetobesearched\n");
	printf("\n");
	return;
}

int main(int argc, char **argv) {
	FILE *fimage, *fsearch;
	char filename_image[128], filename_search[128];
	uint32_t offset;
	uint32_t size_search, size_image;
	
	
	if(argc < 3) { print_help(); exit(-1); }
	
	strcpy(filename_image, argv[1]);
	strcpy(filename_search, argv[2]);
	
	printf("searching for '%s' (%dbytes) in '%s' (%dbytes)\n", filename_image, size_image, filename_search, size_search);
}
