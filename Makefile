
GCC=gcc


build:
	$(GCC) main.c lexer.c mips_gen.c parse.c -o bfmips
