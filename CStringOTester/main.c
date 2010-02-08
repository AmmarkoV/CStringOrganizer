#include <stdio.h>
#include <stdlib.h>
#include "../CStringOrganize.h"

int main()
{
    printf("C String Tester ! --------------------- \n");

    struct CStringOArray array_of_cstrings;
    struct CStringO cstrings;

    Cstr2KBstr_Hash(&cstrings,"HELLO WORLD\0");
    printf("Simple CString copy with hash `%s` , length is `%u` ",cstrings.str,cstrings.str_length);

    return 0;
}
