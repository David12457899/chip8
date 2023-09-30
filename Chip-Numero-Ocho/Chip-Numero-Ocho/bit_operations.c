#include "bit_operations.h"

int get_instruction_part(u16 instruction, int part_index) {
	return (instruction >> (4 * (3 - part_index))) & 0xF;
}