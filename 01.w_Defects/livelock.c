/********Software Analysis - FY2013*************/
/*
* File Name: data_lost.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Live lock
*
*/


/* Livelock
 * Complexity: Thread 1 and thread 2 try to give up the 
 * control of the thread.This leads to the system not progressing further.
 */

#include "HeaderFile.h"

pthread_mutex_t livelock_001_glb_A;
pthread_mutex_t livelock_001_glb_B;

int x,y;

void *mythreadA(void *pram)
{
	while(1)
	{
		pthread_mutex_lock(&livelock_001_glb_A);
		x=x+1;
		pthread_mutex_unlock(&livelock_001_glb_A);

		int status=pthread_mutex_trylock(&livelock_001_glb_B);
		if(status==0)
		{
			continue;
		}
	}
    return NULL;
}

void* mythreadB()
{
	while(1)
	{
		pthread_mutex_lock(&livelock_001_glb_B);
		y=y+1;
		pthread_mutex_unlock(&livelock_001_glb_B);

		int status=pthread_mutex_trylock(&livelock_001_glb_A);
		if(status==0)
		{
			continue;
		}
	}
    return NULL;
}

void livelock_001()
{
	pthread_t pthreadA,pthreadB;

	pthread_mutex_init(&livelock_001_glb_A,NULL);
	pthread_mutex_init(&livelock_001_glb_B,NULL );

	pthread_create(&pthreadA,NULL,mythreadA,NULL);
	pthread_create(&pthreadB,NULL,(void *) &mythreadB,NULL);

	pthread_join(pthreadA,NULL);
	pthread_join(pthreadB,NULL);
		
}

extern volatile int vflag;
void livelock_main ()
{

	if (vflag> 0)
	{
		livelock_001 ();
	}

}
