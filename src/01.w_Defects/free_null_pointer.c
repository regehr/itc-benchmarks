/********Software Analysis - FY2013*************/
/*
* File Name: free_null_pointer.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Free NULL  pointer
*
*/

#include "HeaderFile.h"

int *free_null_pointer_002_gbl_ptr = NULL;
char **free_null_pointer_010_gbl_dst=NULL;

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to char
*/
void free_null_pointer_001 ()
{
	char* buf= NULL;
	free(buf);/* Tool should detect this line as error */ /*ERROR:Freeing a NULL pointer*/
	buf = NULL;
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to int that is global file scope , inside a if statement
*/
void free_null_pointer_002 ()
{
     int a=20;
     if(a>0)
     {
     	 free(free_null_pointer_002_gbl_ptr);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
     	 free_null_pointer_002_gbl_ptr = NULL;
     }
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to long in an infinite for loop , memory allocated and assigned inside a if condition
*/
void free_null_pointer_003 ()
{
	int i;
	long *buf=NULL;
	for (i=0;;i++)
	{
		if(i>=10)
		{
			buf=(long*) calloc(5,sizeof(long));
			buf[0]=i;
		}
		free (buf);/*ERROR:Freeing a NULL pointer*/
		buf = NULL;
		if(i>=10)
		break;
	}
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a double pointer to float , memory allocated in an do - while loop
*/
void free_null_pointer_004 ()
{
	float **fptr = (float**) malloc(5*sizeof(float*));
	int i=0,j=0;

do
{
	fptr[i]=NULL;
	i++;
}while (i<5);

    i=0;
    do
	{
		for(j=0;j<5;j++)
		{
			/**(*(fptr+i)+j)=i+0.5;*/
		}
	    free(fptr[i]); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	    i++;
    }while (i<5);
	free(fptr);
}

/*
* Types of defects: Freeing a NULL pointer
 *  Memory allocated in a function and Memory used in another function
 */
# define INDEX 'a'
static unsigned char a =INDEX;
char * free_null_pointer_005_gbl_ptr;
void free_null_pointer_005_func_001 (int len)
{
	free_null_pointer_005_gbl_ptr=NULL;
	if(a != INDEX)
		free_null_pointer_005_gbl_ptr= malloc(sizeof(char) * (len+1));
}

void free_null_pointer_005 ()
{
	char *str = "This is a string";
	free_null_pointer_005_func_001(strlen(str));
	strcpy(free_null_pointer_005_gbl_ptr,str);
	free(free_null_pointer_005_gbl_ptr); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	free_null_pointer_005_gbl_ptr = NULL;
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to structure ,memory allocated based on function return value
*/
int free_null_pointer_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

typedef struct {
	int a;
	int b;
	char *buf;
} free_null_pointer_006_s_001;

void free_null_pointer_006 ()
{
	int flag=0,i;
	char *s1="This is a string";
	free_null_pointer_006_s_001* s=(free_null_pointer_006_s_001*) calloc(5,sizeof(free_null_pointer_006_s_001)) ;

	if(free_null_pointer_006_func_001(flag)==0)
	{
		for(i= 0; i<5 ;i++)
	    {
			(s+i)->buf = NULL;
	    }
	    strcpy((s+4)->buf,s1);
	}
	if(free_null_pointer_006_func_001(flag)==0)
	{
		for(i= 0; i<5 ;i++)
			free((s+i)->buf);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	}
	free(s);
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a double pointer to long , memory allocated in another function inside goto label and if condition
*/
long ** free_null_pointer_007_gbl_doubleptr;
int free_null_pointer_007_func_001(int flag)
{
   int ret ;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}
void free_null_pointer_007_func_002()
{
	int i,j;
	free_null_pointer_007_gbl_doubleptr=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		free_null_pointer_007_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			free_null_pointer_007_gbl_doubleptr[i][j]=i;
		}
	}
}

#define ZERO 0
void free_null_pointer_007()
{
	int flag=0,i,j;
	free_null_pointer_007_gbl_doubleptr=NULL;
goto label;

    if(free_null_pointer_007_func_001(flag)!=ZERO)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				free_null_pointer_007_gbl_doubleptr[i][j] += 1;
			}
			free (free_null_pointer_007_gbl_doubleptr[i]);
			free_null_pointer_007_gbl_doubleptr[i] = NULL;
	   }
	}
    else
    {
	    free(free_null_pointer_007_gbl_doubleptr);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	    free_null_pointer_007_gbl_doubleptr = NULL;
    }
label:
    	if(free_null_pointer_007_func_001(flag)!=ZERO)
    	{
    		free_null_pointer_007_func_002();
    	}
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a double pointer to char , and initialized in another function
*/
enum {min_buffer = 0 , max_buffer = 5 };
static unsigned int min=min_buffer+2;
static unsigned int max=max_buffer+2;
void free_null_pointer_008_func_001 (int len,char **stringPtr)
{
	char * p = NULL;
	if(min <= min_buffer && max <= max_buffer)
    {
		p = malloc(sizeof(char) * (len+1));
	    *stringPtr = p;
    }
}

void free_null_pointer_008 ()
{
	char *str = "This is a string";
	char *str1=NULL;
	free_null_pointer_008_func_001(strlen(str),&str1);
	strcpy(str1,str);
	free(str1);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	str1 = NULL;
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a double pointer to char in an infinite while loop
*/
/*Allocate Memory */
char **free_null_pointer_009dst;
void free_null_pointer_009_func_001()
{
	free_null_pointer_009dst = NULL;
	int i;
    {
		while(0)
		{
			free_null_pointer_009dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	free_null_pointer_009dst[i]=(char*) malloc(15*sizeof(char));
		    }
		    break;
		}
    }
}

void free_null_pointer_009 ()
{
	int i;
    free_null_pointer_009_func_001();
    for(i=0;i<5;i++)
    {
    	strcpy (free_null_pointer_009dst[i],"STRING");
    }
	while(1)
	{
		for(i=0;i<5;i++)
	    {
			free(free_null_pointer_009dst[i]);
			free_null_pointer_009dst[i] = NULL;
	    }
	    break;
	}
	while(1)
	{
	    free(free_null_pointer_009dst);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	    free_null_pointer_009dst = NULL;
	    break;
	}
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a double pointer to char in an infinite while loop,memory allocated in one function ,
* set in another function and freed in another function
*/
#define SET_MEM 0
void free_null_pointer_010_func_001()
{
	int i;
    {
		while(SET_MEM)
		{
			free_null_pointer_010_gbl_dst = (char**) malloc(5*sizeof(char*));
		    for(i=0;i<5;i++)
		    {
		    	free_null_pointer_010_gbl_dst[i]=(char*) malloc(15*sizeof(char));
		    }
		    break;
		}
    }
}
void free_null_pointer_010_func_002(char **dst, char (*src)[15])
{
	int i;
	for(i=0;i<5;i++)
	{
	   strcpy(*(dst+i),src[i]);
	}
}
void free_null_pointer_010_func_003()
{
	int i;
	while(SET_MEM)
	{
		for(i=0;i<5;i++)
	    {
			free(free_null_pointer_010_gbl_dst[i]);
			free_null_pointer_010_gbl_dst[i] = NULL;
	    }
	    break;
	}
	while(SET_MEM == 0)
	{
	    free(free_null_pointer_010_gbl_dst);
	    free_null_pointer_010_gbl_dst = NULL;/*ERROR:Freeing a NULL pointer*/
	    break;
	}
}
void free_null_pointer_010 ()
{
    char str2[][15] = {{"STRING"},
    		       {"TEST"},{"STRING#"},{"TEST!"},{"TRIAL"}};
    free_null_pointer_010_func_001();
    free_null_pointer_010_func_002(free_null_pointer_010_gbl_dst,str2);
    free_null_pointer_010_func_003();
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to union in an switch case and random function and static pointer to union
*/
typedef union {
	int a;
	int b;
} free_null_pointer_011_u_001;

static free_null_pointer_011_u_001 *u;
free_null_pointer_011_u_001 * free_null_pointer_011_func_001 ()
{

	int flag = 0;
	switch (flag)
	{
		case 1:
		{
			u = (free_null_pointer_011_u_001 *)calloc(1,sizeof(free_null_pointer_011_u_001));
			u->a = 40;
			return u;
		}
		case 2:
		{
			u = (free_null_pointer_011_u_001 *)calloc(2,sizeof(free_null_pointer_011_u_001));
			u->a = 20;
			return u;
		}
		case 3:
		{
			u = (free_null_pointer_011_u_001 *)calloc(3,sizeof(free_null_pointer_011_u_001));
			u->a = 30;
			return u;
		}
		default:
			return (free_null_pointer_011_u_001 *)(-1);
	}
}

free_null_pointer_011_u_001 * free_null_pointer_011_func_002 ()
{
	int flag = rand();
	switch (flag)
	{
		case 1:
		{
			free(u); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
			u= NULL;
			return u;
		}
		case 2:
		{
			return u;
		}
		case 3:
		{
			return u;
		}
		default:
			return (free_null_pointer_011_u_001 *)(-1);
	}
}

void free_null_pointer_011 ()
{
	int ret;
	free_null_pointer_011_u_001 *p;
	p = free_null_pointer_011_func_001 ();
	ret = p->b;
	p = free_null_pointer_011_func_002 ();
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to double in an ternary conditional operator
*/
#define ZERO 0
#define MAX 1
int free_null_pointer_012_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}
void free_null_pointer_012 ()
{
	double *ptr =NULL, a;
	int flag=10;

    if (free_null_pointer_012_func_001(1) == ZERO && MAX ==1)
    {
    	(flag == 10)? (ptr= (double*) malloc(10*sizeof(double))) : ( ptr= NULL);
        (flag == 10)? (*(ptr+1) = 10):(a=100);
    }

    if (free_null_pointer_012_func_001(0) == ZERO && MAX ==1)
    {
    	if(flag == 10)
    	a = *(ptr+1);
    }

    if (free_null_pointer_012_func_001(0) == ZERO && MAX ==1)
    {
    	if(flag == 10)
        {
    		free(ptr); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
    	    ptr = NULL;
        }
    }
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to double in an while  loop, pointer aliasing
*/
void free_null_pointer_013 ()
{
	double * fptr;
	double **fp1 = &fptr;
	double **fp2 = &fptr;
	fptr = NULL;
	int i=0;
	do
	{
		double * fptr = *fp1;
		if(i>=10 && i<=100)
		{
	       fptr = (double *)calloc(10, sizeof(double));
		}
	    *(fptr+3) = 50.5;
	    *fp1 = fptr;
	    i++;
	}while(i>=0 && i<=1);
	do
	{
	    double * fptr = *fp2;
        free(fptr);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
        fptr = NULL;
	}while(i>=0 && i<=1);
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: When using a pointer to int element in structure
*/
typedef struct  {
    double *p1;
    double *p2;
    double *p3;
}free_null_pointer_014_s_001 ;

free_null_pointer_014_s_001 *free_null_pointer_014_gbl_s=NULL;

void free_null_pointer_014_func_001(int flag)
{
	int i;
	if(flag ==1)
	{
		for (i=1;i<1;i++)
		{
			free_null_pointer_014_gbl_s = malloc(sizeof(free_null_pointer_014_s_001));
		    free_null_pointer_014_gbl_s->p1 =  malloc(sizeof(double));
		    free_null_pointer_014_gbl_s->p2 =  malloc(sizeof(double));
		    free_null_pointer_014_gbl_s->p3 =  malloc(sizeof(double));
		}
	}
}

void free_null_pointer_014_func_002(int flag)
{
   static double arr[3]={10.0,20.0,30.0};
   int i;
   if (flag ==1)
   {
	   for (i=0;i<1;i++)
	   {
		   *(free_null_pointer_014_gbl_s->p1) = arr[0];
		   *(free_null_pointer_014_gbl_s->p2) = arr[1];
		   *(free_null_pointer_014_gbl_s->p3) = arr[2];
	   }
   }
}

void free_null_pointer_014_func_003(int flag)
{
   int i;
   if (flag ==1)
   {
	   for (i=1;i<1;i++)
	   {
		  free(free_null_pointer_014_gbl_s->p1);
		  free(free_null_pointer_014_gbl_s->p2);
		  free(free_null_pointer_014_gbl_s->p3);
	   }
	   for (i=0;i<1;i++)
	   {
		  free(free_null_pointer_014_gbl_s);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
	   }

   }
}

void free_null_pointer_014 ()
{
	  free_null_pointer_014_func_001(1);
	  free_null_pointer_014_func_002(1);
	  free_null_pointer_014_func_003(1);
}

/*
* Types of defects: Freeing a NULL pointer
* Complexity: Free Null Pointer main function
*/
extern volatile int vflag;
void free_null_pointer_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		free_null_pointer_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		free_null_pointer_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		free_null_pointer_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		free_null_pointer_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		free_null_pointer_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		free_null_pointer_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		free_null_pointer_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		free_null_pointer_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		free_null_pointer_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		free_null_pointer_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		free_null_pointer_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		free_null_pointer_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		free_null_pointer_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		free_null_pointer_014();
	}
}
