#include <stdio.h>

#define MAX_ARGS 3

int main(int argc, char** argv)
{
	
	if (argc != MAX_ARGS) {
		fprintf(stderr, "usage: ./ochos <input_file> <output_file>\n");
	}

	printf("Running disassembler!\n");
}