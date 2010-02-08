#include <stdio.h>
#include <stdlib.h>
#include "../CStringOrganize.h"

int main()
{
    printf("C String Tester %s ! --------------------- \n",CStringOrganizer_Version());

    struct CStringOArray array_of_cstrings={0};
    struct CStringO cstrings={0};

    Organize_Cstr_Hash(&cstrings,"HELLO WORLD\0");
    printf("Simple CString copy with value `%s` , length is `%u` \n",cstrings.str,cstrings.str_length);

    AddToOStringArray(&array_of_cstrings,"FIRST STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[0].str,array_of_cstrings.array[0].str_length);

    AddToOStringArray(&array_of_cstrings,"SECOND STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[1].str,array_of_cstrings.array[1].str_length);

    AddToOStringArray(&array_of_cstrings,"THIRD STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[2].str,array_of_cstrings.array[2].str_length);

    return 0;
}
