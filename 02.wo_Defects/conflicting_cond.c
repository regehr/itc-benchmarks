/********Software Analysis - FY2013*************/
/*
* File Name: conflicting_cond.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Contradict conditions
* Description: Defect Free Code to identify false positives occurring in contradicting conditions
*/
#include "HeaderFile.h"
int rand (void);

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	(a==0&&a==1)
 */
void conflicting_cond_001 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ((a == 0) || (a == 1)) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	(a<5&&10<a)
 */
void conflicting_cond_002 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (! ((a < 5) || (10 < a))) /*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	((0<a&&a<2)&&(8<a&&a<10))
 */
void conflicting_cond_003 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (((0 < a) && (a < 2)) || ((8 < a) && (a < 10)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the if statement	nested if statement if (a < 5) if(10<a)�j
 */
void conflicting_cond_004 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 5)
	{
		a += 10;
		if (10 < a)/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
		{
			b += a;
		}
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: conditional operator	(a==0&&a==1)
 */
void conflicting_cond_005 ()
{
	int a;
	int b;
	int ret;

	a = rand();
	b = ((a == 0) || (a == 1)) ? 0 : 1;/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: the for statement	(a==0&&a==1)
 */
void conflicting_cond_006 ()
{
	int a;
	int b = 0;
	int ret;

	for (a = 0; (a == 0) || (a == 1); a ++)/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	(a==0&&a==1)
 */
void conflicting_cond_007 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a == 0) || (a == 1))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	(a<5&&10<a)
 */
void conflicting_cond_008 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (! ((a < 5) || (10 < a)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: while statement	((0<a&&a<2)&&(8<a&&a<10))
 */
void conflicting_cond_009 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (((0 < a) && (a < 2)) || ((8 < a) && (a < 10)))/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * Complexity: do-while statement	(a==0&&a==1)
 */
void conflicting_cond_010 ()
{
	int a;
	int ret;

	do
	{
		a = rand();
	}
	while ((a == 0) || (a == 1));/*Tool should Not detect this line as error*/ /*No ERROR:contradict condition*/
	ret = a;
        sink = ret;
}

/*
 * Types of defects: contradict condition
 * contradict condition - main function
 */
extern volatile int vflag;
void conflicting_cond_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		conflicting_cond_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		conflicting_cond_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		conflicting_cond_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		conflicting_cond_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		conflicting_cond_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		conflicting_cond_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		conflicting_cond_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		conflicting_cond_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		conflicting_cond_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		conflicting_cond_010();
	}
}
