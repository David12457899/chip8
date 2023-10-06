#include "disassembler.h"

static char* translate_chunck(char* chunck)
{
	
}

void disassemble(char* input_file, char* output_file)
{
	FILE *input_fp = NULL, *output_fp = NULL;
	char chunk[CHUNCK_READ_SIZE];

	input_fp = fopen(input_file, "r");

	if (input_fp == NULL) {
		fprintf(stderr, "unable to open input file: %s\n", input_file);
		
		exit(1);
	}

	while (fgets(chunk, CHUNCK_READ_SIZE, input_fp) != NULL) {
		char* translated_chunck = translate_chunck(chunk);

		output_fp = fopen(output_file, "a");
		
		fprintf(output_fp, "%s\n", translated_chunck);
	
		fclose(output_fp);
	}

	fclose(input_fp);

	

	fprintf(stderr, "unable to open input file: %s\n", input_file);
}