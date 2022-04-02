#ifndef CPU_DATA_H
#define CPU_DATA_H
#include <string.h>
#include <stdlib.h>
#include "masks.h"

struct signature {
    char stepping;
    char model;
    char family;
    char type;
    char model_ex;
    char family_ex;
}typedef signature;

void init_sg(int value, signature* sg){
    sg->stepping = value & MASK_STEPPING;
    sg->model = (value & MASK_MODEL) >> 4;
    sg->family = (value & MASK_FAMILY) >> 8;
    sg->type = (value & MASK_TYPE) >> 12;
    sg->model_ex = (value & MASK_MODEL_EX) >> 16;
    sg->family_ex = (value & MASK_FAMILY_EX) >> 20;
}

static char result[255];

char* sg_data(signature* sg, masks type){
    // optimize later
    char temp[255];

    result[0] = '\0';
    temp[0] = '\0';
 
    switch (type){
        case MASK_STEPPING:
            strcpy(result, "Stepping ID: ");
            _ui64toa((unsigned int) sg->stepping, temp, 10);
            strcat(result, temp);
            break;
        case MASK_MODEL:
            strcpy(result, "Model Number: ");
            _ui64toa((unsigned int) sg->model, temp, 10);
            strcat(result, temp);
            break;
        case MASK_FAMILY:
            strcpy(result, "Family Code: ");
            _ui64toa((unsigned int) sg->family, temp, 10);
            strcat(result, temp);
            break;
        case MASK_TYPE:
            strcpy(result, "Processor Type: ");

            if(sg->type == 0)
                strcat(result, "Original OEM processor");
            else if(sg->type == 1)
                strcat(result, "OverDrive ® processor;");
            else if(sg->type == 2)
                strcat(result, "Dual processor");
            else
                strcat(result, "Intel reserved (Do not use)");

            strcat(result, temp);
            break;
        case MASK_MODEL_EX:
            strcpy(result, "Extended Model: ");
            _ui64toa((unsigned int) sg->model_ex, temp, 10);
            strcat(result, temp);
            break;
        case MASK_FAMILY_EX:
            strcpy(result, "Extended Family: ");
            _ui64toa((unsigned int) sg->family_ex, temp, 10);
            strcat(result, temp);
            break;
    }

    return result;
}

#endif
