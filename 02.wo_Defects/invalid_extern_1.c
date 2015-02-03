/********Software Analysis - FY2013*************/
/*
* File Name: invalid_extern_1.c
* Defect Classification
* ---------------------
* Defect Type: other
* Defect Sub-type: external variable type error
*
*/

#include "HeaderFile.h"

int invalid_extern_001_glb_buf[5] = {1, 2, 3, 4, 5};
float invalid_extern_001_glb_float[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
float invalid_extern_001_glb_var3[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
int invalid_extern_001_glb_var4 = 5;
float invalid_extern_001_glb_var5 = 5.0;

typedef struct {
        int  csr;
        int  data;
}invalid_extern_001_glb_006_s_001;

invalid_extern_001_glb_006_s_001 *invalid_extern_001_glb_006_str;
