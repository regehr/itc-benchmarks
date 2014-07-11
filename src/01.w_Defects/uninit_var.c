/********Software Analysis - FY2013*************/
/*
* File Name: uninit_var.c
* Defect Classification
* ---------------------
* Defect Type: Misc defects
* Defect Sub-type: Uninitialized variable
* Description: Defect code to identify uninitialized variable in a code flow
*/


#include "HeaderFile.h"

/*
 * Types of defects: uninitialized variable
 * Complexity: basic types	int	Variable	Loading
 */
void uninit_var_001 ()
{
	int a ;
	int ret;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: 1-dimensional array	int	Variable	Loading
 */
void uninit_var_002 ()
{
	int buf[5];
	int ret;
	ret = buf[3];/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: 2-dimensional array	int	Variable	Loading
 */
void uninit_var_003 ()
{
	int buf[5][6];
	int ret;
	ret = buf[1][1];/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: Double variable initialized based on constant
 */
static const int UNINIT_VAR_004_TRUE = 1; /* true */
static const int UNINIT_VAR_004_FALSE = 0; /*false */
void uninit_var_004 ()
{
	float dvar,dvar1,ret;
    if(UNINIT_VAR_004_TRUE ==0)
    	dvar = 10.0;
    else if (UNINIT_VAR_004_FALSE !=0 )
    	dvar1 = 25.8;
    else
    	;
    ret = dvar;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: basic types	int	Function arguments	Loading
 */
int uninit_var_005_func_001 (void)
{
	int ret;
	if (0)
	ret = 1;
	return ret;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

void uninit_var_005 ()
{
	int a;
	a = uninit_var_005_func_001();
}

/*
 * Types of defects: uninitialized variable
 * Complexity: long variable initialized in a ternary conditional operator
 */
void uninit_var_006 ()
{
    long a;
    int flag =0;
    (flag==10)? (a = 1):(flag =a);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: structure Int Variable	Loading
 */
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_var_007_s_001;

void uninit_var_007 ()
{
	uninit_var_007_s_001 s;
	int ret;
	s.a = 1;
	s.b = 1;
	ret = s.uninit;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

/*
 * Types of defects: uninitialized variable
 * Complexity: Static Int variable initialized by return value of function with a condition in while loop
 */
int uninit_var_008_func_001 (int a)
{
	static int ret;
	ret -= a;
	return ret;
}

void uninit_var_008 ()
{
    int flag = 1;
    int data;
    while(uninit_var_008_func_001(flag)>0)
    {
    	data +=flag;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
    }
}

/*
 * Types of defects: uninitialized variable
 * Complexity: char array	Function arguments	Loading
 */
void uninit_var_009_func_001 (char buf[])
{
	char ret[25];
	strcpy(buf,ret);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

void uninit_var_009 ()
{
	char buf[25] ;
	uninit_var_009_func_001(buf);
}

/*
 * Types of defects: uninitialized variable
 * Complexity: 2-dimensional array	int	Function arguments	Loading
 */
void uninit_var_010_func_001 (int buf[][6])
{
	int ret[5][6];
	int i,j;
	for (i=0;i<5;i++)
		for (j=0;j<6;j++)
			buf[i][j] = ret[i][j];}/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/

void uninit_var_010 ()
{
	int buf[5][6];
	uninit_var_010_func_001(buf);
}

/*
 * Types of defects: uninitialized variable
 * Complexity: 1-dimensional array	int	Function arguments	Loading and
 * initialized with return value of function
 */
int uninit_var_011_func_001 (int arr1[],int a)
{
	int ret=0;
	if(arr1[0] > 0)
		ret = a+arr1[1];/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
		return ret ;
}

void uninit_var_011 ()
{
	int arr[5];
	int p ;
	p= uninit_var_011_func_001(arr,(sizeof(arr)/sizeof(int)));
}

/*
 * Types of defects: uninitialized variable
 * Complexity: Structure passed as function parameter and based on the return value of function another structure is initialized
 */
typedef struct {
	unsigned int a;
	unsigned int b;
	unsigned int uninit;
} uninit_var_012_s_001;

int uninit_var_012_func_001 (uninit_var_012_s_001 s1)
{
	switch ( (s1.a + s1.b +s1.uninit) )/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	{
		case 5:
		{
			return 5;
		}
		case 6:
		{
			return 6;
		}
		case 7:
		{
			return 7;
		}
		default:
			return -1;
	}
}

void uninit_var_012 ()
{
	uninit_var_012_s_001 s,r;
	s.a = 2;
	s.b = 1;
	int ret;
	ret = uninit_var_012_func_001 (s);
	if(ret >=0)
		r = s;
}

/*
 * Types of defects: uninitialized variable
 * Complexity: int variable initialized with function return value using enumeration
 */
typedef enum
            {ZERO,
	         ONE,
	         TWO } values;

int uninit_var_013_func_001 (void )
{
	values val ;/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	return val;
}

void uninit_var_013 ()
{
    int a;
    a = uninit_var_013_func_001();
}

/*
 * Types of defects: uninitialized variable
 * Complexity: structure int Function arguments	Loading
 */
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_var_014_s_001;

uninit_var_014_s_001 uninit_var_014_func_001 (uninit_var_014_s_001 s1)
{
	uninit_var_014_s_001 ret;
	ret.a = (++s1.a);
	ret.b = (++s1.b);
	ret.uninit = (++s1.uninit);/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	return ret;
}

void uninit_var_014 ()
{
	uninit_var_014_s_001 s,r;
	s.a = 1;
	s.b = 1;
	r = uninit_var_014_func_001(s);
}

/*
 * Types of defects: uninitialized variable
 * Complexity: Array initialized in a  function using macro's
 */
#define ZERO 0
#define ONE  1
#define TWO  2
void uninit_var_015_func_001 (int a[] )
{
	a[0] = ZERO;
	a[2] = TWO;
}

void uninit_var_015 ()
{
    int a[3],ret;
    uninit_var_015_func_001(a);
    ret = a[1];/*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
};


/*
 * Types of defects: uninitialized variable
 * uninitialized variable main function
 */
extern volatile int vflag;
void uninit_var_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		uninit_var_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		uninit_var_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		uninit_var_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		uninit_var_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		uninit_var_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		uninit_var_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		uninit_var_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		uninit_var_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		uninit_var_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		uninit_var_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		uninit_var_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		uninit_var_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		uninit_var_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		uninit_var_014();
	}

	if (vflag == 15 || vflag ==888)
	{
		uninit_var_015();
	}
}
