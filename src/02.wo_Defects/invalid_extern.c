/********Software Analysis - FY2013*************/
/*
* File Name: invalid_extern.c
* Defect Classification
* ---------------------
* Defect Type: Misc defects
* Defect Sub-type: Bad extern type for global variable
* Description: Defect Free Code to identify false positives during invalid extern declaration
*/

/*
 * Types of defects: external variable type mistake
 * Complexity: external variable type error
 * Note: the PolySpace compilation error handling
 *       (variable has incompatible type with its ... The following)
 */
/* #if ! (defined(CHECKER_POLYSPACE) || defined(CHECKER_VARVEL)) */
#include "HeaderFile.h"
extern int invalid_extern_001_glb_buf[5]; /*Tool should not detect this line as error*/ /*No ERROR:Bad extern type for global variable*/
extern float invalid_extern_001_glb_float[5] ; /*Tool should not detect this line as error*/ /*No ERROR:Bad extern type for global variable*/
extern float invalid_extern_001_glb_var3[5] ; /*Tool should not detect this line as error*/ /*No ERROR:Bad extern type for global variable*/
extern int invalid_extern_001_glb_var4 ; /*Tool should not detect this line as error*/ /*No ERROR:Bad extern type for global variable*/
extern float invalid_extern_001_glb_var5 ; /*Tool should not detect this line as error*/ /*No ERROR:Bad extern type for global variable*/

typedef struct {
        int  csr;
        int  data;
}invalid_extern_001_glb_006_s_001;

extern invalid_extern_001_glb_006_s_001 *invalid_extern_001_glb_006_str;


void invalid_extern_001 ()
{
	invalid_extern_001_glb_buf[3] = 1;
}

void invalid_extern_002 ()
{
	invalid_extern_001_glb_float[3] = 1.0;
}

void invalid_extern_003 ()
{
	invalid_extern_001_glb_var3[3] = 1.0;
}

void invalid_extern_004 ()
{
	invalid_extern_001_glb_var4 = 1;
}

void invalid_extern_005 ()
{
	invalid_extern_001_glb_var5 = 1.0;
}

void invalid_extern_006 ()
{
	invalid_extern_001_glb_006_str = (invalid_extern_001_glb_006_s_001 *) malloc(1*sizeof(invalid_extern_001_glb_006_s_001));
	invalid_extern_001_glb_006_str->csr = 10;
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
