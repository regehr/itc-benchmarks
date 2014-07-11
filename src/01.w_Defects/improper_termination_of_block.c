/********Software Analysis - FY2013*************/
/*
* File Name: improper_termination_of_block.c
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Improper termination of block
*
*/

#include "HeaderFile.h"

/*
* Types of defects: Improper termination of block
* Complexity: Improper termination as only 1 statement after if statement is executed
*/

void improper_termination_of_block_001()
{
	int condition=0,x=0,y=0;
	
	if (condition==0) /*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	printf("%d",x);
	printf("%d",y);


}

/*
* Types of defects: Improper termination of block
* Complexity: Improper termination as only 1 statement after if statement is executed
*/

void improper_termination_of_block_002()
{
	int condition=0,x=0,y=0;
	
	if (condition==0);	printf("%d",x);/*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	printf("%d",y);

}

/*
* Types of defects: Improper termination of block
* Complexity: Improper termination as the semicolon causes for not to be executed in a loop
*/

void improper_termination_of_block_003()
{
	int x,y=0;
	
	for(x=0;x<10;x++);/*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	printf("%d",x);
	printf("%d",y);

}

/*
* Types of defects: Improper termination of block
* Complexity: Improper termination as only 1 statement after while statement is executed
*/

void improper_termination_of_block_004()
{
	int x=0,y=0;
	
	while(x<10);/*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	x++;
	printf("%d",x);
	printf("%d",y);

}

extern volatile int vflag;
void improper_termination_of_block_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		improper_termination_of_block_001 ();
	}

	if (vflag == 2 || vflag ==888)
	{
		improper_termination_of_block_002 ();
	}

	if (vflag == 3 || vflag ==888)
	{
		improper_termination_of_block_003 ();
	}

	if (vflag == 4 || vflag ==888)
	{
		improper_termination_of_block_004 ();
	}

}
