#include "cpu.h"

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

void handle_instruction(u16 instruction) {
	int instruction_type = get_instruction_type(instruction);

	instructions[instruction_type](instruction);
}

static void instruction_cls_ret()
{
}

static void instruction_jp()
{
}

static void instruction_call()
{
}

static void instruction_se_byte()
{
}

static void instruction_sne_byte()
{
}

static void instruction_se()
{
}

static void instruction_ld()
{
}

static void instruction_add_byte()
{
}

static void instruction_binary_operation()
{
}

static void instruction_sne()
{
}

static void instruction_ld_addr()
{
}

static void instruction_jp_addr()
{
}

static void instruction_rnd_addr()
{
}

static void instruction_drw_addr()
{
}

static void instruction_skp()
{
}

static void instruction_skp_sknp()
{
}

static void instruction_interrupt()
{
}

static int get_instruction_type(u16 instruction) {
	return instruction >> 4;
}





