#include "logger.h"

#define MAX_SUBTYPES 9

char* instructions[][MAX_SUBTYPES] = {
	{"00E0", "00EE"},
	{"JP"},
	{"CALL"},
	{"SE"},
	{"SNE"},
	{"SE"},
	{"LD"},
	{"ADD"},
	{"LD", "OR", "AND", "XOR", "ADD", "SUB", "SHR", "SUBN", "SHL"},
	{"SNE"},
	{"LD"},
	{"JP"},
	{"RND"},
	{"DRW"},
	{"SKP", "SKNP"},
	{"LD", "LD", "LD", "LD", "ADD", "LD", "LD", "LD", "LD"}
};

u8 instruction_indexes_mapper[][MAX_SUBTYPES] = {
	{0, 0xE, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, 1, 2, 3, 4, 5, 6, 7, 0xE},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{7, 0xA, 0x15, 0x18, 0x1E, 0x29, 0x33, 0x55, 0x65},
	{0, -1, -1, -1, -1, -1, -1, -1, -1},
	{0xE, 1, -1, -1, -1, -1, -1, -1, -1},
};

static u8 get_interrupt_subtype(char* instruction) {
	return (hex_char_to_decimal(instruction[2])) * 0x10 + (hex_char_to_decimal(instruction[3]));
}

static u8 find_instruction_index(char* instruction) {
	u8 type = instruction[0] - '0';
	u8* indexes = instruction_indexes_mapper[type];

	// Subtype of 0xF type consists of 2 hex symbols
	u8 subtype = (type != 0xF) ? (instruction[3]) : (get_interrupt_subtype(instruction));

	for (u8 i = 0; i < MAX_SUBTYPES; i++) {
		if (indexes[i] == subtype) {
			return i;
		}
	}

	return -1;
}

static char* translate_instruction(char* instruction) {
	return instructions[find_instruction_index(instruction)];
}

static void print_v(cpu_context* cpu_ctx) {
	for (u8 i = 0; i < 16; i++) {
		fprintf(stdout, "[%hu]", cpu_ctx->V[i]);
	}
	fprintf(stdout, "\n\n");
}

void log_instruction(cpu_context* cpu_ctx, char* instruction)
{
	char* instruction_name = translate_instruction(instruction);

	fprintf(stdout, "%x: %s (%s) I: %hu DT: %h ST: %h SP: %h\n", 
			cpu_ctx->PC, instruction_name,instruction, cpu_ctx->I, cpu_ctx->DT, cpu_ctx->SP);
}

void log_instruction_addr(cpu_context* cpu_ctx, char* instruction, u16 addr)
{
	char* instruction_name = translate_instruction(instruction);

	fprintf(stdout, "%x: %s %hu (%s) I: %hu DT: %h ST: %h SP: %h\n",
		cpu_ctx->PC, instruction_name, addr, instruction, cpu_ctx->I, cpu_ctx->DT, cpu_ctx->SP);
}

void log_instruction_vals(cpu_context* cpu_ctx, char* instruction, char* left_val, char* right_val)
{
	char* instruction_name = translate_instruction(instruction);

	fprintf(stdout, "%x: %s %s,%s (%s) I: %hu DT: %h ST: %h SP: %h\n",
		cpu_ctx->PC, instruction_name, left_val, right_val, instruction, cpu_ctx->I, cpu_ctx->DT, cpu_ctx->SP);
}
