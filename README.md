# bas2bin_for_IchigoJam

Let's make BASIC program on your PC!  
This tool is converter from IchigoJam BASIC to bin file.  
You can add the C language code up to 3KB as asm!  

## how to use

```
$ gcc bas2bin.c -o bas2bin  
$ ./bas2bin test.bas test.bin  
$ cat ichigojam.bin test.bin > ichigojam-pack.bin  
$ lpc21isp -bin ichigojam-pack.bin ...  
```

ichigojam.bin is firmware of IchigoJam.  
http://ichigojam.net/  

## options

--nopadding  omit the padding  
--limit4k  for IchigoCake  

## 3kb machine language

edit src/main.c, src/entry.bas  
```
$ make  
```
(need arm-none-eabi-gcc and so on)  

## license

CC BY 4.0 http://ichigojam.net/  
