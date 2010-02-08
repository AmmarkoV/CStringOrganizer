#ifndef CSTRINGORGANIZE_H_INCLUDED
#define CSTRINGORGANIZE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define ArrayReservedSpaceForNewStrings 100

/*
  Some naming rationale :P
  CStringO meanse CString Organized
  OString means OrganizedString
  org_arr means OrganizedString Array
  org_str meanse OrganizedString :P
*/

typedef unsigned short stringsize;

struct CStringO
{
    char * str;
    unsigned short str_length;
};

struct CStringOArray
{
    struct CStringO * array;
    unsigned short array_length;
    unsigned short array_max_length;
};

char * CStringOrganizer_Version();

unsigned long StoreCstr_Hash(struct CStringO * org_str,char * cstr);
char StoreCstr(struct CStringO * org_str,char * cstr);

void Create_OString(struct CStringO * org_str);
void Delete_OString(struct CStringO * org_str);

char AddToOStringArray(struct CStringOArray * org_arr,char * cstr);
unsigned long GetOStringArrayLength(struct CStringOArray * org_arr);
signed int CheckOStringArrayContainsCStr(struct CStringOArray * ostr_array,char * cstr);
char DeleteOStringArray(struct CStringOArray * org_arr);






#ifdef __cplusplus
}
#endif


#endif // CSTRINGORGANIZE_H_INCLUDED
