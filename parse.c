

#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "mips_gen.h"


struct Node *nnwl = NULL;
struct Stack stack = {
    .s = NULL,
    .size = 0,
};
struct Node top = {
    .action = 'm',
    .v = 30000,
    .next = NULL,
    .children = NULL,
};





void initialize_stack(struct Stack *s) {
    s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = 0;
}
void push(struct Stack *s, struct Node *nw) {
    struct RetLocNode *r = (struct RetLocNode*)(malloc(sizeof(struct RetLocNode)));
    r->next = s->s;
    r->next_write = nw;
    s->s = r;
    s->size++;
}
struct Node *pop(struct Stack *s) {
    if (s->size == 0) {
        return NULL;
    }
    struct RetLocNode *ptr = s->s;
    s->s = s->s->next;
    s->size--;
    struct Node *toR = ptr->next_write;
    free(ptr);
    return toR;
}

struct Node *create_nw(struct Node *w) {
    if (w == NULL) {
        w = (struct Node*)malloc(sizeof(struct Node));
        return w;
    } else {
        struct Node *n  = (struct Node*)malloc(sizeof(struct Node));
        w->next = n;
        return n;
    }
}


void init_parser() {
    nnwl = create_nw(nnwl);
    top.next = nnwl;
}

//TODO: lots of optimizing here
void feed_token(char tok) {
    //print_progAST();
    if (tok == '[') {
        if (nnwl->action != 0) {
            nnwl = create_nw(nnwl);
        }
        nnwl->action = 'l';
        nnwl->v = 0;
        nnwl->next = NULL;
        nnwl->children=NULL;
        nnwl->children = create_nw(nnwl->children);

        push(&stack, nnwl);
        nnwl = nnwl->children;

    } else if (tok == ']') {
        if (nnwl->action != 0) {
            nnwl = create_nw(nnwl);
        }
        nnwl->action = 'n';
        nnwl->v = 0;
        nnwl->next = NULL;
        nnwl->children = NULL;
        struct Node *t = pop(&stack);
        if (t == NULL) {
            printf("MISMATCHED LOOP BRACE");
            return;
        } else {
            create_nw(t);
            nnwl = t;
        }
        
    } else if (tok =='+' || tok == '-') {
        if (nnwl->action != 'v' && nnwl->action != 0) {
            nnwl = create_nw(nnwl);
        }
        nnwl->action = 'v';
        if (tok == '+') {
            nnwl->v+=1;
        } else {
            nnwl->v-=1;
        }
        
        nnwl->next = NULL;
        nnwl->children = NULL;
    } else if (tok == '.' || tok == ',') {
        if (nnwl->action != 0) {
            nnwl = create_nw(nnwl);
        }
        nnwl->action = tok;
        nnwl->next = NULL;
        nnwl->children = NULL;
    } else if (tok == '<' || tok == '>') {
        if (nnwl->action != 'p') {
            nnwl = create_nw(nnwl);
        }
        nnwl->action = 'p';
        if (tok == '<') {
            nnwl->v-=1;
        } else {
            nnwl->v +=1;
        }
        nnwl->next = NULL;
        nnwl->children = NULL;
    }
}


int generate_target(enum TargetCode t, char *outfile) {
    if (stack.size != 0) {
        printf("WARNING: program will fall through: unmatched [");
    }
    if (t == MIPS) {
        generate_mips(&top, outfile);
    }   
}

void print_progAST() {
    print_AST(&top, 0);
}

void print_AST(struct Node *n, int ind) {
    if (n == NULL) {
        return;
    }
    for (int i = 0 ;i != ind; i++) {
        printf("\t");
    }
    printf("Node type %d, value %d\n", n->action, n->v);
    if (n->children != NULL) {
        print_AST(n->children, ind+1);
    }
    if (n->next != NULL) {
        print_AST(n->next, ind);
    }
}
