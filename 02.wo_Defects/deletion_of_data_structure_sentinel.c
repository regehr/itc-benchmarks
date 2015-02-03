/********Software Analysis - FY2013*************/
/*
* File Name: deletion_of_data_structure_sentinel.c
* Defect Classification
* ---------------------
* Defect Type: Dynamic memory defects
* Defect Sub-type: Deletion of data structure sentinel
* Description: Defect Free Code to identify false positives while deletion of data structure sentinel
*/

#include "HeaderFile.h"

/*
* Types of defects: Deletion of a data structure sentinel
* Complexity: Not leaving a place for '\0' which is the terminator for the string.
*/

void deletion_of_data_structure_sentinel_001()
{
	char* foo;
	int counter;
	foo=calloc(11,sizeof(char));
	for(counter=0;counter<10;counter++)
	{
		foo[counter]='a'; /*Tool should Not detect this line as error*/ /*No ERROR:Deletion of a data structure sentinel*/
	}
	foo[counter]='\0';
	free(foo);
}

/*
* Types of defects: Deletion of a data structure sentinel
* Complexity: Not leaving a place for '\0' which is the 
* terminator for the string using memcpy function.
*/

void deletion_of_data_structure_sentinel_002()
{
	char str1[]="This is a string";
	char str[17];
	memcpy(str,str1,strlen(str1)+1);/*Tool should Not detect this line as error*/ /*No ERROR:Deletion of a data structure sentinel*/
}

/*
* Types of defects: Deletion of a data structure sentinel
* Complexity: Not leaving a place for '\0' which is the 
* terminator for the string using memcpy function using a constant.
*/

void deletion_of_data_structure_sentinel_003()
{
	int i;
	char str[17];
	char ptr[11];
		
	for(i=0;i<10;i++)
	{
		ptr[i]='a';
	}
	
	ptr[i]='\0';
	memcpy(str,ptr,11);/*Tool should Not detect this line as error*/ /*No ERROR:Deletion of a data structure sentinel*/
}

extern int vflag;
void deletion_of_data_structure_sentinel_main()
{
	if (vflag ==1 || vflag ==888)
	{
		deletion_of_data_structure_sentinel_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		deletion_of_data_structure_sentinel_002();
	}

	if (vflag ==3 || vflag ==888)
	{
		deletion_of_data_structure_sentinel_003();
	}

}
