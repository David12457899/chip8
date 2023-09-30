#include "cpu.h"

static void instruction_cls_ret(cpu_context* cpu_ctx, u16 instruction)
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

static void instruction_jp(cpu_context* cpu_ctx, u16 instruction)
{
	address = get_address_from
	
	cpu_ctx->PC = address;
}

static void instruction_call(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_se_byte(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_sne_byte(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_se(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_ld(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_add_byte(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_binary_operation(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_sne(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_ld_addr(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_jp_addr(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_rnd_addr(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_drw_addr(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_skp(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_skp_sknp(cpu_context* cpu_ctx, u16 instruction)
{
}

static void instruction_interrupt(cpu_context* cpu_ctx, u16 instruction)
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

void handle_instruction(cpu_context* cpu_ctx, u16 instruction) {
	int instruction_type = get_address_from_instruction(instruction);

	instructions[instruction_type](cpu_ctx, instruction);
}

