/********Software Analysis - FY2013*************/
/*
* File Name: improper_error_handling.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Improper error handling
* Description: Defect Free Code to identify false positives in improper try..catch error handling
*/
#include "HeaderFile.hpp"
/*
* Types of defects: Improper error handling
* Complexity: No throw function in a try catch block
*/

void improper_error_handling_001()
{
	try {
		int a=0,b=9,c;
		if (a==0)
		throw(a);

		c=b/a;
	}
	catch(int a)
	{
		printf("Error1: a is equal to 0 %d  \n",a);
		//exit(1);
	}
}

/*
* Types of defects: Improper error handling
* Complexity: Improper error handling due to no code presence in catch
*/

void improper_error_handling_002()
{
	try {
		int a=0,b=9,c;
		if (a==0) 
			throw(a);

		c=b/a;
	}
	catch(int a)
	{
		printf("Error2: a is equal to 0 %d  \n",a);
		//exit(1);
	}

}

/*
* Types of defects: Improper error handling
* Complexity: Different datatypes in throw and catch statement
*/

void improper_error_handling_003()
{
	try {
		float a=0.0,b=9.0,c;
		if (a==0.0)
			 throw(a);

		c=b/a;
	}
	catch(float a)
	{
		printf("Error3: a is equal to 0 %f  \n",a);
		//exit(1);
	}

}

/*
* Types of defects: Improper error handling
* Complexity: Different datatypes in throw and catch in a nested try catch block
*/

void improper_error_handling_004()
{
	try
	{
		try {
			float a=0.0,b=9.0,c;

			if (a==0.0) 
				throw(a);

			c=b/a;
		}
		catch(float a)
		{
			throw a;
		}
	}
	catch(float a)
	{
		printf("Error4: a is equal to 0 %f  \n",a);
		exit(1);
	}

}

/*
*
*/
extern volatile int vflag;
void improper_error_handling_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		improper_error_handling_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		improper_error_handling_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		improper_error_handling_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		improper_error_handling_004();
	}
}
