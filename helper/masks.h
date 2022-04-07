#ifndef MASK_H
#define MASK_H

#define TRUE_STR "1"
#define FALSE_STR "0"

enum masks_eax{
	MASK_STEPPING = 0xF,
	MASK_MODEL = 0xF0,
	MASK_FAMILY = 0xF00,
	MASK_TYPE = 0x3000,
	MASK_MODEL_EX = 0xF0000,
	MASK_FAMILY_EX = 0xFF00000
}typedef masks_eax;

enum masks_ebx{
	MASK_BRAND_ID = 0x000000FF,
	MASK_CHUNKS = 0x0000FF00,
	MASK_APIC_ID = 0xFF000000
}typedef masks_ebx;

enum masks_edx{
	MASK_FPU 	= 0x1,
	MASK_VME 	= 0x2,
	MASK_DE  	= 0x4,
	MASK_PSE 	= 0x8,
	MASK_TSC 	= 0x10,
	MASK_MSR 	= 0x20,
	MASK_PAE 	= 0x40,
	MASK_MCE 	= 0x80,
	MASK_CXB 	= 0x100,
	MASK_APIC	= 0x200,
	// reserv bit
	MASK_SEP 	= 0x800,
	MASK_MTRR	= 0x1000,
	MASK_PGE 	= 0x2000,
	MASK_MCA 	= 0x4000,
	MASK_CMOV	= 0x8000,
	MASK_PAT 	= 0x10000,
	MASK_PSE_36 = 0x20000,
	MASK_PSN	= 0x40000,
	MASK_CLFSH	= 0x80000,
	// reserv bit
	MASK_DS		= 0x200000,
	MASK_ACPI 	= 0x400000,
	MASK_MMX	= 0x800000,
	MASK_SP_FXR	= 0x1000000,
	MASK_SSE	= 0x2000000,
	MASK_SSE2	= 0x4000000,
	MASK_SS		= 0x8000000,
	// reserv bit
	MASK_TM		= 0x20000000
}typedef masks_edx;

#endif