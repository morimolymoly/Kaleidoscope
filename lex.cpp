#include <string>

namespace kaleidoscope
{

enum Token
{
    tok_eof = -1,

    tok_def = -2,
    tok_extern = -3,

    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierStr;
static double NumVal;

int get_tok()
{
    static int LastChar = ' ';
    while(isspace(LastChar))
        LastChar = getchar();

    if(isalpha(LastChar)) {
        IdentifierStr = LastChar;
        while(isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;

        if(IdentifierStr == "def")
            return tok_def;
        if(IdentifierStr == "extern")
            return tok_extern;
        return tok_identifier;
    }

    if(LastChar == '#') {
        do
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if(LastChar != EOF) {
            return get_tok();
        }
    }

    if(LastChar == EOF)
        return tok_eof;
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}
}

int main(void){
    printf("%d\n", kaleidoscope::get_tok());
    return 0;
}
