#pragma once

#include "defines.h"

int get_instruction_type(u16 instruction);
u16 get_address_from_instruction(u16 instruction);
u8 get_kk_from_instruction(u16 instruction);
u8 hex_char_to_decimal(char chr);
