#pragma once

#include "defines.h"
#include "chip.h"
#include "bit_operations.h"
#include "cpu_helper.h"
#include "cpu.h"

#define BINARY_OPERATION_ASSIGNMENT 0
#define BINARY_OPERATION_OR 1
#define BINARY_OPERATION_AND 2
#define BINARY_OPERATION_XOR 3
#define BINARY_OPERATION_ADD 4
#define BINARY_OPERATION_SUB 5
#define BINARY_OPERATION_SHR 6
#define BINARY_OPERATION_SUBN 7
#define BINARY_OPERATION_SHL 0xE

#define PART_TYPE 0
#define PART_SUBTYPE 3
#define PART_BYTES 3

typedef int (*instruction_function)(chip_context* chip_ctx, u16 instruction);

// specific subtypes of instructions

// Main function
void handle_instruction(chip_context* chip_ctx, u16 instruction);
