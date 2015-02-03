/********Software Analysis - FY2013*************/
/*
* File Name: ptr_subtraction.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Incorrect pointer arithmetic
*
*/

#include "HeaderFile.h"

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: an incorrect pointer arithmetic
 */
void ptr_subtraction_001 ()
{
	char buf1[5];
	char buf2[5];
	intptr_t offset;
	offset = buf2 - buf1; /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*/
        sink = offset;
}

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: an incorrect pointer arithmetic
 */
void ptr_subtraction_002 ()
{
	int x= 10;
	int *ptr = &x;
	char *buf ;
	buf= (char *)(ptr+1); /*Tool should detect this line as error*/ /*ERROR:Incorrect pointer arithmetic*/
}

/*
 * Types of defects: an incorrect pointer arithmetic
 * Complexity: volatile
 */
extern volatile int vflag;
void ptr_subtraction_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		ptr_subtraction_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		ptr_subtraction_002();
	}

}
