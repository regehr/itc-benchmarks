/********Software Analysis - FY2013*************/
/*
* File Name: not_return.c
* Defect Classification
* ---------------------
* Defect Type: Misc defects
* Defect Sub-type: Non void function does not return value
*
*/

#include "HeaderFile.h"
int rand (void);

/*
 * Type of defect: there is a path that does not return a return value
 * Complexity: if it contains if statements
 */
int not_return_001_func_001 (int flag)
{
	if (flag == 0)
	{
		return 0;
	}
} /*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_001 ()
{
	int ret;
	ret = not_return_001_func_001(rand());
        sink = ret;
}

/*
 * Type of defect: there is a path that does not return a return value
 * Complexity: if it contains nested if statements
 */
int not_return_002_func_001 (int flag1, int flag2)
{
	if (flag1 == 0)
	{
		if (flag2 == 0)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}/*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_002 ()
{
	int ret;
	ret = not_return_002_func_001(rand(), rand());
        sink = ret;
}

/*
 * Type of defect: there is a path that does not return a return value
 * Complexity: If it contains including switch
 */
int not_return_003_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
			return 0;
		case 2:
			break;
		case 3:
			return 0;
		default:
			return -1;
	}
}/*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_003 ()
{
	int ret;
	ret = not_return_003_func_001(rand());
        sink = ret;
}

/*
 * Type of defect: there is a path that does not return a return value
 * Complexity: if it contains the goto
 */
int not_return_004_func_001 (int flag)
{
	int ret = 0;
	if (flag == 0)
	{
		goto my_label;
	}
	return ret;
my_label:
	ret ++;
}/*Tool should detect this line as error*/ /*ERROR: No return value */

void not_return_004 ()
{
	int ret;
	ret = not_return_004_func_001(rand());
        sink = ret;
}

/*
 *Types of defects: there is a path that does not return a return value
 *Complexity: Not return main function
 */
extern volatile int vflag;
void not_return_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		not_return_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		not_return_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		not_return_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		not_return_004();
	}
}
