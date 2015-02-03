/********Software Analysis - FY2013*************/
/*
* File Name: memory_leak.c
* Defect Classification
* ---------------------
* Defect Type: Resource management defects
* Defect Sub-type: Memory leakage
*
*/

#include "HeaderFile.h"

int rand (void);

/*
* Types of defects: Memory Leakage - Allocate Memory and not freeing it
* Complexity: When using a pointer to char in an infinite for loop
*/
void memory_leak_001 ()
{
	int i;
	char *buf;
	for (i=0;;i++)
	{
		buf=(char*) calloc(5,sizeof(char)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
		if(buf!=NULL)
		{
		buf[0]=1;
		/*if(i>=10) */
		}
		/*break;*/
	}
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 * When using double pointers to the type INT
 */

void memory_leak_002 ()
{
	int **ptr = (int**) malloc(5*sizeof(int*));
	int i,j;

	for(i=0;i<5;i++)
		ptr[i]=(int*) malloc(5*sizeof(int)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			*(*(ptr+i)+j)=i;
		}
	}
	free(ptr);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 *  Memory allocated in a function and Memory used in another function
 */
void memory_leak_003_func_001 (int len,char **stringPtr)
{
	char * p = malloc(sizeof(char) * (len+1));
	*stringPtr = p;
}

void memory_leak_003 ()
{
	char *str = "This is a string";
	char *str1;
	memory_leak_003_func_001(strlen(str),&str1);/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	strcpy(str1,str);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 * When using pointers to the structure with an string as a member of the structure
 */
typedef struct {
	int a;
	int b;
	char *buf;
} memory_leak_004_s_001;

void memory_leak_004 ()
{
	memory_leak_004_s_001* s=(memory_leak_004_s_001*) calloc(5,sizeof(memory_leak_004_s_001)) ;
	char *s1="This is a string";
	int i;
	if(s!=NULL)
	for(i= 0; i<5 ;i++)
	{
		(s+i)->buf = (char*)malloc(25* sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	}
	strcpy((s+4)->buf,s1);
	for(i= 0; i<5 ;i++);
	free(s);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 *  When using pointer to float Memory is allocated and freed in conditional statement(if)
 */
void memory_leak_005()
{
	float *ptr;
	int flag=10;

	if(flag > 0)
	{
		ptr= (float*) malloc(5*sizeof(float));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
		if(ptr!=NULL)
		{
        *(ptr+1) = 10.5;
		}
	}
    if(flag < 0)
	free(ptr);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 *  When using pointer to double Memory is allocated and freed based on return value of function
 */
int memory_leak_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void memory_leak_006()
{
	double *dptr;
	int flag=0;

	if(memory_leak_006_func_001(flag)==0)
	{
		dptr= (double*) malloc(5*sizeof(double));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
		if(dptr!=NULL)
		{
           *(dptr+1) = 10.50000;
		}
	}
    if(memory_leak_006_func_001(flag) !=0)
	free(dptr);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 *  When using Switch case statements and void pointer
 */
void *vptr;
int memory_leak_007_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			vptr = (int *)calloc(10, sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
			if(vptr!=NULL)
			{
			   *((int*)vptr+1) = 10;
			}
			return 1;
		}
		case 2:
		{
			vptr = (char *)calloc(10, sizeof(char));
			if(vptr!=NULL)
			{
			   *((char*)vptr+2) = 'a';
			}
			return 2;
		}
		case 3:
		{
			vptr = (float *)calloc(10, sizeof(float));
			if(vptr!=NULL)
			{
			   *((float*)vptr+3) = 5.5;
			}
			return 3;
		}
		default:
			return -1;
	}
}

void memory_leak_007 ()
{
	int ret;
	ret = memory_leak_007_func_001 (rand());
	if(ret == 0)
		if(vptr!=NULL)
		{
		free(vptr);
		}
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
*  When using 1 single pointer alias
*/
void memory_leak_008 ()
{
	int *ptr=(int*) malloc(5 * sizeof(int));
	int *p = (int*)malloc(5 * sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(ptr !=NULL)
	{
	p = ptr;
	*(p+1) = 1;
	free(ptr);
	}
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
*  When using 1 single pointer alias - dangling pointer
*/
void memory_leak_009 ()
{
	float *ptr=(float*) malloc(5 * sizeof(float));
	int *p = (int*) malloc(5 * sizeof(int)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(ptr !=NULL)
	{
          p = (int *)ptr;
	   *(p+1) = 1.5;
	   free (ptr);
	   ptr = NULL;
	}
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
*  When using 2 single pointer alias
*/
void memory_leak_0010 ()
{
	int *ptr = (int*) calloc(5,sizeof(int));
	int *p1 = (int*) calloc(5,sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	int *p2 = NULL;
	p1 = ptr;
	p2 = p1;
	*(p2+4) = 1;
	free(ptr);
}

/*
* Types of defects: Memory Leakage - Allocate Memory and not freeing it
*  When using alias(union) - a union containing two methods of accessing the same data (within the same function) alias
*/
typedef union {
    char * u1;
    char * u2;
} memory_leak_0011_uni_001;


void memory_leak_0011()
{
    char * buf = NULL;
    memory_leak_0011_uni_001 un;
    buf = (char *)calloc(50, sizeof(char)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(buf!=NULL)
	{
    strcpy(buf, "This Is A String");
    un.u1 = buf;
	}
    {
    	char * buf ;

    	buf = un.u2;
    }
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 * Complexity: Union of pointer	Constant	 expressions	Write
 */
typedef struct {
	int a;
	int b;
} memory_leak_0012_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_0012_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_0012_s_003;

typedef union {
	memory_leak_0012_s_001 s1;
	memory_leak_0012_s_002 s2;
	memory_leak_0012_s_003 s3;
} memory_leak_0012_uni_001;

void memory_leak_0012 ()
{
	memory_leak_0012_uni_001 *u = (memory_leak_0012_uni_001 * )malloc(5*sizeof( memory_leak_0012_uni_001 ));
	memory_leak_0012_uni_001 *p  = (memory_leak_0012_uni_001 * )malloc(5*sizeof( memory_leak_0012_uni_001 ));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	p = u;

	p->s1.a = 1;

	free(u);
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 * Complexity: Union of pointer	Constant	 expressions	Write
 */
typedef struct {
	int a;
	int b;
} memory_leak_0013_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_0013_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_0013_s_003;

typedef union {
	memory_leak_0013_s_001 *s1;
	memory_leak_0013_s_002 *s2;
	memory_leak_0013_s_003 *s3;
} memory_leak_0013_uni_001;

void memory_leak_0013 ()
{
	memory_leak_0013_uni_001 *u = (memory_leak_0013_uni_001 * )malloc(5*sizeof( memory_leak_0013_uni_001 ));
	if(u!=NULL)
	{
	u->s1 = (memory_leak_0013_s_001 *) malloc(sizeof(memory_leak_0013_s_001));
	}
	memory_leak_0013_uni_001 *p  = (memory_leak_0013_uni_001 * )malloc(5*sizeof( memory_leak_0013_uni_001 )); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	p->s1 = (memory_leak_0013_s_001 *) malloc(sizeof(memory_leak_0013_s_001));
	
	if(u!=NULL)
	{
	p = u;
	p->s1->a = 1;
    free(p->s1);
	free(p);

	}
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
*  Using two double pointers to the same value within the same function
*/
void memory_leak_0014 ()
{
    float * fptr;
    float **fp1 = &fptr;
    float **fp2 = &fptr;
    fptr = NULL;
    {
        float * fptr = *fp1;
        fptr = (float *)calloc(10, sizeof(float));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
        if(fptr!=NULL)
        {
        *(fptr+3) = 50.5;
        *fp1 = fptr;
        }
    }
    {
        float * fptr1 ;
        fptr1 = *fp2;
    }
}

/*
 * Types of defects: Memory Leakage - Allocate Memory and not freeing it
 *  Memory allocated and returned from one function and Memory used in another function
 */
char * memory_leak_0015_func_001 (int len)
{
	char *stringPtr = malloc(sizeof(char) * (len+1));
	return stringPtr;
}

void memory_leak_0015 ()
{
	char *str = "This is a string";
	char *str1 = memory_leak_0015_func_001(strlen(str)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(str1!=NULL)
	{
	    strcpy(str1,str);
	}
}

/*
* Types of defects: Freeing a NULL pointer
 *  Memory allocated in a function and Memory used in another function
 */
# define INDEX 'a'
static unsigned char a =INDEX;
char * memory_leak_0016_gbl_ptr;
void memory_leak_0016_func_001 (int len)
{
	memory_leak_0016_gbl_ptr=NULL;
	if(a == INDEX)
		memory_leak_0016_gbl_ptr= malloc(sizeof(char) * (len+1));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
}

void memory_leak_0016 ()
{
	char *str = "This is a string";
	memory_leak_0016_func_001(strlen(str));
	strcpy(memory_leak_0016_gbl_ptr,str);
}

/*
* Types of defects: Memory Leakage - Allocate Memory and not freeing it
* Complexity: When using a double pointer to long , memory allocated in another function inside goto label and if condition
*/
long ** memory_leak_0017_gbl_doubleptr;
int memory_leak_0017_func_001(int flag)
{
   int ret ;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void memory_leak_0017_func_002()
{
	int i,j;
	memory_leak_0017_gbl_doubleptr=(long**) malloc(10*sizeof(long*));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */

	for(i=0;i<10;i++)
	{
		memory_leak_0017_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			memory_leak_0017_gbl_doubleptr[i][j]=i;
		}
	}
}

#define ZERO 0
void memory_leak_0017()
{
	int flag=0,i,j;
	memory_leak_0017_gbl_doubleptr=NULL;
goto label;

    if(memory_leak_0017_func_001(flag)==ZERO)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				memory_leak_0017_gbl_doubleptr[i][j] += 1;
			}
			free (memory_leak_0017_gbl_doubleptr[i]);
			memory_leak_0017_gbl_doubleptr[i] = NULL;
	   }

	}

label:
    	if(memory_leak_0017_func_001(flag)==ZERO)
    	{
    		memory_leak_0017_func_002();
    	}
}

/*
* Types of defects: Memory Leakage - Allocate Memory and not freeing it
* Complexity: When using a double pointer to char in an infinite while loop
*/
/*Allocate Memory */
char **memory_leak_0018dst;
void memory_leak_0018_func_001()
{
	memory_leak_0018dst = NULL;
	int i;
    {
		while(1)
		{
			memory_leak_0018dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	memory_leak_0018dst[i]=(char*) malloc(15*sizeof(char));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
		    }
		    break;
		}
    }
}

void memory_leak_0018 ()
{
	int i;
    memory_leak_0018_func_001();
    for(i=0;i<5;i++)
    {
    	strcpy (memory_leak_0018dst[i],"STRING");
    }
	while(1)
	{
		for(i=0;i<5;i++)
	    {
                ;

	    }
	    free(memory_leak_0018dst);
	    memory_leak_0018dst = NULL;
	    break;
	}
}

/*
* Types of defects: Memory Leakage - Allocate Memory and not freeing it
* Complexity:Memory Leakage main function
*/
extern volatile int vflag;
void memory_leak_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		memory_leak_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		memory_leak_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		memory_leak_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		memory_leak_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		memory_leak_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		memory_leak_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		memory_leak_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		memory_leak_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		memory_leak_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		memory_leak_0010();
	}

	if (vflag == 11 || vflag ==888)
	{
		memory_leak_0011();
	}

	if (vflag == 12 || vflag ==888)
	{
		memory_leak_0012();
	}

	if (vflag == 13 || vflag ==888)
	{
		memory_leak_0013();
	}

	if (vflag == 14 || vflag ==888)
	{
		memory_leak_0014();
	}

	if (vflag == 15 || vflag ==888)
	{
		memory_leak_0015();
	}

	if (vflag == 16 || vflag ==888)
	{
		memory_leak_0016();
	}

	if (vflag == 17 || vflag ==888)
	{
		memory_leak_0017();
	}

	if (vflag == 18 || vflag ==888)
	{
		memory_leak_0018();
	}
}
