#include "./helper/logger.h"
#include "./helper/cpuinfo.h"
#include "./helper/cpu_data.h"

#include <stdlib.h>

#define STRING_SZ 100
#define NUMBER_SZ 40

void cpu_part_1();
void cpu_part_2();
void cpu_part_3();
void cpu_part_4();

int main(){
    info("start program");

    char bit_inf[50];
    bit_inf[0] = '\0';
    bit_depth(bit_inf);
    info(bit_inf);

    delimiter('=', 80);
    cpu_part_1();
    delimiter('=', 80);
    cpu_part_2();
    delimiter('=', 80);
    cpu_part_4();
    delimiter('=', 80);

    info("end program");
    return 0;
}

void cpu_part_1() {
    char temp_str[STRING_SZ];
    char number[NUMBER_SZ];
    
    temp_str[0] = '\0';
    number[0] = '\0';

    reg inf = max_supp_func();
    strcpy(temp_str, "CPU => ");
    strcat(temp_str, (char*) &inf.ebx);
    info(temp_str);

    temp_str[0] = '\0';
    number[0] = '\0';

    strcpy(temp_str, "MAX BASIC FUNC => ");
    snprintf( number, NUMBER_SZ, "%x", inf.eax);
    strcat(temp_str, number);
    info(temp_str);
}

void cpu_part_2() {
    reg inf = cpu_signature();
    signature_eax sg_eax;
    signature_ebx sg_ebx;
    signature_edx sg_edx;

    // init all sigs
    init_sg_eax(inf.eax, &sg_eax);
    init_sg_ebx(inf.ebx, &sg_ebx);
    init_sg_edx(inf.edx, &sg_edx);

    // eax
    info( sg_data_eax(&sg_eax, MASK_STEPPING));
    info( sg_data_eax(&sg_eax, MASK_MODEL));
    info( sg_data_eax(&sg_eax, MASK_FAMILY));
    info( sg_data_eax(&sg_eax, MASK_TYPE));
    info( sg_data_eax(&sg_eax, MASK_MODEL_EX));
    info( sg_data_eax(&sg_eax, MASK_FAMILY_EX));

    // delim lines
    delimiter('=', 80);
    // ebx
    info( sg_data_ebx(&sg_ebx, MASK_BRAND_ID));
    info( sg_data_ebx(&sg_ebx, MASK_CHUNKS));
    info( sg_data_ebx(&sg_ebx, MASK_APIC_ID));

    // delim lines
    // delimiter('=', 80);
    // edx
    info( sg_data_edx(&sg_edx, MASK_FPU));
    info( sg_data_edx(&sg_edx, MASK_VME));
    info( sg_data_edx(&sg_edx, MASK_DE));
    info( sg_data_edx(&sg_edx, MASK_PSE));
    info( sg_data_edx(&sg_edx, MASK_TSC));
    info( sg_data_edx(&sg_edx, MASK_MSR));
    info( sg_data_edx(&sg_edx, MASK_PAE));
    info( sg_data_edx(&sg_edx, MASK_MCE));
    info( sg_data_edx(&sg_edx, MASK_CXB));
    info( sg_data_edx(&sg_edx, MASK_APIC));
    // delim lines
    // delimiter(' ', 80);
    info( sg_data_edx(&sg_edx, MASK_SEP));
    info( sg_data_edx(&sg_edx, MASK_MTRR));
    info( sg_data_edx(&sg_edx, MASK_PGE));
    info( sg_data_edx(&sg_edx, MASK_MCA));
    info( sg_data_edx(&sg_edx, MASK_CMOV));
    info( sg_data_edx(&sg_edx, MASK_PAT));
    info( sg_data_edx(&sg_edx, MASK_PSE_36));
    info( sg_data_edx(&sg_edx, MASK_PSN));
    info( sg_data_edx(&sg_edx, MASK_CLFSH));
    // delim lines
    // delimiter(' ', 80);
    info( sg_data_edx(&sg_edx, MASK_DS));
    info( sg_data_edx(&sg_edx, MASK_ACPI));
    info( sg_data_edx(&sg_edx, MASK_MMX));
    info( sg_data_edx(&sg_edx, MASK_SP_FXR));
    info( sg_data_edx(&sg_edx, MASK_SSE));
    info( sg_data_edx(&sg_edx, MASK_SSE2));
    info( sg_data_edx(&sg_edx, MASK_SS));
    // delim lines
    // delimiter(' ', 80);
    info( sg_data_edx(&sg_edx, MASK_TM));
}

void cpu_part_3() {
    reg inf = cpu_cache();
}

void cpu_part_4(){
    reg inf = cpu_serial_num();
    char serial_number[255] = "";
    char temp_num[255] = "";

    strcpy(serial_number, "Serial Number: ");
    _ui64toa(inf.ecx, temp_num, 10);
    strcat(serial_number, temp_num);
    temp_num[0] = '\0';
    strcat(serial_number, " ");
    _ui64toa(inf.edx, temp_num, 10);
    strcat(serial_number, temp_num);
    
    info(serial_number);
}