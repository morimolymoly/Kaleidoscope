#include <string>
#include "../stubs/io.h"
#include "lex.h"

static std::string IdentifierStr;
static double NumVal;

int get_tok()
{
    static int LastChar = ' ';
    while(isspace(LastChar))
        LastChar = GetChar();

    if(isalpha(LastChar)) {
        IdentifierStr = LastChar;
        while(isalnum((LastChar = GetChar())))
            IdentifierStr += LastChar;

        if(IdentifierStr == "def")
            return tok_def;
        if(IdentifierStr == "extern")
            return tok_extern;
        return tok_identifier;
    }

    if(LastChar == '#') {
        do
            LastChar = GetChar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if(LastChar != EOF) {
            return get_tok();
        }
    }

    if(LastChar == EOF)
        return tok_eof;
    int ThisChar = LastChar;
    LastChar = GetChar();
    return ThisChar;
}
