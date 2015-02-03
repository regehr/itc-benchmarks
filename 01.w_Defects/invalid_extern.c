/********Software Analysis - FY2013*************/
/*
* File Name: invalid_extern.c
* Defect Classification
* ---------------------
* Defect Type: Misc defects
* Defect Sub-type: Bad extern type for global variable
*
*/

#include "HeaderFile.h"

/*
 * Types of defects: external variable type mistake
 * Complexity: external variable type error
 * Note: the PolySpace compilation error handling
 *       (variable has incompatible type with its ... declaration)
 */
/* #if ! (defined(CHECKER_POLYSPACE) || defined(CHECKER_VARVEL)) */
extern int *invalid_extern_001_glb_buf; /*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
extern int *invalid_extern_001_glb_float;/*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
extern int invalid_extern_001_glb_var3;/*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
extern float invalid_extern_001_glb_var4;/*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
extern char invalid_extern_001_glb_var5;/*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/
//extern invalid_extern_001_glb_006_s_001;
//extern invalid_extern_001_glb_006_s_001 *invalid_extern_001_glb_006_str;
extern char* invalid_extern_001_glb_006_str;/*Tool should detect this line as error*/ /*ERROR:Bad extern type for global variable*/

void invalid_extern_001 ()
{
	invalid_extern_001_glb_buf[3] = 1;
}

void invalid_extern_002 ()
{
	invalid_extern_001_glb_float[3] = 1;
}

void invalid_extern_003 ()
{
	invalid_extern_001_glb_var3 = 1;
}

void invalid_extern_004 ()
{
	invalid_extern_001_glb_var4 = 1.0;
}

void invalid_extern_005 ()
{
	invalid_extern_001_glb_var5 = 1.0;
}

void invalid_extern_006 ()
{
	invalid_extern_001_glb_006_str[1] = 'c';
}

/* #endif ! (defined(CHECKER_POLYSPACE) || defined(CHECKER_VARVEL)) */

/*
 * Types of defects: external variable type mistake
 * Complexity: volatile
 */
extern volatile int vflag;
void invalid_extern_main ()
{
/*#if ! (defined(CHECKER_POLYSPACE) || defined(CHECKER_VARVEL))*/
	if (vflag == 1 || vflag ==888)
	{
		invalid_extern_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		invalid_extern_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		invalid_extern_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		invalid_extern_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		invalid_extern_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		invalid_extern_006();
	}
/*#endif */ /* ! (defined(CHECKER_POLYSPACE) || defined(CHECKER_VARVEL)) */
}
