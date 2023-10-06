#include "cpu.h"

static void instruction_cls_ret(chip_context* chip_ctx, u16 instruction)
{
	// 00E0(CLS)/00EE(RET)
	int subtype = get_instruction_part(instruction, PART_TYPE);

	switch (subtype) {
		case 0:
			// todo: insert CLS function call here
			break;
		case 0xE:
			// todo: insert RET function call here
			break;
		default:
			// todo: insert unrecognized fatal error here
			break;
	}
}

static void instruction_jp(chip_context* chip_ctx, u16 instruction)
{
	chip_ctx->cpu->PC = get_address_from_instruction(instruction);
}

static void instruction_call(chip_context* chip_ctx, u16 instruction)
{
	chip_ctx->stack[chip_ctx->cpu->SP] = chip_ctx->cpu->PC;
	chip_ctx->cpu->SP++;

	instruction_jp(chip_ctx, instruction);
}

static void instruction_se_byte(chip_context* chip_ctx, u16 instruction)
{
	char kk = get_kk_from_instruction(instruction);
	int x = get_instruction_part(instruction, 1);
	
	chip_ctx->cpu->PC++;
}

static void instruction_sne_byte(chip_context* chip_ctx, u16 instruction)
{
	instruction_se_byte(chip_ctx, instruction);
	chip_ctx->skip_instruction = 1 - chip_ctx->skip_instruction;
}

static void instruction_se(chip_context* chip_ctx, u16 instruction)
{
	int x = get_instruction_part(instruction, 1);
	int y = get_instruction_part(instruction, 2);

	if (chip_ctx->cpu->V[x] == chip_ctx->cpu->V[y]) {
		chip_ctx->skip_instruction = 1;
	}
}

static void instruction_ld(chip_context* chip_ctx, u16 instruction)
{
	char kk = get_kk_from_instruction(instruction);
	int x = get_instruction_part(instruction, 1);

	chip_ctx->cpu->V[x] = kk;
}

static void instruction_add_byte(chip_context* chip_ctx, u16 instruction)
{
	char kk = get_kk_from_instruction(instruction);
	int x = get_instruction_part(instruction, 1);

	chip_ctx->cpu->V[x] += kk;
}

static void instruction_binary_operation(chip_context* chip_ctx, u16 instruction)
{
	u16 tmp;
	int x = get_instruction_part(instruction, 1);
	int y = get_instruction_part(instruction, 2);

	int operation_type = get_instruction_part(instruction, PART_SUBTYPE);

	switch (operation_type) {
		case BINARY_OPERATION_ASSIGNMENT:
			chip_ctx->cpu->V[x] = chip_ctx->cpu->V[y];
			break;
		
		case BINARY_OPERATION_OR:
			chip_ctx->cpu->V[x] |= chip_ctx->cpu->V[y];
			break;
		
		case BINARY_OPERATION_AND:
			chip_ctx->cpu->V[x] &= chip_ctx->cpu->V[y];
			break;
		
		case BINARY_OPERATION_XOR:
			break;
			chip_ctx->cpu->V[x] ^= chip_ctx->cpu->V[y];
		
		case BINARY_OPERATION_ADD:
			tmp = (u16)chip_ctx->cpu->V[x] + (u16)chip_ctx->cpu->V[y];
		
			chip_ctx->cpu->V[x] = (u8)(tmp & 255);
			chip_ctx->cpu->V[0xF] = (u8)(tmp >> 8);
			break;
		
		case BINARY_OPERATION_SUB:
			tmp = (u16)chip_ctx->cpu->V[x] - (u16)chip_ctx->cpu->V[y];
		
			chip_ctx->cpu->V[x] = (u8)(tmp & 255);
			chip_ctx->cpu->V[0xF] = chip_ctx->cpu->V[x] > chip_ctx->cpu->V[y] ? 1 : 0;
			break;
	
		
		case BINARY_OPERATION_SHR:
			// todo: might get V[y] as parameter? 
			chip_ctx->cpu->V[x] >>= 1;
			chip_ctx->cpu->V[0xF] = chip_ctx->cpu->V[x] & 1;
			break;
		
		case BINARY_OPERATION_SUBN:
			tmp = (u16)chip_ctx->cpu->V[y] - (u16)chip_ctx->cpu->V[x];

			chip_ctx->cpu->V[x] = (u8)(tmp & 255);
			chip_ctx->cpu->V[0xF] = chip_ctx->cpu->V[x] < chip_ctx->cpu->V[y] ? 1 : 0;
			break;
		
		case BINARY_OPERATION_SHL:
			// todo: might get V[y] as parameter?
			chip_ctx->cpu->V[x] <<= 1;
			chip_ctx->cpu->V[0xF] = chip_ctx->cpu->V[x] & 1;
			break;
		
		default:
			break;
	}
}

static void instruction_sne(chip_context* chip_ctx, u16 instruction)
{

}

static void instruction_ld_addr(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_jp_addr(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_rnd_addr(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_drw_addr(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_skp(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_skp_sknp(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_interrupt(chip_context* chip_ctx, u16 instruction)
{
}

static instruction_function instructions[] = {
	&instruction_cls_ret,
	&instruction_jp,
	&instruction_call,
	&instruction_se_byte,
	&instruction_sne_byte,
	&instruction_se,
	&instruction_ld,
	&instruction_add_byte,
	&instruction_binary_operation,
	&instruction_sne,
	&instruction_ld_addr,
	&instruction_jp_addr,
	&instruction_rnd_addr,
	&instruction_drw_addr,
	&instruction_skp_sknp,
	&instruction_interrupt
};

void handle_instruction(chip_context* chip_ctx, u16 instruction) {
	// todo: handle skip instruction
	// todo: replace all int occurences with u<8/16/32>
	int instruction_type = get_instruction_part(instruction, PART_TYPE);

	instructions[instruction_type](chip_ctx, instruction);
}

