/********Software Analysis - FY2013*************/
/*
* File Name: endless_loop.c
* Defect Classification
* ---------------------
* Defect Type: Misc defects
* Defect Sub-type: Unintentional end less loop
* Description: Defect Free Code to identify false positives in unintentional endless looping
*/

#include "HeaderFile.h"

/*
 * Types of defects: infinite loop
 * Complexity: the for statement	No ongoing condition equation
 */
void endless_loop_001 ()
{
	int ret;
	int a = 0;
	int i;
	for (i = 0; ; i ++)
	{
		a ++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (i > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: the for statement	No initialization expression for reuse
 */
void endless_loop_002 ()
{
	int ret;
	int a = 0;
	int i;
	for (i = 0; i < 10; )
	{
		a ++;
		i ++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	Constant
 */
void endless_loop_003 ()
{
	int ret;
	int a = 0;
	while (1)
	{
		a ++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	Variable
 */
void endless_loop_004 ()
{
	int ret;
	int a = 0;
	int flag = 1;
	while (flag)
	{
		a ++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	The return value of the function
 */
int endless_loop_005_func_001 ()
{
	return 1;
}

void endless_loop_005 ()
{
	int ret;
	int a = 0;
	while (endless_loop_005_func_001())
	{ /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		a ++;
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	Function arguments
 */
void endless_loop_006_func_001 (int flag)
{
	int ret;
	int a = 0;
	while (flag)
	{
		a ++; /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

void endless_loop_006 ()
{
	endless_loop_006_func_001(1);
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	(a<b)
 */
void endless_loop_007 ()
{
	int ret;
	int a = 0;
	int flag = 1;
	while (flag > 0) /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
	{
		a ++;
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: while statement	(a==b)
 */
void endless_loop_008 ()
{
	int ret;
	int a = 0;
	int flag = 0;
	while (flag == 0) /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
	{
		a ++;
		if (a > 5)
		{
			break;
		}
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * Complexity: do-while statement	Constant
 */
void endless_loop_009 ()
{
	int ret;
	int a = 0;
	do
	{
		a ++;
		if (a > 5)
		{
			break;
		}
	}
	while (1); /*Tool should Not detect this line as error*/ /*No ERROR:Unintentional end less loop*/
	ret = a;
        sink = ret;
}

/*
 * Types of defects: infinite loop
 * endless loop main function
 */
extern volatile int vflag;
void endless_loop_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		endless_loop_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		endless_loop_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		endless_loop_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		endless_loop_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		endless_loop_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		endless_loop_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		endless_loop_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		endless_loop_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		endless_loop_009();
	}
}
