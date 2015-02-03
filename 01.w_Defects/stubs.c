/************************************************/
/* Stub created in main body with same timing		*/
/************************************************/

#include "HeaderFile.h"

/* For PolySpace */
#if defined(CHECKER_POLYSPACE)
#include <pthread.h>
#include "stubs.h"

int rand (void);

int pthread_create (
		pthread_t *thread, const pthread_attr_t *attr,
		void *(*start_routine)(void *), void *arg)
{
	*thread = (pthread_t)rand();
	return 0;
}
#endif /* defined(CHECKER_POLYSPACE) */


/* For Prevent*/
#if defined(CHECKER_PREVENT)
#endif /* defined(CHECKER_PREVENT) */


/* For CodeSonar */
#if defined(CHECKER_CODESONAR)
#endif /* defined(CHECKER_CODESONAR) */


/* For K7/
#if defined(CHECKER_K7)
#endif /* defined(CHECKER_K7) */


/* For VARVEL */
#if defined(CHECKER_VARVEL)
#endif /* defined(CHECKER_VARVEL) */


/************************************************/
/* Stub created in main body with different timing	*/
/************************************************/

/* For PolySpace */
#if defined(MKSTUBS_POLYSPACE)
#endif /* defined(MKSTUBS_POLYSPACE) */


/* For Prevent */
#if defined(MKSTUBS_PREVENT)
typedef unsigned int size_t;
typedef unsigned int ssize_t;

unsigned int sleep (unsigned int seconds)
{
	__coverity_sleep__();
	return 0;
}

ssize_t recv (int s, void *buf, size_t len, int flags)
{
	__coverity_sleep__();
	return 0;
}
#endif /* defined(MKSTUBS_PREVENT) */


/* For CodeSonar */
#if defined(MKSTUBS_CODESONAR)
#endif /* defined(MKSTUBS_CODESONAR) */


/* For K7 */
#if defined(MKSTUBS_K7)
#endif /* defined(MKSTUBS_K7) */


/* For VARVEL */
#if defined(MKSTUBS_VARVEL)
#endif /* defined(MKSTUBS_VARVEL) */
