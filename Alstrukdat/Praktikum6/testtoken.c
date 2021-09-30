#include "tokenmachine.c"
#include "charmachine.c"

int main()
{
    startToken();
    while (!endToken)
    {
        printf("%c,%d\n", currentToken.tkn, currentToken.val);
        advToken();
    }
    return 0;
}