#include "cpu.h"

static void instruction_cls_ret(chip_context* chip_ctx, u16 instruction)
{
	// 00E0(CLS)/00EE(RET)
	int subtype = get_instruction_part(instruction, 3);

	switch (subtype) {
		case 0X0:
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
}

static void instruction_sne_byte(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_se(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_ld(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_add_byte(chip_context* chip_ctx, u16 instruction)
{
}

static void instruction_binary_operation(chip_context* chip_ctx, u16 instruction)
{
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
	int instruction_type = get_address_from_instruction(instruction);

	instructions[instruction_type](chip_ctx, instruction);
}

