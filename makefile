assembler: assembler.c asm_parser.c
	gcc -o assembler assembler.c asm_parser.c -I.