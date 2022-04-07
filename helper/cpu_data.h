#ifndef CPU_DATA_H
#define CPU_DATA_H
#include <string.h>
#include <stdlib.h>
#include "masks.h"

static char result[255];

struct signature_eax {
    char stepping;
    char model;
    char family;
    char type;
    char model_ex;
    char family_ex;
}typedef signature_eax;

struct signature_ebx{
    char brand_id;
    char chunks;
    char apic_id;
}typedef signature_ebx;

struct signature_edx{
    char fpu    : 1;
    char vme    : 1;
    char de     : 1;
    char pse    : 1;
    char tsc    : 1;
    char msr    : 1;
    char pae    : 1;
    char mce    : 1;
    char cxb    : 1;
    char apic   : 1;
    char rsrv_1 : 1; // reserv
    char sep    : 1;
    char mtrr   : 1;
    char pge    : 1;
    char mca    : 1;
    char cmov   : 1;
    char pat    : 1;
    char pse_36 : 1;
    char psn    : 1;
    char clfsh  : 1;
    char rsrv_2 : 1; // reserv
    char ds     : 1;
    char acpi   : 1;
    char mmx    : 1;
    char sp_fxr : 1;
    char sse    : 1;
    char sse2   : 1;
    char ss     : 1;
    char rsrv_3 : 1; // reserv
    char tm     : 1;
}typedef signature_edx;

void bool_str(char* temp, int bit);

void init_sg_eax(int value, signature_eax* sg);
void init_sg_ebx(int value, signature_ebx* sg);
void init_sg_edx(int value, signature_edx* sg);

char* sg_data_eax(signature_eax* sg, masks_eax type);
char* sg_data_ebx(signature_ebx* sg, masks_ebx type);
char* sg_data_edx(signature_edx* sg, masks_edx type);
#endif
