/********Software Analysis - FY2013*************/
/*
* File Name: zero_division.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Division by zero
* Description: Defect Free Code to identify false positives to identify the division by zero functionality
*/

#include "HeaderFile.h"
int rand (void);

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Constant
 */
void zero_division_001 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / 1; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/ =)	Basic type	int	Constant
 */
void zero_division_002 ()
{
	int dividend = 1000;
	int ret;
	dividend /= 1; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
	ret = dividend;
}

/*
 * Types of defects: divide by zero
 * Complexity: calculation of retained earnings (%)	Basic type	int	Constant
 */
void zero_division_003 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend % 1; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: the remainder calculation (% =)	Basic type	int	Constant
 */
int zero_division_004_dividend_gbl = 1000;
static int zero_division_004_divisor_gbl = 11;
void zero_division_004_func_001 ()
{
	zero_division_004_dividend_gbl %= zero_division_004_divisor_gbl; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
void zero_division_004 ()
{

	zero_division_004_divisor_gbl--;
	zero_division_004_func_001 ();

}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	1-Dimensional array	int	An array of element values
 */
void zero_division_005 ()
{
	int dividend = 1000;
	int divisors[5] = {2, 1, 3, 0, 4};
	int ret;
	ret = dividend / divisors[2]; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	1 Heavy pointer	int	Variable
 */
int zero_division_006_gbl_divisor = 1;
void zero_division_006 ()
{
	int dividend = 1000;

	int *p;
	int ret;
	p = &zero_division_006_gbl_divisor;
	ret = dividend / *p; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Structure of the	int	Variable
 */
typedef struct {
	int a;
	int b;
	int divisor;
} zero_division_007_s_001;

zero_division_007_s_001 zero_division_007_s_gbl;

void zero_division_007_func_001 ()
{
	zero_division_007_s_gbl.divisor = 1;
}

void zero_division_007 ()
{
	int dividend = 1000;
	int ret;
	zero_division_007_func_001();
	ret = dividend / zero_division_007_s_gbl.divisor; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	float	Constant
 */
void zero_division_008 ()
{
	float dividend = 1000.0;
	float ret;
	ret = dividend / 1.0; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Variable
 */
void zero_division_009 ()
{
	int dividend = 1000;
	int divisor = 1;
	int ret;
	ret = dividend / divisor; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Value of random variable
 */
void zero_division_010 ()
{
	int dividend = 1000;
	int divisor;
	int ret;
	divisor = rand();
	if (divisor != 0)
	{
		ret = dividend / divisor; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
	}
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Linear equation
 */
void zero_division_011 ()
{
	int dividend = 1000;
	int divisor = 2;
	int ret;
	ret = dividend / (2 * divisor - 3); /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Nonlinear equation
 */
void zero_division_012 ()
{
	int dividend = 1000;
	int divisor = 2;
	int ret;
	ret = dividend / (divisor * divisor - 3); /*Tool should not detect this line as error*/ /* No ERROR:division by zero */

}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	The return value of the function
 */
int zero_division_013_func_001 ()
{
	return 1;
}

void zero_division_013 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / zero_division_013_func_001(); /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Function arguments
 */
void zero_division_014_func_001 (int divisor)
{
	int dividend = 1000;
	int ret;
	ret = dividend / divisor; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

void zero_division_014 ()
{
	zero_division_014_func_001(1);
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Alias for 1 weight
 */
void zero_division_015 ()
{
	int dividend = 1000;
	int divisor = 1;
	int divisor1;
	int ret;
	divisor1 = divisor;
	ret = dividend / divisor1; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Also known as double Alias
 */
int *zero_division_016_gbl_divisor ;
void zero_division_016_func_001 ()
{
	zero_division_016_gbl_divisor = malloc(1*sizeof(int));
	*zero_division_016_gbl_divisor= 1;
}
void zero_division_016_func_002 ()
{
	(*zero_division_016_gbl_divisor)++;
}
void zero_division_016 ()
{
	int dividend = 1000;
	int divisor1;
	int divisor2;
	int ret;
	zero_division_016_func_001 ();
	zero_division_016_func_002 ();
	divisor1 = *zero_division_016_gbl_divisor;
	divisor2 = divisor1;
	ret = dividend / divisor2; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * divide by zero main function
 */
extern volatile int vflag;
void zero_division_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		zero_division_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		zero_division_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		zero_division_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		zero_division_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		zero_division_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		zero_division_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		zero_division_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		zero_division_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		zero_division_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		zero_division_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		zero_division_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		zero_division_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		zero_division_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		zero_division_014();
	}

	if (vflag == 15 || vflag ==888)
	{
		zero_division_015();
	}

	if (vflag == 16 || vflag ==888)
	{
		zero_division_016();
	}
}
