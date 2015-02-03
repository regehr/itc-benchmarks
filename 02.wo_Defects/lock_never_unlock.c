/********Software Analysis - FY2013*************/
/*
* File Name: lock_never_unlock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Locked but never unlock
* Description: Defect Free Code to identify false positives while there has been a lock of a resource and never unlocked scenario
*/


/* #include <pthread.h>	Compile-time options. -lpthread You can specify */
#include "HeaderFile.h"

/* Polyspace Does not support Concurrency */

#if defined(CHECKER_POLYSPACE)
# define NULL ((void *) 0)
int rand (void);
#endif /* defined(CHECKER_POLYSPACE) */
/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock in same function using one thread
 */

pthread_mutex_t lock_never_unlock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_001_glb_mutex_lock () {}
void lock_never_unlock_001_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int lock_never_unlock_001_glb_data = 0;

void * lock_never_unlock_001_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_001_glb_mutex);
	lock_never_unlock_001_glb_data = (lock_never_unlock_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&lock_never_unlock_001_glb_mutex);     /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */

	unsigned long ip = (unsigned long)pthread_self();
    printf("Task1! Lock Never Unlock, threadID# %lu! gbl1 = %d \n",ip ,lock_never_unlock_001_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
    return NULL;
}

void lock_never_unlock_001 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1;
	pthread_mutex_init(&lock_never_unlock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_001_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&lock_never_unlock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_001_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Locking twice and unlocking only once in same function using two thread
 */
pthread_mutex_t lock_never_unlock_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_002_glb_mutex_lock () {}
void lock_never_unlock_002_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int lock_never_unlock_002_glb_data = 0;

void * lock_never_unlock_002_tsk_001 (void * pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_002_glb_mutex);
	lock_never_unlock_002_glb_data = (lock_never_unlock_002_glb_data % 100) + 1;
	pthread_mutex_unlock(&lock_never_unlock_002_glb_mutex);    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */

	pthread_mutex_lock(&lock_never_unlock_002_glb_mutex);
	lock_never_unlock_002_glb_data = (lock_never_unlock_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
	unsigned long ip = (unsigned long)pthread_self();
    printf("Task2! Lock Never Unlock, threadID # %lu! gbl2 = %d \n",ip ,lock_never_unlock_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
    pthread_mutex_unlock(&lock_never_unlock_002_glb_mutex);

#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_002 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	pthread_mutex_init(&lock_never_unlock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_002_tsk_001, NULL);
	pthread_create(&tid2, NULL, lock_never_unlock_002_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_002_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions , 2 threads
 */
pthread_mutex_t lock_never_unlock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_003_glb_mutex_lock () {}
void lock_never_unlock_003_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

float lock_never_unlock_003_glb_data = 1000.0;

void lock_never_unlock_003_func_001 (void *pram)
{
#if ! defined(CHECKER_POLYSPACE)
    pthread_mutex_lock (&lock_never_unlock_003_glb_mutex);
    lock_never_unlock_003_glb_data = (lock_never_unlock_003_glb_data) + 1.2;

#if defined PRINT_DEBUG
	int ip = (int)pram;
	printf("Task3! Lock Never Unlock, thread # %d! gbl3 = %f \n",ip ,lock_never_unlock_003_glb_data);
#endif /* defined(PRINT_DEBUG) */

    pthread_mutex_unlock (&lock_never_unlock_003_glb_mutex);    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
#endif /* ! defined(CHECKER_POLYSPACE) */
}

void* lock_never_unlock_003_tsk_001 (void *pram)
{
#if ! defined(CHECKER_POLYSPACE)

	pthread_mutex_lock(&lock_never_unlock_003_glb_mutex);
	lock_never_unlock_003_glb_data = (lock_never_unlock_003_glb_data) + 3.5;
	pthread_mutex_unlock(&lock_never_unlock_003_glb_mutex);
	lock_never_unlock_003_func_001(pram);
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void lock_never_unlock_003 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&lock_never_unlock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, lock_never_unlock_003_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock_never_unlock_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void lock_never_unlock_003_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			lock_never_unlock_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads unlocked based on if condition
 */
pthread_mutex_t lock_never_unlock_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
void *lock_never_unlock_004_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;

   pthread_mutex_lock( &lock_never_unlock_004_glb_mutex_1 );
   ip = (long)input;
   ip = ip *10;
#if defined PRINT_DEBUG
   printf("Task4_1! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */

   if (ip >= 0)
   pthread_mutex_unlock( &lock_never_unlock_004_glb_mutex_1 );    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
#endif /* defined(CHECKER_POLYSPACE) */

   return NULL;
}

void * lock_never_unlock_004_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;

   pthread_mutex_lock( &lock_never_unlock_004_glb_mutex_2 );
   ip = (long)input;
   ip = ip *20;

#if defined PRINT_DEBUG
   printf("Task4_2! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
   pthread_mutex_unlock( &lock_never_unlock_004_glb_mutex_2 );
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void lock_never_unlock_004 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   intptr_t t1 = 10;
	   intptr_t t2 = 20;
	   pthread_create(&th1, NULL, lock_never_unlock_004_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, lock_never_unlock_004_tsk_002, (void *)t2);
	   sleep(1);
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Thread created in else condition , no unlock
 */
pthread_mutex_t lock_never_unlock_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_005_glb_data = 0;

# define NO_THREAD 0
int thread_set = 1;

void * lock_never_unlock_005_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	pthread_mutex_lock(&lock_never_unlock_005_glb_mutex);
	lock_never_unlock_005_glb_data = (lock_never_unlock_005_glb_data % 100) + 5;
	pthread_mutex_unlock(&lock_never_unlock_005_glb_mutex);    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */

	unsigned long ip = (unsigned long)pthread_self();
    printf("Task5! Lock Never Unlock, threadID# %lu! gbl5 = %d \n",ip ,lock_never_unlock_005_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
    return NULL;
}

void lock_never_unlock_005 ()
{
#if !defined(CHECKER_POLYSPACE)
	if (thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
	    pthread_mutex_init(&lock_never_unlock_005_glb_mutex, NULL);
	    pthread_create(&tid1, NULL, lock_never_unlock_005_tsk_001, NULL);
	    pthread_join(tid1, NULL);
	    pthread_mutex_destroy(&lock_never_unlock_005_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads created in else condition
 */
pthread_mutex_t lock_never_unlock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1

void * lock_never_unlock_006_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;

   pthread_mutex_lock( &lock_never_unlock_006_glb_mutex_1 );
   ip = (long)input;
   ip = ip *10;
#if defined PRINT_DEBUG
   printf("Task6_1! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */

   if (ip >= 0)
   pthread_mutex_unlock( &lock_never_unlock_006_glb_mutex_1 );    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * lock_never_unlock_006_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;

   pthread_mutex_lock( &lock_never_unlock_006_glb_mutex_2 );
   ip = (long)input;
   ip = ip *20;

#if defined PRINT_DEBUG
   printf("Task6_2! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
   pthread_mutex_unlock( &lock_never_unlock_006_glb_mutex_2 );
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void lock_never_unlock_006 ()
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
		pthread_create(&th1, NULL, lock_never_unlock_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, lock_never_unlock_006_tsk_002, (void *)t2);
		sleep(1);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t lock_never_unlock_007_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_007_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_007_glb_var = 0;
void *lock_never_unlock_007_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_007_glb_mutex_1 );
			   lock_never_unlock_007_glb_var += 10;
			   pthread_mutex_unlock( &lock_never_unlock_007_glb_mutex_1 );
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task7_1! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * lock_never_unlock_007_tsk_002(void *input)
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
			   pthread_mutex_lock( &lock_never_unlock_007_glb_mutex_2 );

			   /* if(i!=5) */
			   {
				   lock_never_unlock_007_glb_var += 20;
				   pthread_mutex_unlock( &lock_never_unlock_007_glb_mutex_2 );    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
			   }
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task7_2! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void lock_never_unlock_007 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   intptr_t t1 = 10;
	   intptr_t t2 = 20;
	   pthread_create(&th1, NULL, lock_never_unlock_007_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, lock_never_unlock_007_tsk_002, (void *)t2);
	   pthread_join(th1, NULL);
	   pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads created in else condition
*/
pthread_mutex_t lock_never_unlock_008_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_008_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1
typedef struct {
	int a;
	int b;
} lock_never_unlock_008_s_001;
lock_never_unlock_008_s_001 lock_never_unlock_008_glb_sptr ={0};
void * lock_never_unlock_008_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip *10;
	for (i=0;i<=4;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &lock_never_unlock_008_glb_mutex_1 );
			lock_never_unlock_008_glb_sptr.a += 10;
			if(i!=5)
			   pthread_mutex_unlock( &lock_never_unlock_008_glb_mutex_1 );    /*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
		}
	}
#if defined PRINT_DEBUG
   printf("Task8_1! Lock But Never Unlock, thread #%ld! aa=%d\n",ip,lock_never_unlock_008_glb_sptr.a);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * lock_never_unlock_008_tsk_002(void *input)
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
			pthread_mutex_lock( &lock_never_unlock_008_glb_mutex_2 );
			lock_never_unlock_008_glb_sptr.a += 20;
			pthread_mutex_unlock( &lock_never_unlock_008_glb_mutex_2 );
		}
	}
#if defined PRINT_DEBUG
	   printf("Task8_2! Lock But Never Unlock, thread #%ld! aa=%d\n",ip,lock_never_unlock_008_glb_sptr.a);
#endif /* defined(PRINT_DEBUG) */

#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void lock_never_unlock_008 ()
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
		   pthread_create(&th1, NULL, lock_never_unlock_008_tsk_001, (void *)t1);
		   pthread_create(&th2, NULL, lock_never_unlock_008_tsk_002, (void *)t2);
		   sleep(1);
	   }

#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads inside do-while loop and if condition
 */
pthread_mutex_t lock_never_unlock_009_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_009_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_009_glb_var = 0;
void *lock_never_unlock_009_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	do
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_009_glb_mutex_1 );
			   lock_never_unlock_009_glb_var += 10;
			   pthread_mutex_unlock( &lock_never_unlock_009_glb_mutex_1 );
		   }
		   i--;
	}while (i>0);
#if defined PRINT_DEBUG
   printf("Task7_1! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * lock_never_unlock_009_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
     do
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_009_glb_mutex_2 );

			   if(i!=6)
			   {
				   lock_never_unlock_009_glb_var += 20;
				   pthread_mutex_unlock( &lock_never_unlock_009_glb_mutex_2 );/*Tool should not detect this line as error*/ /* No ERROR:Lock Never Unlock */
			   }
		   }
		   i--;
	}	while (i>0);
#if defined PRINT_DEBUG
   printf("Task7_2! Lock Never Unlock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void lock_never_unlock_009 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   intptr_t t1 = 10;
	   intptr_t t2 = 20;
	   pthread_create(&th1, NULL, lock_never_unlock_009_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, lock_never_unlock_009_tsk_002, (void *)t2);
	   pthread_join(th1, NULL);
	   pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}


/*
 * Types of defects: Lock But Never Unlock
 * Lock But Never Unlock main function
 */
extern volatile int vflag;
void lock_never_unlock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		lock_never_unlock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		lock_never_unlock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		lock_never_unlock_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		lock_never_unlock_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		lock_never_unlock_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		lock_never_unlock_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		lock_never_unlock_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		lock_never_unlock_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		lock_never_unlock_009();
	}


}
#endif
