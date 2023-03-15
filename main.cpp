// main.cpp
#include <stdio.h>
#include "add-nbo.h"

int main(int argc, char **argv) {
	if(argc != 3) {
		printf("syntax : ./add-nbo <file1> <file2>\n");
		return -1;
	}
	
	uint32_t a, b;
	if(bfile_read(argv[1], &a)) return -1;
	if(bfile_read(argv[2], &b)) return -1;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);
	return 0;
}

