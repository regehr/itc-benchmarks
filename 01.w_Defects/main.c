/*
 ============================================================================
 Description : Main section of Test Suite, Software Analysis - FY2013 (Ansi-style)
 ============================================================================
 */

#include "HeaderFile.h"

volatile int vflag;
volatile int vflag_copy;
volatile int vflag_file;

int idx, sink;
double dsink;
void *psink;

int main(int argc,char*argv[])
{
	if(argv[1])
	{

	vflag_copy = atoi(argv[1]);
	vflag_file = (int)floor((double)vflag_copy/1000.0);
	vflag = (int)floor((int)vflag_copy%1000);
	printf("vflag_file = %d vflag_func = %d vflag_copy =%d \n" , vflag_file, vflag,vflag_copy);
	/* BitShift errors */
	if (vflag_file == 1 || vflag_file == 888)
	{
		bit_shift_main();
	}

	/* Buffer overrun(dynamic buffer) */
	if (vflag_file ==2 || vflag_file == 888)
	{
		dynamic_buffer_overrun_main ();
	}

	/* Buffer underrun(dynamic buffer) */
	if (vflag_file ==3 || vflag_file == 888)
	{
		dynamic_buffer_underrun_main();
	}

	/* Compared to NULL and the function address */
	if (vflag_file ==4 || vflag_file == 888)
	{
		cmp_funcadr_main();
	}

	/* Conflicting Condition */
	if (vflag_file ==5 || vflag_file == 888 )
	{
		conflicting_cond_main();
	}

	/* From the large size of the data type's assignment to small */
	if (vflag_file ==6 || vflag_file == 888)
	{
		data_lost_main();
	}

	/* overrun */
	if (vflag_file ==7 || vflag_file == 888)
	{
		data_overflow_main();
	}

	/* underrun */
	if (vflag_file ==8 || vflag_file == 888)
	{
		data_underflow_main();
	}

	/* Dead code elimination */
	if (vflag_file ==9 || vflag_file == 888)
	{
		dead_code_main();
	}

	/* Dead lock */
	if (vflag_file ==10 || vflag_file == 888)
	{
		dead_lock_main();
	}

    /* Deletion of Structure sentinel */
	if(vflag_file==11 || vflag_file == 888)
	{
		deletion_of_data_structure_sentinel_main ();
	}

	/* Double Free*/
	if (vflag_file ==12 || vflag_file == 888)
	{
		double_free_main ();
	}

	/* Double lock*/
	if (vflag_file ==13 || vflag_file == 888)
	{
		double_lock_main();
	}

	/* Double Release*/
	if (vflag_file ==14 || vflag_file == 888)
	{
		double_release_main();
	}

	/* Unintentional Endless loop */
	if (vflag_file ==15 || vflag_file == 888)
	{
		endless_loop_main();
	}

    /* free non dynamic allocated memory main */
	if(vflag_file==16 || vflag_file == 888)
	{
		free_nondynamic_allocated_memory_main ();
	}

	/* Free NULL Pointer*/
	if (vflag_file ==17 || vflag_file == 888)
	{
		free_null_pointer_main();
	}

	/* Bad function pointer casting */
	if (vflag_file ==18 || vflag_file == 888)
	{
		func_pointer_main();
	}

	/* Return value of function never checked*/
	if (vflag_file ==19 || vflag_file == 888)
	{
		function_return_value_unchecked_main();
	}

	/* improper Error handling  */
	if(vflag_file==20 || vflag_file == 888)
	{
		/*This is Cpp file*/;
	}

	/* improper termination of block */
	if(vflag_file==21 || vflag_file == 888)
	{
		improper_termination_of_block_main ();
	}

	/* Useless assignment */
	if (vflag_file ==22 || vflag_file == 888)
	{
		insign_code_main();
	}

	/* External variable type mistake */
	if (vflag_file ==23 || vflag_file == 888)
	{
		invalid_extern_main();
	}

	/* Invalid Memory Access */
	if (vflag_file ==24 || vflag_file == 888)
	{
		invalid_memory_access_main();
	}

	/* Allocate small size of memory for type struct/union (static) */
	if (vflag_file ==25 || vflag_file == 888)
	{
		littlemem_st_main();
	}

	/* Live Lock */
	if (vflag_file ==26 || vflag_file == 888)
	{
		livelock_main();
	}

	/*Lock never unlock main main*/
	if (vflag_file ==27 || vflag_file == 888)
	{
		lock_never_unlock_main();
	}

	/*Memory allocation failure main*/
	if (vflag_file ==28 || vflag_file == 888)
	{
		memory_allocation_failure_main();
	}

	/* Memory leak */
	if (vflag_file ==29 || vflag_file == 888)
	{
		memory_leak_main();
	}

	/* Non void function does not return value */
	if (vflag_file ==30 || vflag_file == 888)
	{
		not_return_main();
	}

	/* NULL pointer reference (access) */
	if (vflag_file ==31 || vflag_file == 888)
	{
		null_pointer_main();
	}

	/* Buffer overruns ( static buffer ) */
	if (vflag_file ==32 || vflag_file == 888)
	{
		overrun_st_main();
	}

	/* Copy of the overlapped area */
	if (vflag_file ==33 || vflag_file == 888)
	{
		ow_memcpy_main();
	}

	/* Power related errors */
	if(vflag_file==34 || vflag_file == 888)
	{
		pow_related_errors_main ();
	}

	/* An incorrect pointer arithmetic */
	if (vflag_file ==35 || vflag_file == 888)
	{
		ptr_subtraction_main();
	}

	/* Race condition */
	if (vflag_file ==36 || vflag_file == 888)
	{
		race_condition_main ();
	}

	/* Redundant Condition */
	if (vflag_file ==37 || vflag_file == 888)
	{
		redundant_cond_main();
	}

	/* Back in the local variables (area) */
	if (vflag_file ==38 || vflag_file == 888)
	{
		return_local_main();
	}

	/* signed/unsigned The issues associated with assignment */
	if (vflag_file ==39 || vflag_file == 888)
	{
		sign_conv_main();
	}

	/* Sleep lock */
	if (vflag_file ==40 || vflag_file == 888)
	{
		sleep_lock_main();
	}

	/*Unlock without lock main*/
	if (vflag_file ==41 || vflag_file == 888)
	{
		st_cross_thread_access_main();
	}

	/* Stack overflow */
	if (vflag_file ==42 || vflag_file == 888)
	{
		st_overflow_main();
	}

	/*Unlock without lock main*/
	if (vflag_file ==43 || vflag_file == 888)
	{
		st_underrun_main();
	}

	/* Buffer under run ( static buffer ) */
	if (vflag_file ==44 || vflag_file == 888)
	{
		underrun_st_main();
	}

	/* Uninitialized Memory */
	if (vflag_file ==45 || vflag_file == 888)
	{
		uninit_memory_access_main();
	}

	/* Uninitialized Pointer */
	if (vflag_file ==46 || vflag_file == 888)
	{
		uninit_pointer_main();
	}

	/* Uninitialized variable */
	if (vflag_file ==47 || vflag_file == 888)
	{
		uninit_var_main();
	}

	/*Unlock without lock main*/
	if (vflag_file ==48 || vflag_file == 888)
	{
		unlock_without_lock_main();
	}

	/* Unused variable */
	if (vflag_file ==49 || vflag_file == 888)
	{
		unused_var_main();
	}

	/* Wrong arguments passed to a function pointer*/
	if (vflag_file ==50 || vflag_file == 888)
	{
		wrong_arguments_func_pointer_main();
	}

	/* Division by zero */
	if (vflag_file ==51 || vflag_file == 888)
	{
		zero_division_main();
	}
	printf("Printed from main function ");
	}
	else
	{
		printf("Enter File XXX and Function XXX \n");
		printf("Example: To Execute 2nd File 3rd Function , Enter 002003 \n");
		printf("Example: To Execute All Files ,Enter 888888 \n");
		printf("Example: To Execute All functions in a File :Sample - To execute all functions in 3rd file,Enter 003888 \n");
	}
    return 0;
}
