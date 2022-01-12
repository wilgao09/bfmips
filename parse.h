#ifndef PARSE_H
#define PARSE_H

enum TargetCode {
    MIPS
};

struct Node {
    char action; //can be 'v', 'p', ',' , '.', 'l', 'm', or 'n'
    int v;
    struct Node *next;
    struct Node *children;
};

void feed_token(char tok);

void init_parser();
int generate_target(enum TargetCode t, char *outfile);
void print_progAST();

struct RetLocNode{
    struct RetLocNode *next;
    struct Node *next_write;
};

struct Stack {
    struct RetLocNode *s;
    int size;
};

void initialize_stack(struct Stack *s);
void push(struct Stack *s, struct Node *nw);
struct Node *pop(struct Stack *s);



#endif