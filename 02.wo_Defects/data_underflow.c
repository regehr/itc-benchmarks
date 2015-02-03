/********Software Analysis - FY2013*************/
/*
* File Name: data_underflow.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Data underflow
* Description: Defect Free Code to identify false positives in data underflow in static declaration
*/
#include "HeaderFile.h"
/*
 * Types of defects: underflow
 * Complexity: int	Underflow is with -2	Constant
 */
void data_underflow_001 ()
{
	int min = -2147483646;	/* 0x80000001 */
	int ret;
	ret = min - 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: unsigned int	Underflow with -1	Constant
 */
void data_underflow_002 ()
{
	unsigned int min = 1;
	unsigned int ret;
	ret = min - 1; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Underflow with decrement operator --
 */
void data_underflow_003 ()
{
	int min = -2147483646;	/* 0x80000002 */
	int ret;
	min --;
	min --;
	ret = min; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	-128 At the underflow	Constant
 */
void data_underflow_004 ()
{
	int min = -2147483520;
	int ret;
	ret = min - 128; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Multiply by underflow	Constant
 */
void data_underflow_005 ()
{
	int min = -1073741824;	/* 0xc0000000 */
	int ret;
	ret = min * 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: the operands is a constant
 */
void data_underflow_006 ()
{
	int ret;
	ret = (-2147483646) - 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: floating point underflow ( float )
 */
void data_underflow_007 ()
{
	float ret;

	/* 0 00000000 00000000000000000000010 */
	float min = 2.80259693e-45F;

	ret = min / 2.0F; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: floating point underflow (double)
 */
void data_underflow_008 ()
{
	double ret;

	/* 0 00000000000 0000000000000000000000000000000000000000000000000010 */
	double min = 9.8813129168249309e-324;

	ret = min / 2.0; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity:  underflow (char)
 */
void data_underflow_009 ()
{
	char min = -126;	/* 0x80000002 */
	char ret;
	ret = min - 2; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Underflow at The return value of the function
 */
int data_underflow_010_func_001 ()
{
	return 2;
}

void data_underflow_010 ()
{
	int min = -2147483646;
	int ret;
	ret = min - data_underflow_010_func_001(); /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Complexity: int	Underflow at Function arguments
 */
void data_underflow_011_func_001 (int d)
{
	int min = -2147483646;
	int ret;
	ret = min - d; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

void data_underflow_011 ()
{
	data_underflow_011_func_001(2);
}

/*
 * Types of defects: Underflow
 * Complexity: int	underflow at	An array of element values
 */
void data_underflow_012 ()
{
	int min = -2147483646;
	int dlist[4] = {0, 1, -2, -1};
	int ret;
	ret = min - dlist[2]; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}

/*
 * Types of defects: underflow
 * Data underflow main function
 */
extern volatile int vflag;
void data_underflow_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		data_underflow_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		data_underflow_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		data_underflow_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		data_underflow_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		data_underflow_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		data_underflow_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		data_underflow_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		data_underflow_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		data_underflow_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		data_underflow_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		data_underflow_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		data_underflow_012();
	}
}
