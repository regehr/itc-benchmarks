/********Software Analysis - FY2013*************/
/*
* File Name: dead_code.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Dead code
* Description: Defect Code to identify defects in dead code
*/

#include "HeaderFile.h"

/*
* Types of defects: dead code
* Complexity: Constant if statement
*/
void dead_code_001 ()
{
	int a = 0;
	int ret;
	if (0)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: the if statement	Variable
 */
void dead_code_002 ()
{
	int flag = 0;
	int a = 0;
	int ret;
	if (flag)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: the if statement	The return value of the function
 */
int dead_code_003_func_001 ()
{
	return 0;
}

void dead_code_003 ()
{
	int a = 0;
	int ret;
	if (dead_code_003_func_001())
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: the if statement	Function arguments
 */
void dead_code_004_func_001 (int flag)
{
	int a = 0;
	int ret;
	if (flag)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

void dead_code_004 ()
{
	dead_code_004_func_001(0);
}

/*
* Types of defects: dead code
* Complexity: statement expression if (a <b)
*/
void dead_code_005 ()
{
	int flag = 0;
	int a = 0;
	int ret;
	if (flag > 0)
	{
		a ++; /*Tool should  detect this line as error*/ /* ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: the if statement	(a == b)
 */
void dead_code_006 ()
{
	int flag = 1;
	int a = 0;
	int ret;
	if (flag == 0)
	{
		a ++; /*Tool should  detect this line as error*/ /* ERROR:Dead Code*/
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: the for statement	Constant
 */
void dead_code_007 ()
{
	int a = 0;
	int i;
	int ret;
	for (i = 0; i>1; i ++)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

/*
* Types of defects: dead code
* Complexity: constant while statement
*/
void dead_code_008 ()
{
	int a = 0;
	int ret;
	while (0)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

/*
* Types of defects: dead code
* Complexity: variable while statement
*/
void dead_code_009 ()
{
	int flag = 0;
	int a = 0;
	int ret;
	while (flag)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

/*
* Types of defects: dead code
* Complexity: The return value of the function while statement
*/
int dead_code_010_func_001 ()
{
	return 0;
}

void dead_code_010 ()
{
	int a = 0;
	int ret;
	while (dead_code_010_func_001())
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: while statement	Function arguments
 */
void dead_code_011_func_001 (int flag)
{
	int a = 0;
	int ret;
	while (flag)
	{
		a ++;/*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

void dead_code_011 ()
{
	dead_code_011_func_001(0);
}

/*
* Types of defects: dead code
* Complexity: expression statement while (a <b)
*/
void dead_code_012 ()
{
	int flag = 0;
	int a = 0;
	int ret;
	while (flag > 0) /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
	{
		a ++;
		break;
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Complexity: while statement	(a == b)
 */
void dead_code_013 ()
{
	int flag = 1;
	int a = 0;
	int ret;
	while (flag == 0)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Dead Code*/
		break;
	}
	ret = a;
        sink = ret;
}

/*
 * Types of defects: dead code
 * Dead code main function
 */
extern volatile int vflag;
void dead_code_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		dead_code_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		dead_code_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		dead_code_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		dead_code_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		dead_code_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		dead_code_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		dead_code_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		dead_code_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		dead_code_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		dead_code_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		dead_code_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		dead_code_012();
	}

	if (vflag ==13 || vflag ==888)
	{
		dead_code_013();
	}
}
