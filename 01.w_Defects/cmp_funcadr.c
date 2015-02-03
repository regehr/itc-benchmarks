/********Software Analysis - FY2013*************/
/*
* File Name: cmp_funcadr.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Comparison NULL with function pointer
*
*/

#include "HeaderFile.h"

/*
  * Types of defects: comparing the function address and NULL
  * Complexity: constant (NULL)
  */
int cmp_funcadr_001_glb_a;
int* cmp_funcadr_001_func_001 ()
{
	return &cmp_funcadr_001_glb_a;
}

void cmp_funcadr_001 ()
{
	int ret = 0;
	if (cmp_funcadr_001_func_001 == NULL) /*Tool should detect this line as error*/ /*ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}

/*
  * Types of defects: comparing the function address and NULL
  * Complexity: constant (number)
  * Note: Compile error in handling PolySpace
  * (Operands of == have incompatible types)
  */

int cmp_funcadr_002_func_001 ()
{
	return 10;
}

void cmp_funcadr_002 ()
{
	int ret = 0;
	if (cmp_funcadr_002_func_001 == NULL)/*Tool should detect this line as error*/ /*ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}
 /* ! defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: comparing function addresses with NULL
 * comparing function addresses main function
 */
extern volatile int vflag;
void cmp_funcadr_main ()
{
	if (vflag ==1 || vflag == 888)
	{
		cmp_funcadr_001();
	}

	if (vflag ==2 || vflag == 888)
	{
		cmp_funcadr_002();
	}

}
