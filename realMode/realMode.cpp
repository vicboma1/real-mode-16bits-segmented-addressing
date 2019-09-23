#include "pch.h"
#include <iostream>
#include <windows.h>

//returns a far pointer from offset and segment
#define MK_FP(seg,off)  (void far *) (((unsigned long)(seg) << 16) | (unsigned)(off))

//gets offset of far pointer fptr , returns unsigned integer value
#define FP_OFF(fptr)	((unsigned)(fptr))

//gets segment of far pointer fptr, returns unsigned integer value
#define FP_SEG(fptr) ((unsigned)((unsigned long)(fptr) >> 16))


int main()
{
	std::cout << "\n";

	void far *a = MK_FP(0x0000, 0x0120);
	void far *b = MK_FP(0x0010, 0x0100);
	void far *c = MK_FP(0x0020, 0x0000);

	printf("MK_FP(SEGMENT, OFFSET)\n");

	printf("a = MK_FP(0x0000, 0x0120) =  MK_FP(0 ,288) = %p \n", a);
	printf("b = MK_FP(0x0010, 0x0100) =  MK_FP(16,256) = %p \n", b);
	printf("c = MK_FP(0x0020, 0x0000) =  MK_FP(32,0)   = %p \n", c);

	printf("MK_FP(0x0000, 0x0120) == MK_FP(0x0010, 0x0100) | a == b | %d\n", a == b);
	printf("MK_FP(0x0000, 0x0120) == MK_FP(0x0020, 0x0000) | a == c | %d\n", a == c);
	printf("MK_FP(0x0010, 0x0100) == MK_FP(0x0020, 0x0000) | b == c | %d\n", b == c);

	unsigned aa = FP_OFF(a);
	unsigned bb = FP_OFF(b);
	unsigned cc = FP_OFF(c);

	printf("FP_OFF(%p) | %d\n", a, aa);
	printf("FP_OFF(%p) | %d\n", b, bb);
	printf("FP_OFF(%p) | %d\n", c, cc);

	unsigned aaa = FP_SEG(a);
	unsigned bbb = FP_SEG(b);
	unsigned ccc = FP_SEG(c);

	printf("FP_SEG(%p) | %d\n", a, aaa);
	printf("FP_SEG(%p) | %d\n", b, bbb);
	printf("FP_SEG(%p) | %d\n", c, ccc);

	std::cout << "0 \n";
}