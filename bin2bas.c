#include <stdio.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("bin2bas [bin file]\n");
		return 1;
	}
	FILE* fp = fopen(argv[1], "rb");
	if (!fp) {
		printf("can't open file\n");
		return 1;
	}
	char buf[30];
	int address = 0x700;
	int line = 10;
	for (;;) {
		int n = fgetc(fp);
		if (n == EOF)
			break;
		if (address % 32 == 0) {
			printf("\n%d POKE#%03x", line, address);
			line += 10;
		}
		address++;
		printf(",%d", n);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
