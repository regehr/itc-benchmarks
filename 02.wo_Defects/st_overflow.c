/********Software Analysis - FY2013*************/
/*
* File Name: st_overflow.c
* Defect Classification
* ---------------------
* Defect Type: Stack related defects
* Defect Sub-type: Stack overflow
* Description: Defect Free Code to identify false positives in stack overflow conditions
*/

/*	(Note) created test, assuming the maximum stack size 15 Kbytes (= 15360 bytes)	*/
/* The default stack reservation size used by the linker in windows XP (64bit) is 1 MB(=1048576 bytes)*/

#include "HeaderFile.h"

/*
 * Types of defects: stack overflow
 * Complexity: large internal variables
 */
void st_overflow_001 ()
{
	double buf[1024];/* 1Kbytes */ /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	buf[0] = 1.0;
        sink = buf[idx];
}

 /*
* Types of defects: stack overflow
* Complexity: Level 1 - large function argument function call -
*/
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[524288];	/* 512Kbytes */
	char buf1[65536];	/* 64 Kbytes */
	char buf2[65536];	/* 64 Kbytes */
	char buf3[65536];	/* 64 Kbytes */
	char buf4[65536];	/* 64 Kbytes */
	char buf5[65536];	/* 64 Kbytes */
	char buf6[65536];	/* 64 Kbytes */
	char buf7[65536];	/* 64 Kbytes */
	char buf8[65536];	/* 64 Kbytes */
#else
	char buf[1024];
#endif	/* Prevent failure? Correspondence */

} st_overflow_002_s_001;

void st_overflow_002_func_001 (st_overflow_002_s_001 s)
{
	s.buf[0] = 1;
}

void st_overflow_002 ()
{
	st_overflow_002_s_001 s;		/* 1 Kbytes */
	st_overflow_002_func_001(s);	/* 1 Kbytes */
}

/*
 * Types of defects: stack overflow
 * Complexity: large internal variables	Large function arguments	Function call	Level 1	__
 */
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[524288];	 /* 512 Kbytes */
	char buf1[131072];  /* 128 Kbytes */
	char buf2[131072]; /* 128 Kbytes */
	char buf3[1024];
	char buf4[1024];
#else	/* Prevent failure? Correspondence */
	char buf[1024];
#endif	/* Prevent failure? Correspondence */
} st_overflow_003_s_001;

void st_overflow_003_func_001 (st_overflow_003_s_001 s)
{
	char buf[524288];					/* 512 Kbytes */ /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	s.buf[0] = 1;
	buf[0] = 1;
        sink = buf[idx];
}

void st_overflow_003 ()
{
	st_overflow_003_s_001 s;		/* 5 Kbytes */
	st_overflow_003_func_001(s);	/* 5 Kbytes */
}

/*
 * Types of defects: stack overflow
 * Complexity: large internal variables	Large function arguments	Function call	2 Level	__
 */
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[524288];	/* 512 Kbytes */
	char buf1[131072];/* 128 Kbytes */
	char buf2[1024];
	char buf3[1024];
#else	/* Prevent failure? Correspondence */
	char buf[1024];
	char buf1[1024];
	char buf2[1024];
#endif	/* Prevent failure? Correspondence */
} st_overflow_004_s_001;

void st_overflow_004_func_002 (st_overflow_004_s_001 s)
{
	char buf[131072];					/* 128 Kbytes */
	s.buf[0] = 1;
	buf[0] = 1;
        sink = buf[idx];
}

void st_overflow_004_func_001 (st_overflow_004_s_001 s)
{
	char buf[131072];                 /* 128 Kbytes */ /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	buf[0] = 1;
	st_overflow_004_func_002(s);
        sink = buf[idx];
}

void st_overflow_004 ()
{
	st_overflow_004_s_001 s;
	st_overflow_004_func_001(s);
}

/*
 * Types of defects: stack overflow
 * Complexity: large internal variables	Large function arguments	Recursive function	10 Level	__ __ __ __ __ __ __ __ __ __
 */
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[262144];	/* 256 Kbytes */
#else	/* Prevent failure? Correspondence */
	char buf[1024];
#endif
} st_overflow_005_s_001;

void st_overflow_005_func_001 (st_overflow_005_s_001 s, int cnt)
{
	if (cnt > 0)
	{
		st_overflow_005_func_001(s, cnt - 1);
	}
	else
	{
		s.buf[0] = 1; /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
	}
}

void st_overflow_005 ()
{
	char buf[4096];								/* 4 Kbytes */
	st_overflow_005_s_001 s;
	st_overflow_005_func_001(s, 10);
	buf[0] = 1;
        sink = buf[idx];
}

/*
 * Types of defects: stack overflow
 * Complexity:-	Large function arguments	Function pointer	Level 1	__
 */
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[524288];	 /* 512 Kbytes */
	char buf1[131072];  /* 128 Kbytes */
	char buf2[131072]; /* 128 Kbytes */
	char buf3[1024];
	char buf4[1024];
#else	/* Prevent failure? Correspondence */
	char buf[1024];
#endif	/* Prevent failure? Correspondence */
} st_overflow_006_s_001;

void st_overflow_006_func_001 (st_overflow_006_s_001 s)
{
	char buf[524288];	 /* 512 Kbytes */
	buf[1] = 10;
	s.buf[0] = 1; /*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
        sink = buf[idx];
}

void st_overflow_006 ()
{
	st_overflow_006_s_001 s;
	void (*func)(st_overflow_006_s_001);
	func = st_overflow_006_func_001;
	func(s);
}

/*
 * Types of defects: stack overflow
 * Complexity: large internal variables	Large function arguments	Function call	Level 1	Split condition is
 */
typedef struct {
#if 0	/* Prevent failure? Correspondence */
	char buf[524288];	 /* 512 Kbytes */
	char buf1[131072];  /* 128 Kbytes */
	char buf2[131072]; /* 128 Kbytes */
	char buf3[1024];
	char buf4[1024];
#else	/* Prevent failure? Correspondence */
	char buf[1024];
#endif	/* Prevent failure? Correspondence */
} st_overflow_007_s_001;

void st_overflow_007_func_002 (st_overflow_007_s_001 s);
void st_overflow_007_func_001 (st_overflow_007_s_001 s)
{
	char buf[262144];	/* 256 Kbytes */
	s.buf[0] = 1;
	buf[0] = 1;
	st_overflow_007_func_002(s);
        sink = buf[idx];
}

void st_overflow_007_func_002 (st_overflow_007_s_001 s)
{
	char buf[262144];	/* 256 Kbytes */
	buf[0] = 1;
	s.buf[0] = 1;/*Tool should not detect this line as error*/ /*NO ERROR:Stack overflow*/
        sink = buf[idx];
}

void st_overflow_007 ()
{
	st_overflow_007_s_001 s;			/* 6 Kbytes */
	int flag = 10;
	if (flag)
	{
		st_overflow_007_func_001(s);	/* 6 Kbytes */
	}
	else
	{
		st_overflow_007_func_002(s);	/* 6 Kbytes */
	}
}

/*
 * Types of defects: stack overflow
 * Complexity: stack overflow main function
 */

extern volatile int vflag;
void st_overflow_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		st_overflow_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		st_overflow_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		st_overflow_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		st_overflow_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		st_overflow_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		st_overflow_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		st_overflow_007();
	}
}
