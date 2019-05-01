#define	IMPORT_BIN(section, file, sym) asm (\
		".section \"" section "\"\n"\
		".balign 4\n"\
		".global " #sym "\n"\
		#sym ":\n"\
		".incbin \"" file "\"\n"\
		".global _sizeof_" #sym "\n"\
		".set _sizeof_" #sym ", . - " #sym "\n"\
		".balign 4\n"\
		".section \".text\"\n")

IMPORT_BIN(".BASIC", "obj/entry.o", BASIC);

__attribute__ ((section(".ASMFLG"))) char ASMFLG[]  = { 1, 0, 0, 0 };

__attribute__ ((section(".MAIN"))) int main(int param, int ram, int rom, int (*divfunc)()) {
	//return param + 1;
	return divfunc(100, param); // == 100 / param
}
