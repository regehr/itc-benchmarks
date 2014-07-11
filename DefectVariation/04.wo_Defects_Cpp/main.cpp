/********Software Analysis - FY2013*************/
/*
* File Name: main.cpp
* Defect Classification
* ---------------------
* Defect Type: Inappropriate code
* Defect Sub-type: Improper error handling
* Description: Defect Code to identify improper try..catch error handling
* Created on: Nov 8, 2012
*     Author: caesaru01
*/

#include"HeaderFile.hpp"


volatile int vflag;
volatile int vflag_copy;
volatile int vflag_file;

int main(int argc,char*argv[])
{
	if(argv[1])
	{
		vflag_copy = atoi(argv[1]);
	    vflag_file = (int)floor((double)vflag_copy/1000.0);
	    vflag = (int)floor((int)vflag_copy%1000);
	    printf("vflag_file = %d vflag_func = %d vflag_copy =%d \n" , vflag_file, vflag,vflag_copy);
	    if(vflag_file == 1 || vflag_file == 888)
	    {
	    	improper_error_handling_main ();
	    }
	}
	else
	{
		printf("Enter File XXX and Function XXX \n");
		printf("Example: To Execute 1st File 3rd Function , Enter 001003 \n");
		printf("Example: To Execute All Files ,Enter 888888 \n");
		printf("Example: To Execute All functions in a File :Sample - To execute all functions in 1st file,Enter 001888 \n");
	}
    return 0;
}
