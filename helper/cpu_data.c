#include "cpu_data.h"

void init_sg_eax(int value, signature_eax* sg){
    sg->stepping = value & MASK_STEPPING;
    sg->model = (value & MASK_MODEL) >> 4;
    sg->family = (value & MASK_FAMILY) >> 8;
    sg->type = (value & MASK_TYPE) >> 12;
    sg->model_ex = (value & MASK_MODEL_EX) >> 16;
    sg->family_ex = (value & MASK_FAMILY_EX) >> 20;
}

void init_sg_ebx(int value, signature_ebx* sg){
    sg->brand_id = value & MASK_BRAND_ID;
    sg->chunks = (value & MASK_CHUNKS) >> 8;
    sg->apic_id = (value & MASK_APIC_ID) >> 24;
}

void init_sg_edx(int value, signature_edx* sg){
    *((int*) sg) = value;
}

static char result[255];
char* sg_data_eax(signature_eax* sg, masks_eax type){
    // optimize later
    char temp[255];

    result[0] = '\0';
    temp[0] = '\0';
 
    switch (type){
        case MASK_STEPPING:
            strcpy(result, "Stepping ID: ");
            _ui64toa((unsigned int) sg->stepping, temp, 10);
            break;
        case MASK_MODEL:
            strcpy(result, "Model Number: ");
            _ui64toa((unsigned int) sg->model, temp, 10);
            break;
        case MASK_FAMILY:
            strcpy(result, "Family Code: ");
            _ui64toa((unsigned int) sg->family, temp, 10);
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
            break;
        case MASK_MODEL_EX:
            strcpy(result, "Extended Model: ");
            _ui64toa((unsigned int) sg->model_ex, temp, 10);
            break;
        case MASK_FAMILY_EX:
            strcpy(result, "Extended Family: ");
            _ui64toa((unsigned int) sg->family_ex, temp, 10);
            break;
    }

    strcat(result, temp);
    return result;
}

char* sg_data_ebx(signature_ebx* sg, masks_ebx type){
    // optimize later
    char temp[255];

    result[0] = '\0';
    temp[0] = '\0';
 
    switch (type){
        case MASK_BRAND_ID:
            strcpy(result, "Brand ID: ");
            _ui64toa((unsigned int) sg->brand_id, temp, 10);
            break;
        case MASK_CHUNKS:
            strcpy(result, "Chunks: ");
            _ui64toa((unsigned int) sg->chunks, temp, 10);
            break;
        case MASK_APIC_ID:
            strcpy(result, "APIC ID: ");
            _ui64toa((unsigned int) sg->apic_id, temp, 10);
            break;
    }

    strcat(result, temp);
    return result;
}

char* sg_data_edx(signature_edx* sg, masks_edx type){
    // optimize later
    char temp[255];

    result[0] = '\0';
    temp[0] = '\0';
 
    switch (type){
        case MASK_FPU:
            strcpy(result, "Supp FPU: ");
            bool_str(temp, sg->fpu);
            break;
        case MASK_VME:
            strcpy(result, "Supp VME: ");
            bool_str(temp, sg->vme);
            break;
        case MASK_DE:
            strcpy(result, "Supp DE: ");
            bool_str(temp, sg->de);
            break;
        case MASK_PSE:
            strcpy(result, "Supp PSE: ");
            bool_str(temp, sg->pse);
            break;
        case MASK_TSC:
            strcpy(result, "Supp TSC: ");
            bool_str(temp, sg->tsc);
            break;
        case MASK_MSR:
            strcpy(result, "Supp MSR: ");
            bool_str(temp, sg->msr);
            break;
        case MASK_PAE:
            strcpy(result, "Supp PAE: ");
            bool_str(temp, sg->pae);
            break;
        case MASK_MCE:
            strcpy(result, "Supp MCE: ");
            bool_str(temp, sg->mce);
            break;
        case MASK_CXB:
            strcpy(result, "Supp CXB: ");
            bool_str(temp, sg->cxb);
            break;
        case MASK_APIC:
            strcpy(result, "Supp APIC: ");
            bool_str(temp, sg->msr);
            break;
        case MASK_SEP:
            strcpy(result, "Supp SEP: ");
            bool_str(temp, sg->sep);
            break;
        case MASK_MTRR:
            strcpy(result, "Supp MTRR: ");
            bool_str(temp, sg->mtrr);
            break;
        case MASK_PGE:
            strcpy(result, "Supp PGE: ");
            bool_str(temp, sg->pge);
            break;
        case MASK_MCA:
            strcpy(result, "Supp MCA: ");
            bool_str(temp, sg->mca);
            break;
        case MASK_CMOV:
            strcpy(result, "Supp CMOV: ");
            bool_str(temp, sg->cmov);
            break;
        case MASK_PAT:
            strcpy(result, "Supp PAT: ");
            bool_str(temp, sg->pat);
            break;
        case MASK_PSE_36:
            strcpy(result, "Supp PSE-36: ");
            bool_str(temp, sg->pse_36);
            break;
        case MASK_PSN:
            strcpy(result, "Supp PSN: ");
            bool_str(temp, sg->psn);
            break;
        case MASK_CLFSH:
            strcpy(result, "Supp CLFSH: ");
            bool_str(temp, sg->clfsh);
            break;
        case MASK_DS:
            strcpy(result, "Supp DS: ");
            bool_str(temp, sg->ds);
            break;
        case MASK_ACPI:
            strcpy(result, "Supp ACPI: ");
            bool_str(temp, sg->acpi);
            break;
        case MASK_MMX:
            strcpy(result, "Supp MMX: ");
            bool_str(temp, sg->mmx);
            break;
        case MASK_SP_FXR:
            strcpy(result, "Supp FXRSTOR & FXRSAVE: ");
            bool_str(temp, sg->sp_fxr);
            break;
        case MASK_SSE:
            strcpy(result, "Supp SSE: ");
            bool_str(temp, sg->sse);
            break;
        case MASK_SSE2:
            strcpy(result, "Supp SSE2: ");
            bool_str(temp, sg->sse2);
            break;
        case MASK_SS:
            strcpy(result, "Supp SS: ");
            bool_str(temp, sg->ss);
            break;
        case MASK_TM:
            strcpy(result, "Supp TM: ");
            bool_str(temp, sg->tm);
            break;
    }

    strcat(result, temp);
    return result;
}

void bool_str(char* temp, int bit){
    if(bit)
        strcat(temp, TRUE_STR);
    else
        strcat(temp, FALSE_STR);
}