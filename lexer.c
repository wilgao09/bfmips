
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

FILE *f;

const char pi = '>';
const char pd = '<';
const char vi = '+';
const char vd = '-';
const char lo = '[';
const char lc = ']';
const char bi = ',';
const char bo = '.';
const char ef = ' ';


void set_focus_file(char *path) {
    f = fopen(path, "r");
}

char get_next_token() {
    while (1) {
        int nC = fgetc(f);
        if (nC == EOF) {
            return ef;
        }
        switch (nC) {
            case (43):
                return vi;
                break;
            case (45):
                return vd;
                break;
            case (60):
                return pd;
                break;
            case (62):
                return pi;
                break;
            case (91):
                return lo;
                break;
            case (93):
                return lc;
                break;
            case (46):
                return bo;
                break;
            case (44):
                return bi;
                break;
        }
    }

}