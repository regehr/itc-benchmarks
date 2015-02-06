/********Software Analysis - FY2013*************/
/*
* File Name: redundant_cond.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Redundant conditions
* Description: Defect Free Code to identify false positives in redundant condition
*/

#include "HeaderFile.h"

int rand (void);

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	(5<a&&10<a)
 */
void redundant_cond_001 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ( a < 10 ) /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	(a<5&&a<10)
 */
void redundant_cond_002 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 5) /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	((0<a&&a<10)&&(2<a&&a<8))
 */
void redundant_cond_003 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ( a < 10 ) /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	((0<a&&a<8)&&(5<a&&a<10))
 */
void redundant_cond_004 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if ( a < 10 )/*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	(5<a||10<a)
 */
void redundant_cond_005 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 10) /*Tool should detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the if statement	nested if statement ( if (a < 5) if(a<10))
 */
void redundant_cond_006 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	if (a < 10)  /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;

	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: conditional operator	(5<a&&10<a)
 */
void redundant_cond_007 ()
{
	int a;
	int b;
	int ret;

	a = rand();
	b = ((a < 10) ) ? 0 : 1;  /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: the for statement	(5<a&&10<a)
 */
void redundant_cond_008 ()
{
	int a;
	int b = 0;
	int ret;

	for (a = 20; 10 < a; a --)  /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: while statement	(5<a&&10<a)
 */
void redundant_cond_009 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (a < 10)  /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a --;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: while statement	(a<5&&a<10)
 */
void redundant_cond_010 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a < 5)) /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: while statement	((0<a&&a<10)&&(2<a&&a<8))
 */
void redundant_cond_011 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a < 8))  /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: while statement	((0<a&&a<8)&&(5<a&&a<10))
 */
void redundant_cond_012 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while (a < 10)/*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: while statement	(5<a||10<a)
 */
void redundant_cond_013 ()
{
	int a;
	int b = 0;
	int ret;

	a = rand();
	while ((a < 10))/*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
	{
		b += a;
		a --;
	}
	ret = b;
        sink = ret;
}

/*
 * Types of defects: redundant condition
 * Complexity: do-while statement	(5<a&&10<a)
 */
void redundant_cond_014 ()
{
  int a;
  int b = 0;
  int ret;

  a = rand();
  do {
    // JDR: cast to unsigned to avoid UB
    b += (unsigned)a;
    a --;
  }
  while (10 < a); /*Tool should not detect this line as error*/ /*No ERROR:Redundant condition*/
  ret = b;
  sink = ret;
}

/*
 * Types of defects: redundant condition
 * redundant condition main function
 */
extern volatile int vflag;
void redundant_cond_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		redundant_cond_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		redundant_cond_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		redundant_cond_003();
	}

	if (vflag ==4 || vflag ==888)	/* Without test cases */
	{
		redundant_cond_004();
	}

	if (vflag ==5 || vflag ==888)	/* Without test cases */
	{
		redundant_cond_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		redundant_cond_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		redundant_cond_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		redundant_cond_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		redundant_cond_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		redundant_cond_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		redundant_cond_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		redundant_cond_012();
	}

	if (vflag ==13 || vflag ==888)
	{
		redundant_cond_013();
	}

	if (vflag ==14 || vflag ==888)
	{
		redundant_cond_014();
	}
}
