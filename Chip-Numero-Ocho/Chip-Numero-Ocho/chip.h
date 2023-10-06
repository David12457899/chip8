#pragma once

#include "cpu.h"
#include "defines.h"

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

typedef struct chip_context{
	cpu_context* cpu;

	u16 stack[STACK_SIZE];
} chip_context;