/********Software Analysis - FY2013*************/
/*
* File Name: free_nondynamic_allocated_memory.c
* Defect Classification
* ---------------------
* Defect Type: Resource management defects
* Defect Sub-type: Free non dynamically allocated memory
* Description: Defect Free Code to identify false positives while freeing non dynamically allocated memory
*/

#include "HeaderFile.h"

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Constant if statement
*/

void free_nondynamic_allocated_memory_001()
{
	char* ptr="a";
	if(0)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Variable if statement
*/

void free_nondynamic_allocated_memory_002()
{
	char* ptr="a";;
	int flag=1;
	if(flag>1)
	free(ptr);  /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: global Inside same  function
*/
char *free_nondynamic_allocated_memory_003_gbl_ptr;

void free_nondynamic_allocated_memory_003()
{
	free_nondynamic_allocated_memory_003_gbl_ptr = malloc(sizeof(char));
	free(free_nondynamic_allocated_memory_003_gbl_ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}


/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Double pointers
*/

void free_nondynamic_allocated_memory_004()
{
	char* ptr1="a";
	char** ptr=&ptr1;
	while(0)
	free(ptr);  /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Array of pointers
*/

void free_nondynamic_allocated_memory_005()
{
	char *buf1=(char*)calloc(5,sizeof(char));
	char *buf2=(char*)calloc(5,sizeof(char));
	char **pbuf[2] = {&buf1, &buf2};
	int i,j=1;
	if(buf2 != NULL)
	{
	    buf2[0] = 10.0;
	}
	for(i=0;i<2;i++)
	{
		*((*pbuf[i])+j)=5.0;
	}
	free(buf1);
	free(buf2); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Free pointer to different data types
*/

void free_nondynamic_allocated_memory_006()
{
	char* ptr1=malloc(sizeof(char));
	int* ptr2=malloc(sizeof(int));
	float* ptr3=malloc(sizeof(float));
	double* ptr4=malloc(sizeof(double));

	free(ptr1);
	free(ptr2);
	free(ptr3);
	free(ptr4); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a constant while loop
*/

void free_nondynamic_allocated_memory_007()
{
	char* ptr="a";
	while(0)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a variable while loop which leads to dead code
*/

void free_nondynamic_allocated_memory_008()
{
	char* ptr="b";
	int a=2,b=0;
	while(a<b)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a variable while loop
*/

void free_nondynamic_allocated_memory_009()
{
	char* ptr="c";
	int a=0,b=2;
	while(a>b)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a for loop
*/

void free_nondynamic_allocated_memory_010()
{
	int i;
	for(i=0;i<1;i++)
	{
		char* ptr="g";
		printf("%s",ptr);
		/*free(ptr);*/ /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	}
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a for loop
*/

void free_nondynamic_allocated_memory_011()
{
	int i;
	for(i=0;i<0;i++)
	{
		char* ptr="z";
		free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	}
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: In a if condition statement inside a while loop
*/

void free_nondynamic_allocated_memory_012()
{
	char* ptr="a";
	int a=0,b=2;
	while(a<b)
	{
		a++;
		if(a==5)
		free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	}
}


/*
* Types of defects: Free memory not allocated dynamically
* Complexity: free a structure pointer inside a structure
*/

typedef struct node
{
	int a;
	struct node * next;

}free_nondynamic_allocated_memory_struct_013;

void free_nondynamic_allocated_memory_013()
{
	free_nondynamic_allocated_memory_struct_013* new_struct=malloc(sizeof(free_nondynamic_allocated_memory_struct_013));

	new_struct->next = malloc(sizeof(free_nondynamic_allocated_memory_struct_013));
	free(new_struct->next); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	free(new_struct);
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: free a global structure pointer
*/

typedef struct node1
{
	int a;
	struct node1* next;

}free_nondynamic_allocated_memory_struct_014;
free_nondynamic_allocated_memory_struct_014 * free_nondynamic_allocated_memory_str ;
void free_nondynamic_allocated_memory_014()
{
	free_nondynamic_allocated_memory_str = malloc(sizeof(free_nondynamic_allocated_memory_struct_014));
	free(free_nondynamic_allocated_memory_str); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Global variable , freed in another In a function
*/
char *free_nondynamic_allocated_memory_015_gbl_ptr;
void free_nondynamic_allocated_memory_015_func_001()
{
	free(free_nondynamic_allocated_memory_015_gbl_ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

void free_nondynamic_allocated_memory_015()
{
	free_nondynamic_allocated_memory_015_gbl_ptr = malloc(sizeof(char));
	free_nondynamic_allocated_memory_015_func_001();
}

/*
* Types of defects: Free memory not allocated dynamically
* Complexity: Global variable , variable set in another In a function
*/
char *free_nondynamic_allocated_memory_016_gbl_ptr;
char free_nondynamic_allocated_memory_016_gbl_var;
void free_nondynamic_allocated_memory_016_func_001()
{
	free_nondynamic_allocated_memory_016_gbl_ptr = malloc(sizeof(char));
}

void free_nondynamic_allocated_memory_016_func_002()
{
	if(free_nondynamic_allocated_memory_016_gbl_var =='A')
	   free(free_nondynamic_allocated_memory_016_gbl_ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}

void free_nondynamic_allocated_memory_016()
{
	free_nondynamic_allocated_memory_016_gbl_var = 'A';
	free_nondynamic_allocated_memory_016_func_001();
	free_nondynamic_allocated_memory_016_func_002();
}

/*
* Types of defects: Free memory not allocated dynamically
* Free memory not allocated dynamically main function
*/
extern volatile int vflag;
void free_nondynamic_allocated_memory_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		free_nondynamic_allocated_memory_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		free_nondynamic_allocated_memory_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		free_nondynamic_allocated_memory_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		free_nondynamic_allocated_memory_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		free_nondynamic_allocated_memory_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		free_nondynamic_allocated_memory_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		free_nondynamic_allocated_memory_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		free_nondynamic_allocated_memory_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		free_nondynamic_allocated_memory_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		free_nondynamic_allocated_memory_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		free_nondynamic_allocated_memory_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		free_nondynamic_allocated_memory_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		free_nondynamic_allocated_memory_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		free_nondynamic_allocated_memory_014();
	}

	if (vflag == 15 || vflag ==888)
	{
		free_nondynamic_allocated_memory_015();
	}

	if (vflag == 16 || vflag ==888)
	{
		free_nondynamic_allocated_memory_016();
	}
}
