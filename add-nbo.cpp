// add-nbo.cpp
#include "add-nbo.h"

uint32_t add(uint32_t a, uint32_t b) {
	return a+b;
}

uint32_t bfile_read(char filename[], uint32_t *v1) {
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("%s is not exist\n", filename);
		return -1;
	}

	uint32_t a = 0;
	a += fgetc(fp)<<24;
	a += fgetc(fp)<<16;
	a += fgetc(fp)<<8;
	a += fgetc(fp);
	*v1 = a;

	fclose(fp);
	return 0;
}

uint32_t my_ntohl(uint32_t a) {
	uint32_t a1 = a & 0xff000000;
	uint32_t a2 = a & 0x00ff0000;
	uint32_t a3 = a & 0x0000ff00;
	uint32_t a4 = a & 0x000000ff;
	
	a = a4 << 24;
	a |= a3 << 8;
	a |= a2 >> 8;
	a |= a1 >> 24;

	return a;
}

uint32_t my_htonl(uint32_t a) {
	uint32_t a1 = a & 0xff000000;
	uint32_t a2 = a & 0x00ff0000;
	uint32_t a3 = a & 0x0000ff00;
	uint32_t a4 = a & 0x000000ff;
	
	a = a4 << 24;
	a |= a3 << 8;
	a |= a2 >> 8;
	a |= a1 >> 24;

	return a;
}
