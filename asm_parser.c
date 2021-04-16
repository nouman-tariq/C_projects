/***************************************************************************
 * file name   : asm_parser.c                                              *
 * author      : tjf & you                                                 *
 * description : the functions are declared in asm_parser.h                *
 *               The intention of this library is to parse a .ASM file     *
 *			        										               * 
 *                                                                         *
 ***************************************************************************
 *
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

/* to do - implement all the functions in asm_parser.h */
int read_asm_file (char* filename, char program [ROWS][COLS] ) 
{

 
	char ch;
    FILE *fptr = NULL; 
    int i = 0,j=0,k=0;

    fptr = fopen(filename, "r");
    
    if (fptr == NULL)
        printf("File is not available \n");
    else
    {
        while ((ch = fgetc(fptr)) != EOF)
        {
          
			if (ch == '\n')
			{
				program[i][j] = '\0';
				i++;
				j = 0;
			}
			else
			{
			program[i][j] = ch;
			
			
				j++;
			}
			
        }
        
    }
     
	if(fptr != NULL)
		fclose(fptr);
    return 0;
}

int parse_add (char* instr, char* instr_bin_str)
{
	
	char binary_opcode[] = "0001";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "000";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_mul (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0001";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "001";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_sub (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0001";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "010";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_div (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0001";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "011";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_and (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0101";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "000";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_or (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0101";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "010";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_xor (char* instr, char* instr_bin_str)
{
	char binary_opcode[] = "0101";
	strcpy(instr_bin_str, binary_opcode);
	
	instr = strtok(NULL, ",");

	char RD[2];
	strcpy(RD, instr);
	parse_reg(RD[1], instr_bin_str+4);

	instr = strtok(NULL, ",");
	char RS[3];
	strcpy(RS, instr);
	parse_reg(RS[2], instr_bin_str+7);

	char sub_opcode[] = "011";
	strcpy(instr_bin_str+10, sub_opcode);
	
	instr = strtok(NULL, ",");
	char RT[3];
	strcpy(RT, instr);
	parse_reg(RT[2], instr_bin_str+13);


	return 0;
}

int parse_instruction (char* instr, char* instr_bin_str)
{
	char *token;
	
	token = strtok(instr, " ");
	if (strcmp(token, "ADD") == 0) 
	{
		parse_add(instr, instr_bin_str);
	} 
	else if (strcmp(token, "MUL") == 0)
	{
		parse_mul(instr, instr_bin_str);
	}
	else if (strcmp(token, "SUB") == 0)
	{
		parse_sub(instr, instr_bin_str);
	}
	else if (strcmp(token, "DIV") == 0)
	{
		parse_div(instr, instr_bin_str);
	}
	else if (strcmp(token, "AND") == 0)
	{
		parse_and(instr, instr_bin_str);
	}
	else if (strcmp(token, "OR") == 0)
	{
		parse_or(instr, instr_bin_str);
	}
	else if (strcmp(token, "XOR") == 0)
	{
		parse_xor(instr, instr_bin_str);
	}

	return 0;
}

int parse_reg (char reg_num, char* instr_bin_str)
{
	const char* R_value;
	switch (reg_num)
	{
	case '0':
		R_value = "000";
		strcpy(instr_bin_str, R_value);
		break;
	case '1':
		R_value = "001";
		strcpy(instr_bin_str, R_value);
		break;
	case '2':
		R_value = "010";
		strcpy(instr_bin_str, R_value);
		break;
	case '3':
		R_value = "011";
		strcpy(instr_bin_str, R_value);
		break;
	
	default:
		break;
	}
}

unsigned short int str_to_bin (char* instr_bin_str)
{
   char *ptr;
   long ret;

   ret = strtol(instr_bin_str, &ptr, 2);
   printf("Hexadecimal representation of the above instructions: %lx\n", ret);
//    printf("String part is |%s|", ptr);

   return ret;
}

int write_obj_file (char* filename, unsigned short int program_bin[ROWS] )
{
	char *object_file;
	object_file = strtok(filename, ".");
	strcat(object_file, ".obj");

	char hexadecimalnum[ROWS][4];
	int num_rows = 0;

	for (size_t k = 0; k < ROWS; k++)
	{
		long quotient, remainder;
		int i, j = 3;
		quotient = program_bin[k];

    	while (quotient != 0)
		{
			remainder = quotient % 16;
			if (remainder < 10)
				hexadecimalnum[k][j--] = 48 + remainder;
			else
				hexadecimalnum[k][j--] = 55 + remainder;
			quotient = quotient / 16;

			num_rows++;
		}
	}
	
	
	char endian_format[] = "0xDECA ";
	char address[] = "0x0000 ";
	num_rows = num_rows/4;
	char buf[sizeof(num_rows)];
	snprintf(buf, sizeof(num_rows), "%d", num_rows);

	char header[(sizeof(endian_format) + (sizeof(address) + sizeof(buf)/4)) - 1];
	strcpy(header, endian_format);
	strcat(header, address);
	strcat(header, buf);

	FILE *fptr;
	fptr = fopen(object_file, "wb");

	fwrite(header, sizeof(header), 1, fptr);

	for (size_t l = 0; l < num_rows; l++)
	{
		fwrite("\n", 1, 1, fptr);
		fwrite(hexadecimalnum[l], sizeof(hexadecimalnum[l]), 1, fptr);
	}
	fclose(fptr);


	return 0;
}
