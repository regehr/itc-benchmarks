/********Software Analysis - FY2013*************/
/*
* File Name: double_release.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Double release
* Description: Defect Free Code to identify false positives in double release - concurrency defects
*/

/*You can specify the-lpthread to include <pthread.h>  Compile options */

#include "HeaderFile.h"

int rand (void);

/*
* Types of defects: double release
* Complexity: double release
*/
pthread_mutex_t double_release_001_glb_mutex_;
pthread_mutex_t * double_release_001_glb_mutex = & double_release_001_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_001_glb_mutex_lock () {}
void double_release_001_glb_mutex_unlock () {}
/* # Endif  # if defined (CHECKER_POLYSPACE) */

int double_release_001_glb_data = 0;

void * double_release_001_tsk_001 (void * pram)
{
	pthread_mutex_lock (double_release_001_glb_mutex);
    double_release_001_glb_data = (double_release_001_glb_data% 100) + 1;
    pthread_mutex_unlock (double_release_001_glb_mutex); /*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
    return NULL;
}

void double_release_001 ()
{
	pthread_t tid1;
    pthread_mutex_init (double_release_001_glb_mutex, NULL);
    pthread_create (& tid1, NULL, double_release_001_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (double_release_001_glb_mutex);
}

/* # If defined (CHECKER_POLYSPACE) */
void double_release_001_tskentry_001 ()
{
	while (1)
   {
		if (rand ())
        {
			double_release_001_tsk_001 (NULL);
        }
    }
}
/* # Endif  defined (CHECKER_POLYSPACE) */

/*
* Types of defects: double release
* Complexity:Unlock without locking
*/

pthread_mutex_t double_release_002_glb_mutex_;
pthread_mutex_t * double_release_002_glb_mutex = &double_release_002_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_002_glb_mutex_lock () {}
void double_release_002_glb_mutex_unlock () {}
/* # Endif # if defined (CHECKER_POLYSPACE) */

int double_release_002_glb_data = 0;

void * double_release_002_tsk_001 (void * pram)
{
	pthread_mutex_lock (double_release_002_glb_mutex);
	double_release_002_glb_data = (double_release_002_glb_data% 100) + 1;
	pthread_mutex_unlock (double_release_002_glb_mutex);
	return NULL;
}

void * double_release_002_tsk_002 (void * pram)
{
	pthread_mutex_lock (double_release_002_glb_mutex);
	double_release_002_glb_data = (double_release_002_glb_data% 100) + 1;
	pthread_mutex_unlock (double_release_002_glb_mutex);
	return NULL;
}

void double_release_002 ()
{
	pthread_t tid1,tid2;
    pthread_mutex_init (double_release_002_glb_mutex, NULL);
    pthread_create (& tid1, NULL, double_release_002_tsk_001, NULL);
    pthread_create (& tid2, NULL, double_release_002_tsk_002, NULL);
    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);
    pthread_mutex_destroy (double_release_002_glb_mutex);
}
/* # if defined (CHECKER_POLYSPACE) */
void double_release_002_tskentry_001 ()
{
	while (1)
    {
		if (rand ())
		{
			double_release_002_tsk_001 (NULL);
		}
    }
}
/* # endif  defined (CHECKER_POLYSPACE) */

/*
* Types of defects: double Release
* Complexity: double release across function 
*/
pthread_mutex_t double_release_003_glb_mutex_;
pthread_mutex_t * double_release_003_glb_mutex = & double_release_003_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_003_glb_mutex_lock () {}
void double_release_003_glb_mutex_unlock () {}
/* # Endif  # if defined (CHECKER_POLYSPACE) */

int double_release_003_glb_data = 0;

void double_release_003_func_001 ()
{
	pthread_mutex_unlock (double_release_003_glb_mutex);
}

void * double_release_003_tsk_001 (void * pram)
{
	pthread_mutex_lock (double_release_003_glb_mutex);
	double_release_003_glb_data = (double_release_003_glb_data% 100) + 1;
	double_release_003_func_001 (); /*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
	return NULL;
}

void double_release_003 ()
{
	pthread_t tid1;
	pthread_mutex_init (double_release_003_glb_mutex, NULL);
	pthread_create (& tid1, NULL, double_release_003_tsk_001, NULL);
	pthread_join (tid1, NULL);
	pthread_mutex_destroy (double_release_003_glb_mutex);
}

/* # If defined (CHECKER_POLYSPACE) */
void double_release_003_tskentry_001 ()
{
	while (1)
	{
		if (rand ())
		{
			double_release_003_tsk_001 (NULL);
		}
	}
}
/* # Endif defined (CHECKER_POLYSPACE) */

/*
* Types of defects: double Release
* Complexity: double release inside and outside a loop
*/
pthread_mutex_t double_release_004_glb_mutex_;
pthread_mutex_t * double_release_004_glb_mutex = & double_release_004_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_004_glb_mutex_lock () {}
void double_release_004_glb_mutex_unlock () {}
/* # Endif # if defined (CHECKER_POLYSPACE) */

int double_release_004_glb_data = 0;

void * double_release_004_tsk_001 (void * pram)
{
	int i;
	for(i=0;i<2;i++)
	{
		pthread_mutex_lock (double_release_004_glb_mutex);
		double_release_004_glb_data = (double_release_004_glb_data% 100) + 1;
		pthread_mutex_unlock (double_release_004_glb_mutex); /*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
	}
    return NULL;
}

void double_release_004 ()
{
	pthread_t tid1;
    pthread_mutex_init (double_release_004_glb_mutex, NULL);
    pthread_create (& tid1, NULL, double_release_004_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (double_release_004_glb_mutex);
}

/* # If defined (CHECKER_POLYSPACE) */
void double_release_004_tskentry_001 ()
{
	while (1)
	{
		if (rand ())
		{
			double_release_004_tsk_001 (NULL);
		}
	}
}
/* # Endif defined (CHECKER_POLYSPACE) */



/*
* Types of defects: double Release
* Complexity: double release inside a loop
*/
pthread_mutex_t double_release_005_glb_mutex_;
pthread_mutex_t * double_release_005_glb_mutex = & double_release_005_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_005_glb_mutex_lock () {}
void double_release_005_glb_mutex_unlock () {}
/* # Endif / * # if defined (CHECKER_POLYSPACE) */

int double_release_005_glb_data = 0;

void * double_release_005_tsk_001 (void * pram)
{
	int i;
	pthread_mutex_lock (double_release_005_glb_mutex);
	double_release_005_glb_data = (double_release_005_glb_data% 100) + 1;
	for(i=0;i<1;i++)
	{
		pthread_mutex_unlock (double_release_005_glb_mutex);  /*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
	}
	return NULL;
}

void double_release_005 ()
{
	pthread_t tid1;
    pthread_mutex_init (double_release_005_glb_mutex, NULL);
    pthread_create (& tid1, NULL, double_release_005_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (double_release_005_glb_mutex);
}

/* # If defined (CHECKER_POLYSPACE) */
void double_release_005_tskentry_001 ()
{
	while (1)
	{
		if (rand ())
		{
			double_release_005_tsk_001 (NULL);
		}
	}
}
/* # Endif defined (CHECKER_POLYSPACE) */
/*
* Types of defects: double Release
* Complexity: Second release in if condition
*/
pthread_mutex_t double_release_006_glb_mutex_;
pthread_mutex_t * double_release_006_glb_mutex = & double_release_006_glb_mutex_;
/* # If defined (CHECKER_POLYSPACE) */
void double_release_006_glb_mutex_lock () {}
void double_release_006_glb_mutex_unlock () {}
/* # Endif # if defined (CHECKER_POLYSPACE) */

int double_release_006_glb_data = 0;

void * double_release_006_tsk_001 (void * pram)
{
	pthread_mutex_lock (double_release_006_glb_mutex);
	double_release_006_glb_data = (double_release_006_glb_data% 100) + 1;
	pthread_mutex_unlock (double_release_006_glb_mutex);/*Tool should not detect this line as error*/ /*No ERROR:Double UnLock*/
	return NULL;
}

void double_release_006 ()
{
	pthread_t tid1;
    pthread_mutex_init (double_release_006_glb_mutex, NULL);
    pthread_create (& tid1, NULL, double_release_006_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (double_release_006_glb_mutex);
}

/* # If defined (CHECKER_POLYSPACE) */
void double_release_006_tskentry_001 ()
{
	while (1)
	{
		if (rand ())
		{
			double_release_006_tsk_001 (NULL);
		}
	}
}
/* # Endif defined (CHECKER_POLYSPACE) */
/*
*
*/
extern volatile int vflag;
void double_release_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		double_release_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		double_release_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		double_release_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		double_release_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		double_release_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		double_release_006();
	}
}
