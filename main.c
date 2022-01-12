
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "parse.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Expected one file argument, but found %d", argc - 1);
        return 1;
    }
    set_focus_file(argv[1]);
    init_parser();
    char t;
    while ( (t=get_next_token()) != ' ' ) {
        feed_token(t);
    }
    char *fsloc;
    char *outfile = malloc(sizeof(char) * (4+strlen(argv[1])));
    fsloc=strchr(argv[1], '.');
    if (  fsloc   == NULL   ) {
        outfile = argv[1];
    } else {
        *fsloc = '\0'; //wtf?
        strcpy(outfile, argv[1]);
        *fsloc = '.';
    }
    strcat(outfile,".asm");
    generate_target(MIPS, outfile);


    
    return 0;
}