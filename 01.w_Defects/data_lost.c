/********Software Analysis - FY2013*************/
/*
* File Name: data_lost.c
* Defect Classification
* ---------------------
* Defect Type: Numerical defects
* Defect Sub-type: Integer precision lost because of cast
* Description: Defect Code to identify defects in data lost at cast
*/

int rand (void);
#include "HeaderFile.h"
/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: char	-> short	Variable
 */
void data_lost_001 ()
{
	char ret;
	short a = 0x80;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: short-> int	Variable
 */
void data_lost_002 ()
{
	short ret;
	int a = 0x8000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	long	Variable
 */
void data_lost_003 ()
{
	short ret;
	long a = 0x8000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: int	float	Variable
 */
void data_lost_004 ()
{
	int ret;
	float a = 2.14748365e+09F; /* 0x80000000 */
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a long	float	Variable
 */
void data_lost_005 ()
{
	long ret;
	float a = 2.14748365e+09F; /* 0x80000000 */
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: float	double	Variable
 */
void data_lost_006 ()
{
	float ret;	/* MAX:2^127 * (2 - 2^(-23)) */
	double a = 3.4028235677973366e+38;	/* 2^127 * (2 - 2^(-24)) */
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: unsigned char	unsigned short	Variable
 */
void data_lost_007 ()
{
	unsigned char ret;
	unsigned short a = 0x0100;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: unsigned short	unsigned int	Variable
 */
void data_lost_008 ()
{
	unsigned short ret;
	unsigned int a = 0x00010000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: unsigned short	unsigned long	Variable
 */
void data_lost_009 ()
{
	unsigned short ret;
	unsigned long a = 0x00010000;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: ( signed) bitfield	( signed) bit field	Variable
 */
typedef struct {
	signed int ret : 5;
	signed int a : 7;
} data_lost_010_s_001;

void data_lost_010 ()
{
	data_lost_010_s_001 s;
	s.a = 0x1f;
	s.ret = s.a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	Constant
 */
void data_lost_011 ()
{
	short ret;
	ret = 0x8000;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	Value of random variable
 */
void data_lost_012 ()
{
	short ret;
	int a;
	a = rand();
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	Linear equation
 */
void data_lost_013 ()
{
	short ret;
	int a = 129;
	ret = (254 * a) + 2;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	Nonlinear equation
 */
void data_lost_014 ()
{
	short ret;
	int a = 181;
	ret = (a * a) + 7;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	The return value of the function
 */
int data_lost_015_func_001 ()
{
	return 0x8000;
}

void data_lost_015 ()
{
	short ret;
	ret = data_lost_015_func_001();/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	Function arguments
 */
void data_lost_016_func_001 (int a)
{
	short ret;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

void data_lost_016 ()
{
	data_lost_016_func_001(0x8000);
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	An array of element values
 */
void data_lost_017 ()
{
	short ret;
	int buf[5] = {0x0111, 0x0001, 0x0011, 0x8000, 0x1111};
	ret = buf[3];/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: from the large size of the data type's assignment problem to small
 * Complexity: a short	int	Alias for 1 weight
 */
void data_lost_018 ()
{
	short ret;
	int a = 0x8000;
	int a1;
	a1 = a;
	ret = a1;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * Complexity: a short	int	- double alias
 */
void data_lost_019 ()
{
	short ret;
	int a = 0x8000;
	int a1;
	int a2;
	a1 = a;
	a2 = a1;
	ret = a2;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}

/*
 * Types of defects: assignment from large to small size data type - data lost  problem
 * data lost main function
 */
extern volatile int vflag;
void data_lost_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		data_lost_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		data_lost_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		data_lost_003();
	}

	if (vflag ==4 || vflag ==888)
	{
		data_lost_004();
	}

	if (vflag ==5 || vflag ==888)
	{
		data_lost_005();
	}

	if (vflag ==6 || vflag ==888)
	{
		data_lost_006();
	}

	if (vflag ==7 || vflag ==888)
	{
		data_lost_007();
	}

	if (vflag ==8 || vflag ==888)
	{
		data_lost_008();
	}

	if (vflag ==9 || vflag ==888)
	{
		data_lost_009();
	}

	if (vflag ==10 || vflag ==888)
	{
		data_lost_010();
	}

	if (vflag ==11 || vflag ==888)
	{
		data_lost_011();
	}

	if (vflag ==12 || vflag ==888)
	{
		data_lost_012();
	}

	if (vflag ==13 || vflag ==888)
	{
		data_lost_013();
	}

	if (vflag ==14 || vflag ==888)
	{
		data_lost_014();
	}

	if (vflag ==15 || vflag ==888)
	{
		data_lost_015();
	}

	if (vflag ==16 || vflag ==888)
	{
		data_lost_016();
	}

	if (vflag ==17 || vflag ==888)
	{
		data_lost_017();
	}

	if (vflag ==18 || vflag ==888)
	{
		data_lost_018();
	}

	if (vflag ==19 || vflag ==888)
	{
		data_lost_019();
	}
}
