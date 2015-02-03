/********Software Analysis - FY2013*************/
/*
* File Name: unused_var.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Unused variable
* Description: Defect Code to identify the unused variable in a function
*/

#include "HeaderFile.h"

/*
 * Types of defects: unused variable
 * Complexity: basic types	Internal variables
 */
void unused_var_001 ()
{
	int a = 1;
	int b = 2;
	int unuse;

	unuse = a + b; /*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * Complexity: structure member	Internal variables
 */
typedef struct {
	int a;
	int b;
	int unuse;
} unused_var_002_s_001;

void unused_var_002 ()
{
	unused_var_002_s_001 s;
	s.a = 1;
	s.b = 2;
	s.unuse = s.a + s.b;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * Complexity: Union Member	Internal variables
 */
typedef struct {
	int a;
	int b;
} unused_var_003_s_001;

typedef struct {
	int a;
	int b;
} unused_var_003_s_002;

typedef struct {
	int a;
	int unuse;
} unused_var_003_s_003;

typedef union {
	unused_var_003_s_001 s1;
	unused_var_003_s_002 s2;
	unused_var_003_s_003 s3;
} unused_var_003_uni_001;

void unused_var_003 ()
{
	unused_var_003_uni_001 u;


	u.s1.a = 1;
	u.s1.b = 2;
	u.s3.a = u.s2.a + u.s2.b;
	u.s3.unuse = u.s1.a;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * Complexity: basic types	Global variables
 */
int unused_var_004_glb_a = 1;
int unused_var_004_glb_b = 2;
int unused_var_004_glb_unuse;

void unused_var_004 ()
{
	unused_var_004_glb_unuse = unused_var_004_glb_a + unused_var_004_glb_b;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * Complexity: basic types	static variable in the File
 */
static int unused_var_005_glb_a = 1;
static int unused_var_005_glb_b = 2;
static int unused_var_005_glb_unuse;

void unused_var_005 ()
{
	unused_var_005_glb_unuse = unused_var_005_glb_a + unused_var_005_glb_b;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * Complexity: basic types	static variable in the Function
 */
void unused_var_006 ()
{
	static int a = 1;
	static int b = 2;
	static int unuse;
	if(a==1)
	{	
	    unuse = a + b;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
	}
}

/*
 * Types of defects: unused variable
 * Complexity: Union Member	Internal variables
 */
typedef struct {
	int a;
	int b;
} unused_var_007_s_001;

typedef struct {
	int a;
	int b;
} unused_var_007_s_002;

typedef struct {
	int a;
	int unuse;
} unused_var_007_s_003;

typedef union {
	unused_var_007_s_001 s1;
	unused_var_007_s_002 s2;
	unused_var_007_s_003 s3;
} unused_var_007_uni_001;

unused_var_007_uni_001 unused_var_007_uni_001_gbl;
void unused_var_007 ()
{
	unused_var_007_uni_001_gbl.s1.a = 1;
	unused_var_007_uni_001_gbl.s1.b = 2;
	unused_var_007_uni_001_gbl.s3.a = unused_var_007_uni_001_gbl.s1.a + unused_var_007_uni_001_gbl.s1.b;/*Tool should detect this line as error*/ /*ERROR:Unused variable*/
}

/*
 * Types of defects: unused variable
 * unused variable main function
 */
extern volatile int vflag;
void unused_var_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		unused_var_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		unused_var_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		unused_var_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		unused_var_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		unused_var_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		unused_var_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		unused_var_007();
	}
}
