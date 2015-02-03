/********Software Analysis - FY2013*************/
/*
* File Name: ow_memcpy.c
* Defect Classification
* ---------------------
* Defect Type: Dynamic memory defects
* Defect Sub-type: Memory copy at overlapping areas
*
*/

#include "HeaderFile.h"

/*
 * Types of defects: copy of the overlapped area
 * Complexity: loop in a function
 */
void ow_memcpy_001 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < 3; i ++)
	{
		buf[i] = buf[i+2];/*Tool should detect this line as error*/ /*ERROR:copy of the overlapped area*/
	}
}

/*
 * Types of defects: copy of the overlapped area
 * Complexity: when calling a function (equivalent to memcpy)
 */
void ow_memcpy_002_func_001 (void *dst, const void *src, int size)
{
	unsigned char *p;
	unsigned char *q;
	int i;
	p = (unsigned char *)src;
	q = (unsigned char *)dst;
	for (i = 0; i < size; i ++)
	{
		*q = *p;/*Tool should detect this line as error*/ /*ERROR:copy of the overlapped area*/
		p ++;
		q ++;
	}
}

void ow_memcpy_002 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	ow_memcpy_002_func_001(&buf[2], &buf[0], (3 * sizeof(int)));
}

/*
 * Types of defects: copy of the overlapped area
 * Complexity: volatile
 */
extern volatile int vflag;
void ow_memcpy_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		ow_memcpy_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		ow_memcpy_002();
	}
}
