#pragma once

#include "defines.h"
#include "chip.h"
#include "bit_operations.h"
#include "cpu_helper.h"
#include "cpu.h"

typedef int (*instruction_function)(chip_context* chip_ctx, u16 instruction);

// specific subtypes of instructions

// Main function
void handle_instruction(chip_context* chip_ctx, u16 instruction);

	
