# bfmips

A Brainfuck Compiler

Purpose
--- 

This compiler is a project serves as a segue into larger compiler projects. 


What does this do?
---

It compiles [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) into assembly with optimizations. Because Brainfuck only has 8 instructions, programs like HelloWorld become long; the goal is to compile Brainfuck into as small of a program as possible. This was done by merging instructions of the same type together and removing redundant code. Currently, the compiler only targets MIPS. 


Compiling
---

Compile this project with 
```
gcc -o bfmips main.c parse.c lexer.c mips_gen.c
```
Run the compiler with
```
./bfmips <input.bf>
```
The file will be outputted to input.asm

TODO
---
- Target x86
- More advanced dead code removal