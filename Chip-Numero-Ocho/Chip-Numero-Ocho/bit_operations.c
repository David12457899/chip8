#include "bit_operations.h"

int get_instruction_part(u16 instruction, int part_index)
{
	return (instruction >> (4 * (3 - part_index))) & 0xF;
}

int bcd(u8 val)
{
	u8 incrementing = 1, i = 0;
	u8 res = 0, cur_bit = 0;

	for (i = 0; i < 8; i++) {
		cur_bit = val & 1;
		res += incrementing * cur_bit;

		incrementing *= 10;
	}

	return res;
}