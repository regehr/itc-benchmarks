/********Software Analysis - FY2013*************/
/*
* File Name: function_return_value_unchecked.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Return value of function never checked
*
*/

/*
 * function_return_value_unchecked.c
 *
 *  Created on: Oct 2, 2013
 *      Author: hemalatha
 */

#include "HeaderFile.h"

/*
* Types of defects: Return value of function never checked
* Complexity: Value returned to the calling function is assigned to a variable but never used after that
*/
int function_return_value_unchecked_001_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=flag++;
   return ret;
}
int function_return_value_unchecked_001_func_002(int flag)
{
	int temp;
	temp = function_return_value_unchecked_001_func_001(flag);
	if (temp > 0)
	{
		temp = temp+50;
	}
	else
		temp = 0;
		return temp;
}
void function_return_value_unchecked_001 ()
{
	int a;
	a = function_return_value_unchecked_001_func_002(1);/*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
		a++;
}

/*
* Types of defects: Return value of function never checked
* Complexity: Value returned to the calling function is never assigned to variable/unchecked
*/
float function_return_value_unchecked_002_func_001(int flag)
{
   float ret =1.0;
   while(flag>0)
   {
	   ret++;
	   flag--;
   }
   return ret;
}
void function_return_value_unchecked_002 ()
{
	float a=0.0;
	function_return_value_unchecked_002_func_001(10);     /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    if (a >0)
    	a--;
}

/*
* Types of defects: Return value of function never checked
* Complexity: Return value evaluated only in a if conditional statement
*/
char function_return_value_unchecked_003_func_001(void)
{
	char str1 = 'a';
	return str1;
 }
void function_return_value_unchecked_003 ()
{
	int a=1;
	char buf = function_return_value_unchecked_003_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	a--;
	if (a!=0)
	{
		if(buf != '\0')
			printf("%c\n",buf);
	}
}

/*
* Types of defects: Return value of function never checked
* Complexity: Return value evaluated only in a switch case statement , evaluated using string compare function
*/
typedef struct {
	char a[20];
	int b;
} function_return_value_unchecked_004_s_001;


function_return_value_unchecked_004_s_001  function_return_value_unchecked_004_s_001_func_001 ()
{
	function_return_value_unchecked_004_s_001 s1;
	strcpy(s1.a, "STRING");
    s1.b = 20;
    return s1;
}

void function_return_value_unchecked_004 ()
{
	function_return_value_unchecked_004_s_001 s;
    s= function_return_value_unchecked_004_s_001_func_001();/*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    int flag = 10;
	switch (flag)
	{
		case 1:
		{
			if( (strcmp(s.a,"STRING") ==0) )
				s.b++;
			break;
		}
		case 2:
		{
			if( (strcmp(s.a,"STRING1") >0) )
				s.b++;
			break;
		}
		case 3:
		{
			if(s.b <=20)
				s.b--;
			break;
		}
		default:
		{
			break;
		}
	}
}

/*
* Types of defects: Return value of function never checked
* Complexity: Function called in a for loop but only one return value evaluated in a if condition
*/
typedef struct {
	float c;
	char *a;
	int b;
} function_return_value_unchecked_005_s_001;


function_return_value_unchecked_005_s_001   function_return_value_unchecked_005_s_001_func_001 ()
{
	function_return_value_unchecked_005_s_001 u1;
	char *s ="This is STR";
    u1.a = s;
    u1.b = 20;
    u1.c = 30.5;
    return u1;
}
void function_return_value_unchecked_005 ()
{
	function_return_value_unchecked_005_s_001 u ;
	int i;
	for(i=0;i<10;i++)
	{
		u = function_return_value_unchecked_005_s_001_func_001();/*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
        if (i==5)
       	if(u.b >0)
        		u.c= 60.5;
	}
}

/*
* Types of defects: Return value of function never checked
* Complexity: Function called in a while loop but only one return value De-referencing  evaluated outside while loop.
*/
float (*function_return_value_unchecked_006_func_001())[4]
{
	float (*p)[4];
	int i,j;
	float arr[4][4];
	p= (float (*)[]) calloc (1,sizeof(arr));
    if(p!=NULL)
    {
       memset(p, 1.00, 16);
    }
    if(p!=NULL)
    {
    	for (i = 0;i< 4; i++)
    	{
		   for ( j=0 ;j<4; j++)
		   {
		       *(p[i]+j) += (i+j);
		   }
	   }
    }
	return p;
}

void function_return_value_unchecked_006 ()
{
	float (*ptr)[4];
	int i=10,j=0;
	while (i>0)
	{
		ptr = function_return_value_unchecked_006_func_001();/*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
		for(;(j!=0 && j<4);j++)
		{
	        if(*(ptr[j]) >0)
	        {
	        	*(ptr[j]+1) += i;
	        }
		}
		free(ptr);
	    i--;
	}

}

/*
* Types of defects: Return value of function never checked
* Complexity: Data type of the Returned value and the variable in which it is assigned is different.
*/

float function_return_value_unchecked_007_func_001()
{
	float ret = 10.034;
	return (ret);
}
void function_return_value_unchecked_007 ()
{

	int i=function_return_value_unchecked_007_func_001();/*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	//if (i<10)
		i++;
}

/*
* Types of defects: Return value of function never checked
* Complexity: Data type of the Returned value and the variable in which it is assigned is different.
* Parameters passed is different from function definition
*/
double function_return_value_unchecked_008_func_001(int a)
{
	double ret = 9.034;
	ret += a;
	return (ret);
}
void function_return_value_unchecked_008 ()
{
	int i=function_return_value_unchecked_008_func_001(6.00); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
	//if (i<10)
		i++;
}
/*
* Types of defects: Return value of function never checked
* Complexity: Return more than once in the same function, which can lead to non-evaluation of one of the returned values
*/
double function_return_value_unchecked_009_func_001(double a[] , int max )
{
	double ret =0.0;
	int i;
	for (i=0;i<max;i++)
	ret += a[i];
	return (ret);
}

void function_return_value_unchecked_009 ()
{
    int a=10,b=2,c=0;
    double arr[] = {1.0,2.0,3.0,4.0};
    if(a == 20)
    {
    	if ( function_return_value_unchecked_009_func_001( arr, (sizeof (arr)/sizeof (double)) )  > a)
    		a++;
    }
    else if (b != 2)
    {
    	if ( function_return_value_unchecked_009_func_001( arr, (sizeof (arr)/sizeof (double)) )  < b)
    		b++;
    }
    else if (c >0)
    {
    	if ( function_return_value_unchecked_009_func_001( arr, (sizeof (arr)/sizeof (double)) )  == 0)
    		c ++;
    }
    else
    {
    	function_return_value_unchecked_009_func_001( arr, (sizeof (arr)/sizeof (double)) );    /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    		c ++;
    }
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using fprintf in a if condition with static variable
*/
# define MAX 10
static int function_return_value_unchecked_010_var = MAX;
void function_return_value_unchecked_010 ()
{
    int a = 10;
	if (function_return_value_unchecked_010_var == MAX)
    {
        fprintf(stdout, "%s\n", "TEST STRING");     /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
        {
            a++;
        }
    }
	else
        if (fprintf(stdout, "%s\n", "STRING") < 0)
        {
            a--;
        }
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using snprintf in a if condition with static variable
*/
#define STR "string"
void function_return_value_unchecked_011 ()
{
    int k;
    for(k = 0; k < 5; k++)
    {
    	char buf[100] = "";
        char * buf1 = buf;
        snprintf(buf1,100-strlen(STR)-1, "%s\n", STR);     /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    }
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using fputc function in a infinite while loop
*/
void function_return_value_unchecked_012 ()
{
    while(1)
    {
         fputc((int)'A', stdout);     /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
         break;
    }
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using fputs function inside a if condition evaluated with function return value
*/
int function_return_value_unchecked_013_func_001()
{
	return (1);
}

void function_return_value_unchecked_013 ()
{
    if(function_return_value_unchecked_013_func_001())
    {
        fputs("STRING#", stdout);    /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    }
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using a putchar function in a goto label
*/
void function_return_value_unchecked_014 ()
{
	int a=10;
    goto label;
label:
    putchar((int)'A');    /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
    a++;
}

/*
* Types of defects: Return value of function never checked
* Complexity: When using a puts function in switch case
*/
void function_return_value_unchecked_015 ()
{
    int flag =6,i=10;
	switch(flag)
    {
    case 6:
        puts("TEST");    /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
        {
        	i=20;
        }
        break;
    default:
        {
        	i=10;
            break;
        }
    }
}

/*
* Types of defects: Return value of function never checked
* Complexity: Function called in a for loop but only one return value evaluated in a if condition and all elements of structure is evaluated
*/
typedef struct {
	float c;
	char *a;
	int b;
} function_return_value_unchecked_016_s_001;


function_return_value_unchecked_016_s_001   function_return_value_unchecked_016_s_001_func_001 ()
{
	function_return_value_unchecked_016_s_001 u1;
	char *s ="This is STR";
    u1.a = s;
    u1.b = 20;
    u1.c = 30.5;
    return u1;
}
void function_return_value_unchecked_016 ()
{
	function_return_value_unchecked_016_s_001 u ;
	int i=0;
	for(;i<10;i++)
	{
		u = function_return_value_unchecked_016_s_001_func_001(); /*Tool should detect this line as error*/ /*ERROR:Return value of function never checked*/
       	if(i!=3)
		{
		    if(u.b >0 && u.a !=NULL && u.c != 0)
        		   u.c= 60.5;
		}
	}
}
/*
* Types of defects: Return value of function never checked
* Complexity:Return value of function never checked main function
*/
extern volatile int vflag;
void function_return_value_unchecked_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		function_return_value_unchecked_001 ();
	}

	if (vflag == 2 || vflag ==888)
	{
		function_return_value_unchecked_002 ();
	}

	if (vflag == 3 || vflag ==888)
	{
		function_return_value_unchecked_003 ();
	}

	if (vflag == 4 || vflag ==888)
	{
		function_return_value_unchecked_004 ();
	}

	if (vflag == 5 || vflag ==888)
	{
		function_return_value_unchecked_005 ();
	}

	if (vflag == 6 || vflag ==888)
	{
		function_return_value_unchecked_006 ();
	}

	if (vflag == 7 || vflag ==888)
	{
		function_return_value_unchecked_007 ();
	}

	if (vflag == 8 || vflag ==888)
	{
		function_return_value_unchecked_008 ();
	}

	if (vflag == 9 || vflag ==888)
	{
		function_return_value_unchecked_009 ();
	}

	if (vflag == 10 || vflag ==888)
	{
		function_return_value_unchecked_010 ();
	}

	if (vflag == 11 || vflag ==888)
	{
		function_return_value_unchecked_011 ();
	}

	if (vflag == 12 || vflag ==888)
	{
		function_return_value_unchecked_012 ();
	}

	if (vflag == 13 || vflag ==888)
	{
		function_return_value_unchecked_013 ();
	}

	if (vflag == 14 || vflag ==888)
	{
		function_return_value_unchecked_014 ();
	}

	if (vflag == 15 || vflag ==888)
	{
		function_return_value_unchecked_015 ();
	}

	if (vflag == 16 || vflag ==888)
	{
		function_return_value_unchecked_016 ();
	}
}

