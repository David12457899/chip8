#pragma once

#include <stdio.h>

#include "defines.h"
#include "chip.h"
#include "cpu_helper.h"

void log_instruction(cpu_context* cpu_ctx, char* instruction);
void log_instruction_addr(cpu_context* cpu_ctx, char* instruction, u16 addr);
void log_instruction_vals(cpu_context* cpu_ctx, char* instruction, char* left_val, char* right_val);
// todo: add a log for key press functions