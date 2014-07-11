/********Software Analysis - FY2013*************/
/*
* File Name: sleep_lock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Long lock
* Description: Defect Free Code to identify false positives of long lock conditions
*/
/***
#include <pthread.h>	 Compile-time options. -lpthread You can specify*/

#include "HeaderFile.h"


#if defined(CHECKER_POLYSPACE)
int rand (void);
#endif /* defined(CHECKER_POLYSPACE) */
/*
 * Types of defects: long lock time
 * Complexity: long time sleep
 */
pthread_mutex_t sleep_lock_001_glb_mutex_;
pthread_mutex_t *sleep_lock_001_glb_mutex = &sleep_lock_001_glb_mutex_;
/* #if defined(CHECKER_POLYSPACE) */
void sleep_lock_001_glb_mutex_lock () {}
void sleep_lock_001_glb_mutex_unlock () {}
/* #endif  #if defined(CHECKER_POLYSPACE) */

int sleep_lock_001_glb_data = 0;

void* sleep_lock_001_tsk_001 (void *pram)
{
	pthread_mutex_lock(sleep_lock_001_glb_mutex);
	sleep_lock_001_glb_data = (sleep_lock_001_glb_data % 100) + 1;

    /*Tool should not detect this line as error*/ /*No Error:Long Sleep */

	pthread_mutex_unlock(sleep_lock_001_glb_mutex);
	return NULL;
}

void sleep_lock_001 ()
{
	pthread_t tid1;
	pthread_mutex_init(sleep_lock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, sleep_lock_001_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(sleep_lock_001_glb_mutex);
}

#if defined(CHECKER_POLYSPACE)
void sleep_lock_001_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			sleep_lock_001_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: long lock time
 * Complexity: wait socket
 */
int sleep_lock_002_glb_data = 0;
pthread_mutex_t sleep_lock_002_glb_mutex_;
pthread_mutex_t *sleep_lock_002_glb_mutex = &sleep_lock_002_glb_mutex_;
void* sleep_lock_002_tsk_001 (void *pram)
{
	pthread_mutex_lock(sleep_lock_002_glb_mutex);
	sleep_lock_002_glb_data = (sleep_lock_002_glb_data % 100) + 1;
    /*Tool should not detect this line as error*/ /*No Error:Long Sleep */
	pthread_mutex_unlock(sleep_lock_002_glb_mutex);
	return NULL;
}

void sleep_lock_002 ()
{
	pthread_t tid1;
	pthread_mutex_init(sleep_lock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, sleep_lock_002_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(sleep_lock_002_glb_mutex);
}

/*
 * Types of defects: long lock time
 * Complexity: across the function long time sleep
 */
pthread_mutex_t sleep_lock_003_glb_mutex_;
pthread_mutex_t *sleep_lock_003_glb_mutex = &sleep_lock_003_glb_mutex_;
#if defined(CHECKER_POLYSPACE)
void sleep_lock_003_glb_mutex_lock () {}
void sleep_lock_003_glb_mutex_unlock () {}
#endif /* #if defined(CHECKER_POLYSPACE) */

int sleep_lock_003_glb_data = 0;

void sleep_lock_003_func_001 ()
{
	/* Do nothing */
    /*Tool should not detect this line as error*/ /*No Error:Long Sleep */
}

void* sleep_lock_003_tsk_001 (void *pram)
{
	pthread_mutex_lock(sleep_lock_003_glb_mutex);
	sleep_lock_003_glb_data = (sleep_lock_003_glb_data % 100) + 1;

	sleep_lock_003_func_001();

	pthread_mutex_unlock(sleep_lock_003_glb_mutex);
	return NULL;
}

void sleep_lock_003 ()
{
	pthread_t tid1;
	pthread_mutex_init(sleep_lock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, sleep_lock_003_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(sleep_lock_003_glb_mutex);
}

#if defined(CHECKER_POLYSPACE)
void sleep_lock_003_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			sleep_lock_003_tsk_001(NULL);
		}
	}
}
#endif /* defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: long lock time
 * long time sleep Main function
 */
extern volatile int vflag;
void sleep_lock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		sleep_lock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		sleep_lock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		sleep_lock_003();
	}
}
