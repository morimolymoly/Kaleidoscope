#include "../lex/lex.h"
#include "../stubs/io.h"
#include <stdio.h>

int main(void){

    int actual;
    char *test_def = "def fucker";
    MockInput("def fucker");
    EnableMock();
    actual = get_tok();
    if(actual == -2){
        printf("[UT] get_tok def is seems good\n");
    }else{
        printf("[UT] get_tok def seems bad\n");
        return -1;
    }
    return 0;
}
