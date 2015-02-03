/********Software Analysis - FY2013*************/
/*
* File Name: func_pointer.c
* Defect Classification
* ---------------------
* Defect Type: Pointer related defects
* Defect Sub-type: Bad cast of a function pointer
* Description: Defect Free Code to identify false positives in bad cast of function pointer
*/

#include "HeaderFile.h"

#define MAX 10
typedef struct {
    int arr[MAX];
    int a;
    int b;
    int c;
} func_pointer_015_s_001;

int (*func_gbl)(void );

void (*fptr_gbl)(func_pointer_015_s_001*);
void (*fptr1_gbl)(func_pointer_015_s_001 *);
void (*fptr2_gbl)(func_pointer_015_s_001 *);

long ** func_pointer_005_doubleptr_gbl;

int global_set=0;

/*
 * Type of defect: Bad function pointer casting - Wrong return type
 * Complexity: different return type function :void and function pointer: int (no arguments)
 */
void func_pointer_001_func_001 ()
{
	int a ;
	a =10;
        sink = a;
}

void func_pointer_001 ()
{
	void (*func)();
	func = func_pointer_001_func_001; 
	func();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :int and function pointer: void  (one char argument)
 */
int func_pointer_002_func_001(char a)
{
	a++;
	return (a);
}

void func_pointer_002 ()
{
 	char buf[10] = "string";
	int (*fptr)(char);
	int a;
	fptr = func_pointer_002_func_001; 
	a =fptr(buf[0]);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
        sink = a;
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
  * Complexity: different return type function :long and function pointer: float  (one long argument , one int argument),
  * function pointer declared and used inside if statement
 */
long func_pointer_003_func_001 (long a, int b)
{
	return (a + (long)b);
}

void func_pointer_003 ()
{
 	long ret;
	if(1)
	{
		long (*func)(long , int);
		func = func_pointer_003_func_001; 
		ret = func(1, 2);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
        sink = ret;
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
  * Complexity: different return type function :char * and function pointer: int  (one char * argument),
  * function pointer declared and used inside for loop
 */
static char * func_pointer_004_func_001 (char *str1)
{
    int i = 0;
    int j;
    char * str_rev = NULL;
    if (str1 != NULL)
    {
        i = strlen(str1);
        str_rev = (char *) malloc(i+1);
        if(str_rev!=NULL)
        {
        	for (j = 0; j < i; j++)
            {
               str_rev[j] = str1[i-j-1];
            }
            str_rev[i] = '\0';
        }
        return str_rev;
    }
    else
    {
        return NULL;
    }
}

void func_pointer_004 ()
{
     int j;
    char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        {
            char * str;
            char *(*fptr)(char *);
            fptr = func_pointer_004_func_001; 
            str = fptr(buf[j]);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
            psink = str;
        }
    }
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
  * Complexity: different return type function :long ** and function pointer: void  (no argument),
  * function pointer declared and used inside if statement based on return value of function
 */
int func_pointer_005_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

long **  func_pointer_005_func_002()
{
	int i,j;
	func_pointer_005_doubleptr_gbl=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		func_pointer_005_doubleptr_gbl[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_005_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_005_doubleptr_gbl;
}

void func_pointer_005()
{
 	int flag=0,i,j;
	long ** doubleptr=NULL;

	if(func_pointer_005_func_001(flag)==0)
	{
		long **(*fptr)(); 
	    fptr = func_pointer_005_func_002;
	    doubleptr = fptr();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	    for(i=0;i<10;i++)
	    {
	    	for(j=0;j<10;j++)
		    {
	    		doubleptr[i][j] += 1;
		    }
		    free (doubleptr[i]);
		    doubleptr[i] = NULL;
	    }
        free(doubleptr);
        doubleptr = NULL;
	}
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
  * Complexity: different return type function :float ** and function pointer: char **  (no argument),
  * function pointer declared and used inside if statement based on return value of function
 */

float ** func_pointer_006_doubleptr_gbl=NULL;
int func_pointer_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

float **  func_pointer_006_func_002()
{
	int i,j;
	func_pointer_006_doubleptr_gbl=(float **) malloc(10*sizeof(float*));

	for(i=0;i<10;i++)
	{
		func_pointer_006_doubleptr_gbl[i]=(float *) malloc(10*sizeof(float));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_006_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_006_doubleptr_gbl;
}

float **  func_pointer_006_func_003()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			func_pointer_006_doubleptr_gbl[i][j]=i;
		}
	}
	return func_pointer_006_doubleptr_gbl;
}

float **  func_pointer_006_func_004()
{
	int i;
	for(i=0;i<10;i++)
	{
	    free (func_pointer_006_doubleptr_gbl[i]);
	    func_pointer_006_doubleptr_gbl[i] = NULL;
	}
    free(func_pointer_006_doubleptr_gbl);
    func_pointer_006_doubleptr_gbl = NULL;
	return func_pointer_006_doubleptr_gbl;
}

void func_pointer_006()
{
	int flag=0,i,j;
	if(func_pointer_006_func_001(flag)==0)
	{
		float **(*fptr)();
	    fptr = func_pointer_006_func_002; 
	    func_pointer_006_doubleptr_gbl = fptr();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	    fptr = func_pointer_006_func_003;
	    func_pointer_006_doubleptr_gbl = fptr();
	    for(i=0;i<10;i++)
	    {
	    	for(j=0;j<10;j++)
		    {
	    		func_pointer_006_doubleptr_gbl[i][j] += 1;
		    }
	    }
	    fptr = func_pointer_006_func_004;
	    func_pointer_006_doubleptr_gbl = fptr();
	}
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :int and function pointer: char**  (one char array argument)
 */
int func_pointer_007_func_001(char a[])
{
    int i=0;
	return (a[i]);
}

void func_pointer_007 ()
{
  	char buf[10] = "A string";
	int (*fptr)(char []);
	int a;
	fptr = func_pointer_007_func_001; 
	a =fptr(buf);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
        sink = a;
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :void and function pointer: float**  (one char array argument)
 */
static float a[2][3] = { {1.0,2.0,3.0},
		                {11.1,22.1,33.1} };
void func_pointer_008_func_001(float a[][3] , int max)
{
    a[max-1][2] = 50.6;
}

void func_pointer_008 ()
{
	switch(1)
	{
		case 1:
		{
			void (*fptr)(float [][3] , int); 
			fptr = func_pointer_008_func_001;
			fptr(a,1);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
			break;
		}
		default:
		{
			break;
		}
	}
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :union * and function pointer: union  (no argument)
 */
typedef union {
	int a;
	int b;
} func_pointer_009_u_001;

func_pointer_009_u_001 * func_pointer_009_func_001 (void)
{
	int flag = rand();
	flag = 1;
	func_pointer_009_u_001 *u;
	switch (flag)
	{
		case 1:
		{
			u = (func_pointer_009_u_001 *)calloc(1,sizeof(func_pointer_009_u_001));
			if(u!=NULL)
			u->a = 40;
			return u;
		}
		default:
			return (func_pointer_009_u_001 *)(-1);
	}
}

void func_pointer_009 ()
{
        int ret = 0;
	func_pointer_009_u_001 *p;
	func_pointer_009_u_001 *(*fptr)(); 
	fptr = func_pointer_009_func_001;
	p = fptr ();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	if(p!=NULL)
	{
	   ret = p->b;
	   free(p);
	}
	p= NULL;
        sink = ret;
}

/*
 * Type of defect: bad function pointer casting -- Wrong return type
 * Complexity: the function pointer - single alias (conditions are the same as No.1)
 */
void func_pointer_010_func_001 ()
{
	int a;
	a= 10;
        sink = a;
}

void func_pointer_010 ()
{
	void (*func)();
	void (*func1)();
	func = func_pointer_010_func_001; /*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	func1 = func;
	func1();
}

/*
 * Type of defect: bad function pointer casting -- Wrong return type
 * Complexity: the function pointer - double alias
 */

#define MAX 10
char * func_pointer_011_func_001 (const char *str1)
{
    int i = 0;
    int j;
    char * str_rev = NULL;
    if (str1 != NULL)
    {
        i = strlen(str1);

        str_rev = (char *) malloc(i+1);
        if(str_rev !=NULL)
        {
        	for (j = 0; j < i; j++)
            {
        		str_rev[j] = str1[j];
            }
            str_rev[j] = '\0';
        }
        return str_rev;
    }
    else
    {
        return NULL;
    }
}

void func_pointer_011 ()
{
    int j;
    const char buf[][25]={"This is a String",
    		     "Second String"};
    for(j = 0; j <= 1; j++)
    {
        if (MAX ==10)
    	{
            char * str;
            char *(*fptr)(const char *);
            char *(*fptr1)(const char *); 
            char *(*fptr2)(const char *);
            fptr = func_pointer_011_func_001;
            fptr1 = fptr;
            fptr2 = fptr1;
            str = fptr2(buf[j]);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
            psink = str;
        }
    }
 }

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :pointer to array of Int * and typedef and function pointer: float *(no argument)
 */
typedef int (*pointertoarr)[4];
int (*func_pointer_012_func_001())[4]
{
	int (*p)[4];
	int arr[4][4] = {{1,2,3,4},
			         {11,22,33,44},
			         {33,44,55,66},
			         {55,66,77,88}};
	int i,j;
	p= (int (*)[]) malloc (sizeof arr);
	if(p!=NULL)
	{
	   memcpy(p, arr, sizeof(arr));
	   for (i = 0;i< 4; i++)
	   {
		   for ( j=0 ;j<4; j++)
		   {
			   *(p[i]+j) += *(p[i]+j);
		   }
	   }
	}
	return p;
}

void func_pointer_012 ()
{
    int (*ptr)[4];
	pointertoarr(*func)();
	func = func_pointer_012_func_001; 
	ptr = func();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	free(ptr);
}

/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :int and typedef and function pointer: int *,void(int)
 * Global function pointer , re-declared locally with different type
 */

int func_pointer_013_func_001 ()
{
	int a;
	a= 10;
	return a;
}

int func_pointer_013_func_002 (int flag)
{
	int ret = 0;
	int arr[]={3,8,9,10,4};
	int *ptr;
	if (flag == 1)
	{
		goto my_label;
	}
	return ret;
my_label:
    if (flag == 1)
	{
        int (*func_gbl)(void );
        func_gbl = func_pointer_013_func_001; 
        flag = func_gbl();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
	ptr = &arr[0];
	*(ptr+1) = 7;
	ret ++;
	return ret;
}

void func_pointer_013 ()
{
    int flag;
    int (*func_gbl)(int );
    func_gbl = func_pointer_013_func_002;
    flag = func_gbl(1);
    sink = flag;
}


/*
 * Type of defect: bad function pointer casting - Wrong return type
 * Complexity: different return type function :int and function pointer: float
 * Global function pointer returns different type
 */
int func_pointer_014_func_001 (void)
{
	int a;
	a= 10;
	return a;
}

int func_pointer_014_func_002 (int flag)
{
	int ret = 0;
	if (flag == 1)
	{
		goto my_label;
	}

	return ret;

my_label:
    if (flag == 1)
	{
        func_gbl = func_pointer_014_func_001; 

        goto my_label2;
 	ret ++;
	}

my_label2:
    if (flag == 1)
 	{
          flag = func_gbl();/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
 	}
	return ret;
}

void func_pointer_014 ()
{
    int flag;
    int (*fptr)(int);
    fptr =func_pointer_014_func_002;
    flag = fptr(1);
    sink = flag;
}

/*
* Type of defect: Bad function pointer casting - Wrong return type
* Complexity: Different return types and the number of argument is one
* (function : returns void and function pointer :structure).
* one function pointer used multiple times with  different return type
*/

void func_pointer_015_func_001(func_pointer_015_s_001* st)
{
    memset(st, 0, sizeof(*st));
    st->a = 1;
    global_set = 1;
}

void func_pointer_015_func_002(func_pointer_015_s_001* st1)
{
    int temp=0;
    int i;
    for (i = 0; i < MAX; i++)
    {
    	st1->arr[i] += i;
    	temp += st1->arr[i];
    }
}

void func_pointer_015_func_003(func_pointer_015_s_001 *st)
{
    st->b = st->c;
}

void func_pointer_015_func_004(func_pointer_015_s_001* st1)
{
	if (global_set == MAX)
	{
	   fptr1_gbl = func_pointer_015_func_002;
	   fptr1_gbl(st1);
	}
	else
	{
		fptr2_gbl = func_pointer_015_func_003; 
		fptr2_gbl(st1);/*Tool should not detect this line as error*/ /*No ERROR:Bad function pointer casting*/
	}
}

void func_pointer_015 ()
{
	func_pointer_015_s_001 st,*st1;
	st1 = (func_pointer_015_s_001 *)malloc(1*sizeof(func_pointer_015_s_001));
    memset(st1, 0, sizeof(*st1));

	fptr_gbl = func_pointer_015_func_001;
	fptr_gbl(&st);

	void (*fptr3)(func_pointer_015_s_001* st1);
	fptr3 = func_pointer_015_func_004;
	fptr3(st1);
}

/*
 * Type of defect: bad function pointer casting
 * bad function pointer casting main function
 */
extern volatile int vflag;
void func_pointer_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		func_pointer_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		func_pointer_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		func_pointer_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		func_pointer_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		func_pointer_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		func_pointer_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		func_pointer_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		func_pointer_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		func_pointer_009();
	}

	if (vflag == 10 || vflag ==888)
	{
		func_pointer_010();
	}

	if (vflag == 11 || vflag ==888)
	{
		func_pointer_011();
	}

	if (vflag == 12 || vflag ==888)
	{
		func_pointer_012();
	}

	if (vflag == 13 || vflag ==888)
	{
		func_pointer_013();
	}

	if (vflag == 14 || vflag ==888)
	{
		func_pointer_014();
	}

	if (vflag == 15 || vflag ==888)
	{
		func_pointer_015();
	}

}
