#include "../lex/lex.h"
#include "../stubs/io.h"
#include <stdio.h>
#include <cassert>

int UTLex()
{
    printf("[UT] Lex def\n");
    MockInput("def fucker");
    assert(get_tok() == tok_def);

    printf("[UT] Lex extern\n");
    MockInput("extern fucker");
    assert(get_tok() == tok_extern);

    printf("[UT] Lex def with some comments\n");
    MockInput("#uooo!\ndef fucker");
    assert(get_tok() == tok_def);

    printf("[UT] Lex identifier\n");
    MockInput("int");
    assert(get_tok() == tok_identifier);

    /* not implemented
    printf("[UT] Lex number\n");
    MockInput("400");
    assert(get_tok() == tok_number);*/
    return 0;
}

int main(void){
    EnableMock();
    if (UTLex() != 0)
        return -1;
    printf("[UT] Lex seems good!\n");
    return 0;
}
