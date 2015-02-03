/********Software Analysis - FY2013*************/
/*
* File Name: st_cross_thread_access.c
* Defect Classification
* ---------------------
* Defect Type: Stack related defects
* Defect Sub-type: Cross thread stack access
*
*/


/* #include <pthread.h>	Compile-time options. -lpthread You can specify */
#include "HeaderFile.h"

/* Polyspace Does not support Concurrency */


#if defined(CHECKER_POLYSPACE)
# define NULL ((void *) 0)
int rand (void);
#endif /* defined(CHECKER_POLYSPACE) */
/*
 * Types of defects: Cross thread stack access
 * Complexity: Cross thread stack access in same function using two thread
 */

pthread_mutex_t st_cross_thread_access_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_001_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_001_glb_mutex_lock () {}
void st_cross_thread_access_001_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int st_cross_thread_access_001_glb_data = 0;
int *st_cross_thread_access_001_glb_ptr;

void * st_cross_thread_access_001_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char * th = (char *)pram;
	int arr[10];
	arr[0] = 10;
	*st_cross_thread_access_001_glb_ptr = 200;
	pthread_mutex_lock(&st_cross_thread_access_001_glb_mutex);
	st_cross_thread_access_001_glb_ptr = arr;
	st_cross_thread_access_001_glb_data = (st_cross_thread_access_001_glb_data % 100) + 1;

	pthread_mutex_unlock(&st_cross_thread_access_001_glb_mutex);

	unsigned long ip = (unsigned long)pthread_self();
    printf("Task1! Cross thread stack access, threadID# %lu! thread no =%s %d\n",ip ,th,*st_cross_thread_access_001_glb_ptr);
#endif /* defined(CHECKER_POLYSPACE) */
    return NULL;
}

void * st_cross_thread_access_001_tsk_002 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char * th = (char *)pram;
	pthread_mutex_lock(&st_cross_thread_access_001_glb_mutex_1);
	st_cross_thread_access_001_glb_data = (st_cross_thread_access_001_glb_data % 100) + 1;
	*st_cross_thread_access_001_glb_ptr = 200; /*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
	pthread_mutex_unlock(&st_cross_thread_access_001_glb_mutex_1);

	unsigned long ip = (unsigned long)pthread_self();
    printf("Task1! Cross thread stack access, threadID# %lu! thread no = %s \n",ip ,th);
#endif /* defined(CHECKER_POLYSPACE) */
    return NULL;
}

void st_cross_thread_access_001 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	const char *t1 = "THREAD1";
	const char *t2 = "THREAD2";
	pthread_mutex_init(&st_cross_thread_access_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_001_tsk_001, (void *)t1);
	sleep(1);
	pthread_mutex_init(&st_cross_thread_access_001_glb_mutex_1, NULL);
	pthread_create(&tid2, NULL, st_cross_thread_access_001_tsk_002, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&st_cross_thread_access_001_glb_mutex);
	pthread_mutex_destroy(&st_cross_thread_access_001_glb_mutex_1);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_001_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Cross thread stack access
 * Complexity: unLocking without locking in same function using two thread inside a if condition
 */
pthread_mutex_t st_cross_thread_access_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_002_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_002_glb_mutex_lock () {}
void st_cross_thread_access_002_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

unsigned long st_cross_thread_access_002_glb_data = 0;
int const st_cross_thread_access_002_var = 10;
int arr1[5]={1,2,3,4,5};
int * st_cross_thread_access_002_glb_ptr = arr1;
void * st_cross_thread_access_002_tsk_001 (void * pram)
{
#if !defined(CHECKER_POLYSPACE)
	int arr[5] = {10,20,30,40,50};
	if(st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex);
	    st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
		st_cross_thread_access_002_glb_ptr = arr;
		*st_cross_thread_access_002_glb_ptr = 200.0;
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex);
	}
	if(st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex);
	    st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task2! Cross thread stack access, threadID # %lu! gbl2 = %lu \n",ip ,st_cross_thread_access_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
		pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void * st_cross_thread_access_002_tsk_002 (void * pram)
{
#if !defined(CHECKER_POLYSPACE)
	if(st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex_1);
	    st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
	    *st_cross_thread_access_002_glb_ptr = 200.0;/*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
	    pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex_1);
	}
	if(st_cross_thread_access_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&st_cross_thread_access_002_glb_mutex_1);
	    st_cross_thread_access_002_glb_data = (st_cross_thread_access_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task2! Cross thread stack access, threadID # %lu! gbl2 = %lu \n",ip ,st_cross_thread_access_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
        pthread_mutex_unlock(&st_cross_thread_access_002_glb_mutex_1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_002 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	intptr_t st_cross_thread_access_002_t1 = 10;
	intptr_t st_cross_thread_access_002_t2 = 10;
	pthread_mutex_init(&st_cross_thread_access_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_002_tsk_001, (void *)st_cross_thread_access_002_t1);
	sleep(1);
	pthread_create(&tid2, NULL, st_cross_thread_access_002_tsk_002, (void *)st_cross_thread_access_002_t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_002_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Cross thread stack access
 * Complexity: Cross thread stack access over multiple functions , 2 threads,based on return value of function
 */
pthread_mutex_t st_cross_thread_access_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_003_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_003_glb_mutex_lock () {}
void st_cross_thread_access_003_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

float st_cross_thread_access_003_glb_data = 1000.0;
float st_cross_thread_access_003_glb_data1 = 10.0;
float *st_cross_thread_access_003_glb_ptr = &st_cross_thread_access_003_glb_data1;

int st_cross_thread_access_003_func_002 (int a );
void * st_cross_thread_access_003_tsk_001 (void *pram)
{
	float fptr = 50.2;
#if ! defined(CHECKER_POLYSPACE)
    if(st_cross_thread_access_003_func_002(10) >1)
    {
    	pthread_mutex_lock (&st_cross_thread_access_003_glb_mutex);
        st_cross_thread_access_003_glb_data = (st_cross_thread_access_003_glb_data) + 1.2;
        st_cross_thread_access_003_glb_ptr = &fptr;
#if defined PRINT_DEBUG
	    intptr_t ip = (intptr_t)pram;
	    printf("Task3! Cross thread stack access, thread # %d! gbl3 = %f \n",ip ,st_cross_thread_access_003_glb_data);
#endif /* defined(PRINT_DEBUG) */
    	pthread_mutex_unlock (&st_cross_thread_access_003_glb_mutex);
    }
#endif /* ! defined(CHECKER_POLYSPACE) */
    return NULL;
}

int st_cross_thread_access_003_func_002 (int a )
{
    int ret = 0;
	if (a > 1)
    {
    	ret = a++;
    }
    return ret;
}

void* st_cross_thread_access_003_tsk_002 (void *pram)
{
#if ! defined(CHECKER_POLYSPACE)

    if(st_cross_thread_access_003_func_002(10) !=0)
    {
    	pthread_mutex_lock (&st_cross_thread_access_003_glb_mutex_1);
    	*st_cross_thread_access_003_glb_ptr = 5.3;/*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
    	st_cross_thread_access_003_glb_data = (st_cross_thread_access_003_glb_data) + 3.5;
    	pthread_mutex_unlock(&st_cross_thread_access_003_glb_mutex_1);
    }
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void st_cross_thread_access_003 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&st_cross_thread_access_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, st_cross_thread_access_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, st_cross_thread_access_003_tsk_002, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&st_cross_thread_access_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void st_cross_thread_access_003_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			st_cross_thread_access_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Cross thread stack access
 * Complexity: Cross thread stack access over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t st_cross_thread_access_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
char *buf1="String1";
char *buf2="String2";
char **pbuf[2] = {&buf1, &buf2};
void *st_cross_thread_access_004_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	char *buf11="String111";

	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &st_cross_thread_access_004_glb_mutex_1 );
				pbuf[0] = &buf11;
			   pthread_mutex_unlock( &st_cross_thread_access_004_glb_mutex_1 );
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task4_1! Cross thread stack access, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */

   return NULL;
}

void * st_cross_thread_access_004_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &st_cross_thread_access_004_glb_mutex_2 );
			   strcpy(*pbuf[0],"TEST");/*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
			   pthread_mutex_unlock( &st_cross_thread_access_004_glb_mutex_2 );
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task4_2! Cross thread stack access, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void st_cross_thread_access_004 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   intptr_t t1 = 10;
	   intptr_t t2 = 20;
	   pthread_create(&th1, NULL, st_cross_thread_access_004_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, st_cross_thread_access_004_tsk_002, (void *)t2);
	   /*pthread_join(th1, NULL);
	   pthread_join(th2, NULL);*/
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Cross thread stack access
 * Complexity: Thread created in else condition that will never execute , no lock but there is a unlock
 */
pthread_mutex_t st_cross_thread_access_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_005_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
int st_cross_thread_access_005_glb_data = 0;

# define NO_THREAD 0
int st_cross_thread_access_005_thread_set = NO_THREAD;
int arr[4][4] = {{1,2,3,4},
		         {11,22,33,44},
		         {33,44,55,66},
		         {55,66,77,88}};
int (*p)[4] =arr;

void * st_cross_thread_access_005_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set != NO_THREAD)
	{
		;
	}
	else
	{
		int arr1[4][4] = {{1,2,3,4},
				         {11,22,33,44},
				         {33,44,55,66},
				         {55,66,77,88}};
		p =arr1;
		pthread_mutex_lock(&st_cross_thread_access_005_glb_mutex);
	    st_cross_thread_access_005_glb_data = (st_cross_thread_access_005_glb_data % 100) + 5;
	    pthread_mutex_unlock(&st_cross_thread_access_005_glb_mutex);

	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task5! Cross thread stack access, threadID# %lu! gbl5 = %d arrval = %d \n",ip ,st_cross_thread_access_005_glb_data,*(p[2]+2));

#endif /* defined(CHECKER_POLYSPACE) */
	}
    return NULL;
}

void * st_cross_thread_access_005_tsk_002 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set != NO_THREAD)
	{
		;
	}
	else
	{
		*(p[2]+2) =10;/*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
		pthread_mutex_lock(&st_cross_thread_access_005_glb_mutex_1);
	    st_cross_thread_access_005_glb_data = (st_cross_thread_access_005_glb_data % 100) + 5;
	    pthread_mutex_unlock(&st_cross_thread_access_005_glb_mutex_1);

	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task5_2! Cross thread stack access, threadID# %lu! gbl5 = %d arrval = %d \n",ip ,st_cross_thread_access_005_glb_data,*(p[2]+2));/*Tool should detect this line as error*/ /*Cross thread stack access error*/

#endif /* defined(CHECKER_POLYSPACE) */
	}
    return NULL;
}

void st_cross_thread_access_005 ()
{
#if !defined(CHECKER_POLYSPACE)
	if (st_cross_thread_access_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1,tid2;
	    pthread_mutex_init(&st_cross_thread_access_005_glb_mutex, NULL);
	    pthread_create(&tid1, NULL, st_cross_thread_access_005_tsk_001, NULL);
	    sleep(4);
	    pthread_mutex_init(&st_cross_thread_access_005_glb_mutex_1, NULL);
	    pthread_create(&tid2, NULL, st_cross_thread_access_005_tsk_002, NULL);
	    pthread_join(tid1, NULL);
	    pthread_join(tid2, NULL);
	    pthread_mutex_destroy(&st_cross_thread_access_005_glb_mutex);
	    pthread_mutex_destroy(&st_cross_thread_access_005_glb_mutex_1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Cross thread stack access
 * Complexity: Cross thread stack access over multiple functions using 2 threads created in else condition
*/
pthread_mutex_t st_cross_thread_access_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t st_cross_thread_access_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1
typedef struct {
	int a;
	int b;
} st_cross_thread_access_006_s_001;
st_cross_thread_access_006_s_001 s1 ={10,20};
st_cross_thread_access_006_s_001 *sptr = &s1;
void * st_cross_thread_access_006_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip *10;
	st_cross_thread_access_006_s_001 s ={1,2};
	for (i=0;i<=4;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &st_cross_thread_access_006_glb_mutex_1 );
			sptr = &s;
			pthread_mutex_unlock( &st_cross_thread_access_006_glb_mutex_1 );

		}
	}
#if defined PRINT_DEBUG
   printf("Task6_1! Cross thread stack access, thread #%ld! aa=%d\n",ip,sptr->a);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * st_cross_thread_access_006_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip *20;
	for (i=0;i<=4;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &st_cross_thread_access_006_glb_mutex_2 );
			if (i==2)
			   sptr->a = 100;  /*Tool should detect this line as error*/ /*ERROR:Cross thread stack access error*/
			pthread_mutex_unlock( &st_cross_thread_access_006_glb_mutex_2 );
		}
	}
#if defined PRINT_DEBUG
	   printf("Task6_2! Cross thread stack access, thread #%ld! \n",ip);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void st_cross_thread_access_006 ()
{
	int thread_set = 0;
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   intptr_t t1 = 10;
	   intptr_t t2 = 20;
	   if ( thread_set == CREATE_THREAD)
	   {
           ;
	   }
	   else
	   {
		   pthread_create(&th1, NULL, st_cross_thread_access_006_tsk_001, (void *)t1);
		   pthread_create(&th2, NULL, st_cross_thread_access_006_tsk_002, (void *)t2);
		   sleep(1);
	   }

#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Cross thread stack access
 * Cross thread stack access main function
 */
extern volatile int vflag;
void st_cross_thread_access_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		st_cross_thread_access_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		st_cross_thread_access_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		st_cross_thread_access_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		st_cross_thread_access_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		st_cross_thread_access_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		st_cross_thread_access_006();
	}
}
#endif
