#include "./helper/logger.h"
#include "./helper/cpuinfo.h"

#include <stdlib.h>

#define STRING_SZ 100
#define NUMBER_SZ 40

void cpu_part_1();

int main(void){
    info("start program");

    cpu_part_1();
    cpu_part_2();

    info("end program");
    return 0;
}

void cpu_part_1(){
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

void cpu_part_2(){

}