#ifndef CSTRINGORGANIZE_H_INCLUDED
#define CSTRINGORGANIZE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define KBStringArrayLimit 100

struct CStringO
{
    char * str;
    unsigned short str_length;
};

struct CStringOArray
{
    struct CStringO * kbstr;
    unsigned short array_length;
    unsigned short array_max_length;
};

unsigned long Cstr2KBstr_Hash(struct CStringO * kbstr,char * cstr);
inline void KBstr_Delete(struct CStringO * kbstr);

void AddToStringArray(struct CStringOArray * kbarr,char * cstr);
unsigned long GetArrayLength(struct CStringOArray * kbarr);
void DeleteStringArray(struct CStringOArray * kbarr);






#ifdef __cplusplus
}
#endif


#endif // CSTRINGORGANIZE_H_INCLUDED
