#include "disassembler.h"

static char decimal_to_hex_letter(u16 val) 
{
	return val >= 0xa ? ('A' + val - 10) : ('0' + val);
}

static void translate_chunck(char* chunck, char* translated_chunck)
{
	u8 i = 0, indexer = 0;
	
	u16 tmp_chunck = *(u16*)chunck;

	for (i = 0; i < 4; i++) {
		
		// Little endian
		indexer = i < 2 ? (i + 2) : (i - 2);

		translated_chunck[3 - indexer] = decimal_to_hex_letter(tmp_chunck % 16);

		tmp_chunck /= 16;
	}
}

void disassemble(char* input_file, char* output_file)
{
	FILE *input_fp = NULL, *output_fp = NULL;
	char chunk[CHUNCK_READ_SIZE + 1] = { 0 }, translated_chunck[CHUNCK_READ_SIZE * 2 + 1] = { 0 };
	u8 bytes_read = 0;

	input_fp = fopen(input_file, "rb");
	output_fp = fopen(output_file, "a");

	if (input_fp == NULL) {
		fprintf(stderr, "unable to open input file: %s\n", input_file);
		
		exit(1);
	}

	while ((bytes_read = fread(chunk, 1, CHUNCK_READ_SIZE, input_fp)) > 0) {
		translate_chunck(chunk, translated_chunck);
		
		fprintf(output_fp, "%s\n", translated_chunck);
	}

	fclose(input_fp);
	fclose(output_fp);
}