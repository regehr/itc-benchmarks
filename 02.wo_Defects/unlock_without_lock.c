/********Software Analysis - FY2013*************/
/*
* File Name: unlock_without_lock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Unlock without lock
* Description: Defect Free Code to identify false positives to identify if a shared resource is unlocked without preceeding lock
*/


/* #include <pthread.h>	Compile-time options. -lpthread You can specify */
#include "HeaderFile.h"

/* Polyspace Does not support Concurrency */


#if defined(CHECKER_POLYSPACE)
# define NULL ((void *) 0)
int rand (void);
#endif /* defined(CHECKER_POLYSPACE) */
/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock in same function using two thread
 */

pthread_mutex_t unlock_without_lock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_001_glb_mutex_lock () {}
void unlock_without_lock_001_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */
#ifndef __NO_POLYSPACE__

int unlock_without_lock_001_glb_data = 0;

void * unlock_without_lock_001_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	char * th = (char *)pram;
	pthread_mutex_lock(&unlock_without_lock_001_glb_mutex);
	unlock_without_lock_001_glb_data = (unlock_without_lock_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&unlock_without_lock_001_glb_mutex);	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */

	unsigned long ip = (unsigned long)pthread_self();
    printf("Task1! Unlock without Lock, threadID# %lu! thread no = %s \n",ip ,th);
#endif /* defined(CHECKER_POLYSPACE) */
    return NULL;
}

void unlock_without_lock_001 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	const char *t1 = "THREAD1";
	const char *t2 = "THREAD2";
	pthread_mutex_init(&unlock_without_lock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_001_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, unlock_without_lock_001_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&unlock_without_lock_001_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_001_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			unlock_without_lock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Unlock without Lock
 * Complexity: unLocking without locking in same function using two thread inside a if condition
 */
pthread_mutex_t unlock_without_lock_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_002_glb_mutex_lock () {}
void unlock_without_lock_002_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

unsigned long unlock_without_lock_002_glb_data = 0;
int const unlock_without_lock_002_var = 10;
void * unlock_without_lock_002_tsk_001 (void * pram)
{
#if !defined(CHECKER_POLYSPACE)
	if(unlock_without_lock_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&unlock_without_lock_002_glb_mutex);
	    unlock_without_lock_002_glb_data = (unlock_without_lock_002_glb_data % 100) + 1;
	    pthread_mutex_unlock(&unlock_without_lock_002_glb_mutex);
	}
	if(unlock_without_lock_002_var == (intptr_t)pram)
	{
		pthread_mutex_lock(&unlock_without_lock_002_glb_mutex);
	    unlock_without_lock_002_glb_data = (unlock_without_lock_002_glb_data % 100) + 1;
#if defined PRINT_DEBUG
	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task2! Unlock without Lock, threadID # %lu! gbl2 = %lu \n",ip ,unlock_without_lock_002_glb_data);
#endif /* defined(PRINT_DEBUG) */
        pthread_mutex_unlock(&unlock_without_lock_002_glb_mutex);	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
	}
#endif /* defined(CHECKER_POLYSPACE) */
	return NULL;
}

void unlock_without_lock_002 ()
{
#if !defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	intptr_t const unlock_without_lock_002_t1 = 10;
	intptr_t const unlock_without_lock_002_t2 = 20;
	pthread_mutex_init(&unlock_without_lock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t1);
	pthread_create(&tid2, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_002_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			unlock_without_lock_002_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions , 2 threads,based on return value of function
 */
pthread_mutex_t unlock_without_lock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_003_glb_mutex_lock () {}
void unlock_without_lock_003_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

float unlock_without_lock_003_glb_data = 1000.0;

int unlock_without_lock_003_func_002 (int a );
void unlock_without_lock_003_func_001 (void *pram)
{
#if ! defined(CHECKER_POLYSPACE)
  if (unlock_without_lock_003_func_002(10) >1) {
    pthread_mutex_lock (&unlock_without_lock_003_glb_mutex);	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
  }
  unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 1.2;

#if defined PRINT_DEBUG
  int ip = (intptr_t)pram;
  printf("Task3! Unlock without Lock, thread # %d! gbl3 = %f \n",ip ,unlock_without_lock_003_glb_data);
#endif /* defined(PRINT_DEBUG) */
  unlock_without_lock_003_func_002(10);
  if(unlock_without_lock_003_func_002(10) >1) {
    pthread_mutex_unlock (&unlock_without_lock_003_glb_mutex);
  }
#endif /* ! defined(CHECKER_POLYSPACE) */
}

int unlock_without_lock_003_func_002 (int a )
{
  int ret = 0;
  if (a > 1) {
    ret = a++;
  } else {
    ret = 0;
  }
  return ret;
}

void* unlock_without_lock_003_tsk_001 (void *pram)
{
#if ! defined(CHECKER_POLYSPACE)

  if(unlock_without_lock_003_func_002(10) >1) {
    pthread_mutex_lock (&unlock_without_lock_003_glb_mutex);
  }
  unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 3.5;
  // JDR: commenting out next line which deadlocks us due to taking a lock twice
  // unlock_without_lock_003_func_001(pram);
  if(unlock_without_lock_003_func_002(10) > 1) {
    pthread_mutex_unlock(&unlock_without_lock_003_glb_mutex);
  }
#endif /* defined(CHECKER_POLYSPACE) */
  return NULL;
}

void unlock_without_lock_003 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t tid1,tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&unlock_without_lock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, unlock_without_lock_003_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&unlock_without_lock_003_glb_mutex);
#endif /* defined(CHECKER_POLYSPACE) */
}

#if defined(CHECKER_POLYSPACE)
void unlock_without_lock_003_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			unlock_without_lock_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t unlock_without_lock_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_004_glb_var = 0;
void *unlock_without_lock_004_tsk_001(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_004_glb_mutex_1 );

#if defined PRINT_DEBUG
   printf("Task4_1! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
               unlock_without_lock_004_glb_var += 20;
               pthread_mutex_unlock( &unlock_without_lock_004_glb_mutex_1 );
		   }
		   i--;
	}
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * unlock_without_lock_004_tsk_002(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_004_glb_mutex_2 );	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
               unlock_without_lock_004_glb_var += 5;
			   pthread_mutex_unlock( &unlock_without_lock_004_glb_mutex_2 );
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task4_2! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void unlock_without_lock_004 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
    pthread_create(&th1, NULL, unlock_without_lock_004_tsk_001, (void *)t1);
    pthread_create(&th2, NULL, unlock_without_lock_004_tsk_002, (void *)t2);
	sleep(1);
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Thread created in else condition , no lock but there is a unlock
 */
pthread_mutex_t unlock_without_lock_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_005_glb_data = 0;

# define NO_THREAD 0
int unlock_without_lock_005_thread_set = 1;

void * unlock_without_lock_005_tsk_001 (void *pram)
{
#if !defined(CHECKER_POLYSPACE)
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_mutex_lock(&unlock_without_lock_005_glb_mutex);
	    unlock_without_lock_005_glb_data = (unlock_without_lock_005_glb_data % 100) + 5;
	    pthread_mutex_unlock(&unlock_without_lock_005_glb_mutex);	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */

	    unsigned long ip = (unsigned long)pthread_self();
        printf("Task5! Unlock without Lock, threadID# %lu! gbl5 = %d \n",ip ,unlock_without_lock_005_glb_data);
#endif /* defined(CHECKER_POLYSPACE) */
	}
    return NULL;
}

void unlock_without_lock_005 ()
{
#if !defined(CHECKER_POLYSPACE)
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
	    pthread_mutex_init(&unlock_without_lock_005_glb_mutex, NULL);
	    pthread_create(&tid1, NULL, unlock_without_lock_005_tsk_001, NULL);
	    pthread_join(tid1, NULL);
	    pthread_mutex_destroy(&unlock_without_lock_005_glb_mutex);
	}
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads created in else condition
*/
pthread_mutex_t unlock_without_lock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1
char unlock_without_lock_006_glb_buf[5]="BBBBB";
void * unlock_without_lock_006_tsk_001(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	int i;
	ip = (long)input;
	ip = ip *10;
	for (i=0;i<5;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &unlock_without_lock_006_glb_mutex_1 );	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
			unlock_without_lock_006_glb_buf[i] = 'a';
			pthread_mutex_unlock( &unlock_without_lock_006_glb_mutex_1 );
		}
	}
#if defined PRINT_DEBUG
   printf("Task6_1! Unlock without Lock, thread #%ld! buf %s\n",ip,unlock_without_lock_006_glb_buf);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */

   return NULL;
}

void * unlock_without_lock_006_tsk_002(void *input)
{
#if ! defined(CHECKER_POLYSPACE)
	long ip;
	ip = (long)input;
	ip = ip *20;
	if (ip >= 0)
	{
		pthread_mutex_lock( &unlock_without_lock_006_glb_mutex_2 );
        strcpy(unlock_without_lock_006_glb_buf,"STRI");
		pthread_mutex_unlock( &unlock_without_lock_006_glb_mutex_2 );
	}
#if defined PRINT_DEBUG
   printf("Task6_2! Unlock without Lock, thread #%ld! buf = %s\n",ip,unlock_without_lock_006_glb_buf);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void unlock_without_lock_006 ()
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
		pthread_create(&th1, NULL, unlock_without_lock_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, unlock_without_lock_006_tsk_002, (void *)t2);
		sleep(1);
	}

#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t unlock_without_lock_007_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_007_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_007_glb_var = 0;
void *unlock_without_lock_007_tsk_001(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_007_glb_mutex_1 );
			   unlock_without_lock_007_glb_var += 10;
			   pthread_mutex_unlock( &unlock_without_lock_007_glb_mutex_1 );
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task7_1! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * unlock_without_lock_007_tsk_002(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_007_glb_mutex_2 );

			   /* if(i!=5) */
			   {
				   unlock_without_lock_007_glb_var += 20;
				   pthread_mutex_unlock( &unlock_without_lock_007_glb_mutex_2 );	/*Tool should not detect this line as error*/ /* No ERROR:UnLock without lock */
			   }
		   }
		   i--;
	}
#if defined PRINT_DEBUG
   printf("Task7_2! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void unlock_without_lock_007 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   long int t1 = 10;
	   long int t2 = 20;
	   pthread_create(&th1, NULL, unlock_without_lock_007_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, unlock_without_lock_007_tsk_002, (void *)t2);
	   pthread_join(th1, NULL);
	   pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Unlock without Lockk
 * Complexity: Unlock without Lockk over multiple functions using 2 threads inside do-while loop and if condition
 */
pthread_mutex_t unlock_without_lock_008_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_008_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_008_glb_var = 0;
void *unlock_without_lock_008_tsk_001(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_008_glb_mutex_1 );
			   unlock_without_lock_008_glb_var += 10;
			   pthread_mutex_unlock( &unlock_without_lock_008_glb_mutex_1 );
		   }
		   i--;
	}while (i>0);
#if defined PRINT_DEBUG
   printf("Task8_1! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void * unlock_without_lock_008_tsk_002(void *input)
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
			   pthread_mutex_lock( &unlock_without_lock_008_glb_mutex_2 );

			   if(i!=6)
			   {
				   unlock_without_lock_008_glb_var += 20;
				   pthread_mutex_unlock( &unlock_without_lock_008_glb_mutex_2 );/*Tool should not detect this line as error*/ /* No ERROR:Unlock without Lock */
			   }
		   }
		   i--;
	}	while (i>0);
#if defined PRINT_DEBUG
   printf("Task8_2! Unlock without Lock, thread #%ld!\n",ip);
#endif /* defined(PRINT_DEBUG) */
#endif /* defined(CHECKER_POLYSPACE) */
   return NULL;
}

void unlock_without_lock_008 ()
{
#if ! defined(CHECKER_POLYSPACE)
	pthread_t th1,th2;
	   long int t1 = 10;
	   long int t2 = 20;
	   pthread_create(&th1, NULL, unlock_without_lock_008_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, unlock_without_lock_008_tsk_002, (void *)t2);
	   pthread_join(th1, NULL);
	   pthread_join(th2, NULL);
#endif /* defined(CHECKER_POLYSPACE) */
}

/*
 * Types of defects: Unlock without Lock
 * Unlock without Lock main function
 */
extern volatile int vflag;
void unlock_without_lock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		unlock_without_lock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		unlock_without_lock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		unlock_without_lock_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		unlock_without_lock_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		unlock_without_lock_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		unlock_without_lock_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		unlock_without_lock_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		unlock_without_lock_008();
	}
}
#endif
