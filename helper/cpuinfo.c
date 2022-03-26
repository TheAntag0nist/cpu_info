#include "cpuinfo.h"

// eax = 0
reg max_supp_func(){
    reg result;

    __asm__("mov $0x0, %eax\n\t");
    __asm__("cpuid\n\t");
    __asm__("mov %%ebx, %0\n\t":"=r" (result.ebx));
    __asm__("mov %%edx, %0\n\t":"=r" (result.edx));
    __asm__("mov %%ecx, %0\n\t":"=r" (result.ecx));
    __asm__("mov %%eax, %0\n\t":"=r" (result.eax));

    return result;
}

// eax = 1
reg cpu_signature(){
    reg result;

    __asm__("mov $0x1, %eax\n\t");
    __asm__("cpuid\n\t");
    __asm__("mov %%ebx, %0\n\t":"=r" (result.ebx));
    __asm__("mov %%edx, %0\n\t":"=r" (result.edx));
    __asm__("mov %%ecx, %0\n\t":"=r" (result.ecx));
    __asm__("mov %%eax, %0\n\t":"=r" (result.eax));

    return result;
}

// eax = 2
reg cpu_cache(){
    reg result;

    __asm__("mov $0x2, %eax\n\t");
    __asm__("cpuid\n\t");
    __asm__("mov %%ebx, %0\n\t":"=r" (result.ebx));
    __asm__("mov %%edx, %0\n\t":"=r" (result.edx));
    __asm__("mov %%ecx, %0\n\t":"=r" (result.ecx));
    __asm__("mov %%eax, %0\n\t":"=r" (result.eax));

    return result;
}

// eax = 3
reg cpu_serial_num(){
    reg result;

    __asm__("mov $0x3, %eax\n\t");
    __asm__("cpuid\n\t");
    __asm__("mov %%ebx, %0\n\t":"=r" (result.ebx));
    __asm__("mov %%edx, %0\n\t":"=r" (result.edx));
    __asm__("mov %%ecx, %0\n\t":"=r" (result.ecx));
    __asm__("mov %%eax, %0\n\t":"=r" (result.eax));

    return result;
}