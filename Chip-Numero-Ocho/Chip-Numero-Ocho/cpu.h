#pragma once

#include "defines.h"
#include "bit_operations.h"
#include "cpu_helper.h"

typedef struct cpu_context {
	
	// General Purpose
	u8 V[16];

	// Special
	u16 I;
	u8 delayRegister; // weird name, will handle it later
	u8 timerRegister; // weird name, will handle it later

	// Non-Accessible
	u16 PC;
	u8 SP;
} cpu_context;

typedef int (*instruction_function)(cpu_context* cpu_ctx, u16 instruction);

// specific subtypes of instructions

// Main function
void handle_instruction(cpu_context* cpu_ctx, u16 instruction);

	
