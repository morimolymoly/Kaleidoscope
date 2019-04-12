#include "io.h"
#include <string>

bool testFlag = false;
char *mock_string;

char MockInput(char *input){
    mock_string = input;
}

void EnableMock()
{
    testFlag = true;
}

char getcharstub()
{
    return *mock_string++;
}

char GetChar()
{
    if (testFlag)
        return getcharstub();
    return getchar();
}
