#include "cpu_helper.h"

int get_instruction_type(u16 instruction) {
	// todo: mb fix this?
	return instruction >> 4;
}

u16 get_address_from_instruction(u16 instruction)
{
	return instruction & 0xFFF;
}

u8 get_kk_from_instruction(u16 instruction)
{
	return instruction & 0xFF;
}

