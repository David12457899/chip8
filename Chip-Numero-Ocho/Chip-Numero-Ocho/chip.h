#pragma once

#include "defines.h"

typedef struct cpu_context {

	// General Purpose
	u8 V[16];

	// Special
	u16 I;
	u8 DT; // Delay timer
	u8 ST; // Set sound timer

	// Non-Accessible
	u16 PC;
	u8 SP;
} cpu_context;

typedef struct chip_context{
	cpu_context* cpu;

	u16 stack[STACK_SIZE];
} chip_context;