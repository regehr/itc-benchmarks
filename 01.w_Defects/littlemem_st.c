/********Software Analysis - FY2013*************/
/*
* File Name: littlemem_st.c
* Defect Classification
* ---------------------
* Defect Type: Dynamic memory defects
* Defect Sub-type: Assign small buffer for structure
*
*/


/*
* Types of defects: structure type for securing small size (static)
* Complexity: read pointer structure
*/
#include "HeaderFile.h"
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_001_s_001;

void littlemem_st_001 ()
{
	char buf[10];
	littlemem_st_001_s_001 *p;
	int ret;
	int i;

	for (i = 0; i < 10; i ++)
	{
		buf[i] = 1;
	}

	p = (littlemem_st_001_s_001 *)buf;
	ret = p->c; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
    printf("%d \n",p->c);
}

/*
* Types of defects: structure type for securing small size (static)
* Complexity: writing structure pointer
*/
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_002_s_001;

void littlemem_st_002 ()
{
	char buf[10];
	littlemem_st_002_s_001 *p;
	p = (littlemem_st_002_s_001 *)buf;
	p->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

/*
* Types of defects: structure type for securing small size (static)
* Complexity: write pointer union
*/
typedef union {
	char a;
	short b;
	int c;
} littlemem_st_003_uni_001;

void littlemem_st_003 ()
{
	char buf[2];
	littlemem_st_003_uni_001 *p;
	p = (littlemem_st_003_uni_001 *)buf;
	p->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: struct pointer	Write - Global
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_004_s_001;
littlemem_st_004_s_001 *littlemem_st_004_s_001_gbl_str;

void littlemem_st_004 ()
{
	char buf[10];

	littlemem_st_004_s_001_gbl_str = (littlemem_st_004_s_001 *)buf;
	littlemem_st_004_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: struct pointer	Write - Global , assigned in another function
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_005_s_001;

littlemem_st_005_s_001 *littlemem_st_005_s_001_gbl_str;

char littlemem_st_005_gbl_buf[10];

void littlemem_st_005_func_001 ()
{
	littlemem_st_005_s_001_gbl_str = (littlemem_st_005_s_001 *)littlemem_st_005_gbl_buf;
}

void littlemem_st_005 ()
{
	littlemem_st_005_func_001();
	littlemem_st_005_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside if condition
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_006_s_001;

littlemem_st_006_s_001 *littlemem_st_006_s_001_gbl_str;
#define MAX_STR 10

char littlemem_st_006_gbl_buf[10];

void littlemem_st_006_func_001 ()
{
	littlemem_st_006_s_001_gbl_str = (littlemem_st_006_s_001 *)littlemem_st_006_gbl_buf;
}

void littlemem_st_006_func_002 (int flag)
{
	if(flag == MAX_STR)
	{
		littlemem_st_006_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
	}
}

void littlemem_st_006 ()
{
	littlemem_st_006_func_001();
	littlemem_st_006_func_002(10);
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside for loop
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_007_s_001;

littlemem_st_007_s_001 *littlemem_st_007_s_001_gbl_str;
#define MAX_STR1 10

char littlemem_st_007_gbl_buf[10];

void littlemem_st_007_func_001 ()
{
	littlemem_st_007_s_001_gbl_str = (littlemem_st_007_s_001 *)littlemem_st_007_gbl_buf;
}

void littlemem_st_007_func_002 (int flag)
{
	int i;
	for(i=0;i<2;i++)
	{
		if(flag == MAX_STR1)
		{
			;
		}
		else
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
		}
	}
}

void littlemem_st_007 ()
{
	littlemem_st_007_func_001();
	littlemem_st_007_func_002(1);
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside while loop
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_008_s_001;

littlemem_st_008_s_001 *littlemem_st_008_s_001_gbl_str;
#define MAX_STR2 10
#define MAX_STR3 1

char littlemem_st_008_gbl_buf[10];

void littlemem_st_008_func_001 ()
{
	littlemem_st_008_s_001_gbl_str = (littlemem_st_008_s_001 *)littlemem_st_008_gbl_buf;
}

void littlemem_st_008_func_002 (int flag)
{
	int i=0;
	while(i<2)
	{
		if(flag == MAX_STR2)
		{
			;
		}
		else if(flag == MAX_STR3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
		}
	    i++;
	}
}

void littlemem_st_008 ()
{
	littlemem_st_008_func_001();
	littlemem_st_008_func_002(1);
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside do - while loop
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_009_s_001;

littlemem_st_009_s_001 *littlemem_st_009_s_001_gbl_str;
#define MAX_2 10
#define MAX_3 1

char littlemem_st_009_gbl_buf[10];

void littlemem_st_009_func_001 ()
{
	littlemem_st_009_s_001_gbl_str = (littlemem_st_009_s_001 *)littlemem_st_009_gbl_buf;
}

void littlemem_st_009_func_002 (int flag)
{
	int i=0;
	do
	{
		if(flag == MAX_2)
		{
			;
		}
		else if(flag == MAX_3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
		}
	    i++;
	}while(i<2);
}

void littlemem_st_009 ()
{
	littlemem_st_009_func_001();
	littlemem_st_009_func_002(1);
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside and goto
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_010_s_001;

littlemem_st_010_s_001 *littlemem_st_010_s_001_gbl_str;

char littlemem_st_010_gbl_buf[10];

void littlemem_st_010_func_001 ()
{
	littlemem_st_010_s_001_gbl_str = (littlemem_st_010_s_001 *)littlemem_st_010_gbl_buf;
}

void littlemem_st_010_func_002 (int flag)
{
	goto label;
	label:
		littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
}

void littlemem_st_010 ()
{
	littlemem_st_010_func_001();
	littlemem_st_010_func_002(1);
}

/*
 * Types of defects: Allocate small size for type - structure  (static)
 * Complexity: Struct pointer	Write - Global , assigned in another function inside while loop and goto
 */
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_011_s_001;

littlemem_st_011_s_001 *littlemem_st_011_s_001_gbl_str;

char littlemem_st_011_gbl_buf[10];

void littlemem_st_011_func_001 ()
{
	littlemem_st_011_s_001_gbl_str = (littlemem_st_011_s_001 *)littlemem_st_011_gbl_buf;
}

void littlemem_st_011_func_002 (int flag)
{
	int i=0;
	goto label;

	label:
	while(i<2)
	{
		littlemem_st_007_s_001_gbl_str->c = 1; /*Tool should detect this line as error*/ /*ERROR:Little Memory or Overflow*/
	    i++;
	}
}

void littlemem_st_011 ()
{
	littlemem_st_011_func_001();
	littlemem_st_011_func_002(1);
}
/*
 * Types of defects: Allocate small size for type - structure/ union  (static)
 * little memory main function
 */
extern volatile int vflag;
void littlemem_st_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		littlemem_st_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		littlemem_st_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		littlemem_st_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		littlemem_st_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		littlemem_st_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		littlemem_st_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		littlemem_st_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		littlemem_st_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		littlemem_st_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		littlemem_st_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		littlemem_st_011();
	}
}
