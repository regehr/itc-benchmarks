/********Software Analysis - FY2013*************/
/*
* File Name: sleep_lock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Long lock
*
*/

/*
* #include <pthread.h>
* Compile-time options. -lpthread You can specify
*#include <sys/socket.h>
*#include <netinet/in.h>
*#include <unistd.h>
*#include <string.h>

*#include "stubs.h"
*/
#include "HeaderFile.h"
#ifndef __NO_COVERITY__

#include <sys/socket.h>

#include <netinet/in.h>
#endif
#define NULL ((void *)0)
int rand (void);

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
#ifndef __NO_COVERITY__
	sleep(3600);/*Tool should detect this line as error*/ /*Error:Long Sleep */
#endif
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

/* #if defined(CHECKER_POLYSPACE) */
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
/* #endif defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: long lock time
 * Complexity: wait socket
 */
pthread_mutex_t sleep_lock_002_glb_mutex_;
pthread_mutex_t *sleep_lock_002_glb_mutex = &sleep_lock_002_glb_mutex_;
/* #if defined(CHECKER_POLYSPACE) */
void sleep_lock_002_glb_mutex_lock () {}
void sleep_lock_002_glb_mutex_unlock () {}
/* #endif  #if defined(CHECKER_POLYSPACE) */

char sleep_lock_002_glb_data[256];
int sleep_lock_002_glb_size;

void* sleep_lock_002_tsk_001 (void *pram)
{
	int ret;
	int sock;
#ifndef __NO_COVERITY__
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		return NULL;
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = INADDR_ANY;
	ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
#endif
	if (ret != 0)
	{
		close(sock);
		return NULL;
	}

	/* Lock */
	pthread_mutex_lock(sleep_lock_002_glb_mutex);

	/* Incoming */
#ifndef __NO_COVERITY__

	sleep_lock_002_glb_size =
		recv(sock, sleep_lock_002_glb_data, 256, 0);
	sleep(3600);/*Tool should detect this line as error*/ /*Error:Long Sleep */
#endif

	/* Lock or unlock */
	pthread_mutex_unlock(sleep_lock_002_glb_mutex);

	close(sock);
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

/* #if defined(CHECKER_POLYSPACE) */
void sleep_lock_002_tskentry_001 ()
{
	while (1)
	{
		if (rand())
		{
			sleep_lock_002_tsk_001(NULL);
		}
	}
}
/* #endif  defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: long lock time
 * Complexity: across the function long time sleep
 */
pthread_mutex_t sleep_lock_003_glb_mutex_;
pthread_mutex_t *sleep_lock_003_glb_mutex = &sleep_lock_003_glb_mutex_;
/* #if defined(CHECKER_POLYSPACE) */
void sleep_lock_003_glb_mutex_lock () {}
void sleep_lock_003_glb_mutex_unlock () {}
/* #endif  #if defined(CHECKER_POLYSPACE) */

int sleep_lock_003_glb_data = 0;

void sleep_lock_003_func_001 ()
{
#ifndef __NO_COVERITY__

	sleep(3600);/*Tool should detect this line as error*/ /*Error:Long Sleep */
#endif
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

/* #if defined(CHECKER_POLYSPACE) */
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
/* #endif  defined(CHECKER_POLYSPACE) */

/*
 * Types of defects: long lock time
 * Complexity: volatile
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
