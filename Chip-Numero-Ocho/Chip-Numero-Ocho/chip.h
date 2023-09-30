#pragma once

#include "cpu.h"
#include "defines.h"

typedef struct chip_context{
	cpu_context* cpu;

	u16 stack[STACK_SIZE];
} chip_context;