#include "stdio.h"
#include "string.h"

int getNumber(char* s) {
	char c = *s;
	s++;
	if (c >= '0' && c <= '9') { // number
		int value = 0;
		for (;;) {
			value = value * 10 + (c - '0');
			c = *s;
			s++;
			if (c < '0' || c > '9')
				break;
		}
		return value;
	} else {
		return -1;
	}
}
void deleteEnter(char* s) {
	for (;;) {
		if (*s == 0)
			break;
		if (*s == '\r' || *s == '\n') {
			*s = 0;
			return;
		}
		s++;
	}
}
char* getBody(char* s) {
	for (;;) {
		char c = *s;
		if (c == ' ') {
			return s + 1;
		}
		if (c == 0)
			return 0;
		s++;
	}
}

int file_length(char* fn) {
	FILE* fp = fopen(fn, "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fclose(fp);
	return size;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("bas2bin [bas file] [bin file]\n");
		return 1;
	}
	
	FILE* in = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "wb");
	char line[256];
	int blen = 0;
	for (;;) {
		if (!fgets(line, 256, in)) {
			break;
		}
		deleteEnter(line);
		if (!strlen(line)) {
			continue;
		}
		int num = getNumber(line);
		if (num <= 0) {
			printf("error: %s\n", line);
			return 1;
		}
		char* body = getBody(line);
		int len = strlen(body);
		int align = len & 1; // align 2byte
		
		putc(num & 0xff, out); // num
		putc(num >> 8, out);
		putc(len + align, out); // len
		fputs(body, out); // body
		putc(0, out);
		if (align)
			putc(0, out);
		blen += 3 + len + align + 1;
		
		printf("%d %s\n", num, body);
//		putc(len, out);
//		fputs(line, out);
	}
	putc(0, out);
	putc(0, out);
	blen += 2;
	
	fclose(in);
	
	if (blen > 1024) {
		fclose(out);
		printf("over 1k\n");
		return 1;
	}
	for (int i = 0; i < 1024 - blen; i++) {
		putc(0, out);
	}
	
	fclose(out);
	return 0;
}
