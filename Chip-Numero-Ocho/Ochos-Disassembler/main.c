#include <stdio.h>

#include "disassembler.h"

#define MAX_ARGS 3

int main(int argc, char** argv)
{
	
	if (argc != MAX_ARGS) {
		fprintf(stderr, "usage: ./ochos <input_file> <output_file>\n");
	}

	//char* input_file = argv[1];
	//char* output_file = argv[2];

	char* input_file = "pong.ch8";
	char* output_file = "b.txt";

	disassemble(input_file, output_file);

	printf("Running disassembler!\n");
}