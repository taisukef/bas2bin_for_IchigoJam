/* IchigoJam Memory Definitions */

MEMORY {
  /* Flash: 3kbyte-4byte */
  ROM (rx) : ORIGIN = 0x00000000, LENGTH = 3k-4
  /* SRAM: 4k?? */
  RAM (w)  : ORIGIN = 0x10000000, LENGTH = 4k
}

SECTIONS {
   .text : {
    KEEP(*(.BASIC))     /* launch basic code */
    KEEP(*(.ASMFLG))    /* asm flag */
    KEEP(*(.MAIN))      /* main */
  } > ROM
}
