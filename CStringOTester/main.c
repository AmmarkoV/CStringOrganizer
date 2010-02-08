#include <stdio.h>
#include <stdlib.h>
#include "../CStringOrganize.h"

int main()
{
    printf("C String Tester %s ! --------------------- \n\n\n",CStringOrganizer_Version());

    struct CStringOArray array_of_cstrings={0};
    struct CStringO cstrings={0};

    StoreCstr_Hash(&cstrings,"HELLO WORLD\0");
    printf("Simple CString copy with value `%s` , length is `%u` \n",cstrings.str,cstrings.str_length);

    AddToOStringArray(&array_of_cstrings,"FIRST STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[0].str,array_of_cstrings.array[0].str_length);

    AddToOStringArray(&array_of_cstrings,"SECOND STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[1].str,array_of_cstrings.array[1].str_length);

    AddToOStringArray(&array_of_cstrings,"THIRD STRING");
    printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[2].str,array_of_cstrings.array[2].str_length);

    int i;
    for ( i=0; i<258; i++)
     {
           AddToOStringArray(&array_of_cstrings,"N STRING");
     }


    for ( i=0; i<258; i++)
     {
           printf("Simple CString array with value `%s` , length is `%u` \n",array_of_cstrings.array[2+i].str,array_of_cstrings.array[2+i].str_length);
     }

    DeleteOStringArray(&array_of_cstrings);

    return 0;
}
