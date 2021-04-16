/***************************************************************************
 * file name   : assembler.c                                               *
 * author      : tjf & you                                                 *
 * description : This program will assemble a .ASM file into a .OBJ file   *
 *               This program will use the "asm_parser" library to achieve *
 *			     its functionality.										   * 
 *                                                                         *
 ***************************************************************************
 *
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

int main(int argc, char** argv) {

	if (argc > 1)
	{

		char* filename = argv[1];				// name of ASM file
		char program [ROWS][COLS] ; 			// ASM file line-by-line
		char  program_bin_str [ROWS][17] ; 		// instructions converted to a binary string
		unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)
		int i,j;


		read_asm_file(filename,program);
		for( i=0;i<7;i++)
		{
			for ( j = 0;  j< 14; j++)
			{
					printf("%c",program[i][j]);
			}
			printf("\n");

			parse_instruction(program[i], program_bin_str[i]);
			program_bin[i] = str_to_bin (program_bin_str[i]);

		}	

		write_obj_file (filename, program_bin);

		return 0;
	}
	else
	{
		fprintf(stderr, "Error: No input file is provided \n");
		exit(EXIT_SUCCESS);
	}
	
}