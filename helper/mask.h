#ifndef MASK_H
#define MASK_H

enum masks_num{
	MASK_STEPPING = 0xF,
	MASK_MODEL = 0xF0,
	MASK_FAMILY = 0xF00,
	MASK_TYPE = 0x3000,
	MASK_MODEL_EX = 0xF0000,
	MASK_FAMILY_EX = 0xFF00000
}typedef masks;

#endif