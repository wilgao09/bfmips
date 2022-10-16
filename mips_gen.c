

#include <stdio.h>
#include <stdlib.h>
#include "mips_gen.h"
#include "parse.h"

FILE *out;
int next_chain_num = 1;

void sb()
{
    fprintf(out, "sb $t1, 0($t0)\n");
}

void lb()
{
    fprintf(out, "lbu $t1, 0($t0)\n");
}

void write_chain(struct Node *n, int chain_num)
{
    if (n->action == 'm')
    {
        fputs(".data\n\tmemory: .space 30000\n.text\n.globl _main\n_main:\nla $t0, memory\n", out);
    }
    if (n->action == 'v' && n->v != 0)
    {
        lb();
        fprintf(out, "addi $t1, $t1, %d\n", n->v);
        sb();
    }
    else if (n->action == 'p')
    {
        fprintf(out, "addi $t0, $t0 %d\n", n->v);
    }
    else if (n->action == ',')
    {
        fprintf(out, "addi $v0, $0, 12\nsyscall\nmove $t1, $v0\n");
        sb();
    }
    else if (n->action == '.')
    {
        lb();
        fprintf(out, "move $a0, $t1\naddi $v0, $0, 11\nsyscall\n");
    }
    else if (n->action == 'l')
    {
        fprintf(out, "l%d:\n", next_chain_num);
        next_chain_num++;
        write_chain(n->children, next_chain_num - 1);
    }
    else if (n->action == 'n')
    {
        lb();
        fprintf(out, "bnez $t1, l%d\n", chain_num);
        return;
    }
    if (n->next != NULL && n->next->action != 0)
    {
        write_chain(n->next, chain_num);
    }
}

void generate_mips(struct Node *n, char *o)
{
    out = fopen(o, "w+");
    write_chain(n, 0);
    fputs("addi $v0, $0, 10\nsyscall\n", out);
}
