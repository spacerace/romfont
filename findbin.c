#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>

uint8_t buf_token[4096];
uint8_t buf_image[128*1024];

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
	uint32_t size_token, size_image;
	struct stat stbuf;

	
	if(argc < 3) { print_help(); exit(-1); }
	
	strcpy(filename_token, argv[1]);
	strcpy(filename_image, argv[2]);

	stat(filename_token, &stbuf);
	size_token = stbuf.st_size;

	stat(filename_image, &stbuf);
	size_image = stbuf.st_size;
	
	ftoken = fopen(filename_token, "r");
	fimage = fopen(filename_image, "r");
	
	//printf("%02x\n", buf_image[0]);
	int i;
	for(i = 0; i < size_image; i++) {
		buf_image[i] = getc(fimage);
	}
	
	for(i = 0; i < size_token; i++) {
		buf_token[i] = getc(ftoken);
	}

	fclose(ftoken);
	fclose(fimage);
	
	uint8_t *ptr_image;
	uint8_t *ptr_token;
	ptr_token = (uint8_t *)&buf_token;
	ptr_image = (uint8_t *)&buf_image;
		
	uint32_t search_addr;
	
	for(search_addr = 0; search_addr < (size_image-size_token); search_addr++) {
		//printf("%05x\n", search_addr);
		if(!bcmp(ptr_token, ptr_image, size_token)) {
			printf("%s uses ", filename_image);
			printf("%s (%db) : ", filename_token, size_token);
			printf("0x%05x\n", search_addr);
		}
		ptr_image++;
	}	
	return 0;
}
