#ifndef CPUINFO_H
#define CPUINFO_H

#include <stdio.h>
#include "mask.h"

struct reg
{
    int eax;
    int ebx;
    int edx;
    int ecx;
}typedef reg;


reg max_supp_func();
reg cpu_signature();
reg cpu_cache();
reg cpu_serial_num();
int get_data(int eax, masks mask);

#endif