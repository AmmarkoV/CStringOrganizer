#include "CStringOrganize.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

const char * ver=" 0.001 8/2/10 \0";

char * CStringOrganizer_Version()
{
  return (char *) ver;
}

// *******************************************************************************
// *******************************************************************************
// HELPER FUNCTIONS
// *******************************************************************************
void cso_UpcaseIt(unsigned char * text,unsigned int textsize) //Metatrepei String se Upcase
{
  unsigned int i;
  for (i=0; i<textsize; i++) text[i]=toupper(text[i]);
}

char cstrEqualNoCase(char * str1,char * str2)
{
  int len = strlen(str1);
  int i;
  if ( len != strlen(str2) ) { return 0; }
  for (i=0; i<len; i++ )
   {
     if ( toupper(str1[i]) != toupper(str2[i]) ) { return 0; }
   }
  return 1;
}

inline unsigned long cso_inline_sdbm(char *str)
{
  unsigned long hash = 0;
  int c;
  while (c = *str++) hash = c + (hash << 6) + (hash << 16) - hash;
  return hash;
}
// *******************************************************************************
// HELPER FUNCTIONS
// *******************************************************************************
// *******************************************************************************

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// *******************************************************************************
// *******************************************************************************
// STRING FUNCTIONS
// *******************************************************************************
char StoreCstr(struct CStringO * org_str,char * cstr)
{
    // If org_str contains another string it will be replaced
    if  ( org_str->str!=0 ) { free(org_str->str); }
    unsigned short len = strlen(cstr);

    org_str->str = (char *) malloc(sizeof(char) * (len+1) ); // + zero termination
    org_str->str_length = len;
    strcpy (org_str->str , cstr) ;

    return 1;
}

unsigned long StoreCstr_Hash(struct CStringO * org_str,char * cstr)
{
    if ( StoreCstr(org_str,cstr)==1 ) {  return cso_inline_sdbm(cstr); }
    return 0;
}

void Delete_OString(struct CStringO * org_str)
{
    if  ( org_str->str!=0 ) { free(org_str->str); }
    org_str->str_length=0;
    return;
}
// *******************************************************************************
// STRING FUNCTIONS
// *******************************************************************************
// *******************************************************************************


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// *******************************************************************************
// *******************************************************************************
// STRINGARRAY FUNCTIONS
// *******************************************************************************
char CreateOStringArray(struct CStringOArray * ostr_array,unsigned int array_length)
{
    fprintf(stderr,"CreateOStringArray Called!\n");
    if  ( ostr_array->array!=0 )  DeleteOStringArray(ostr_array);
    if  ( ostr_array->array==0 )
    {
      ostr_array->array = ( struct CStringO * ) malloc ( sizeof(struct CStringO) * array_length );
      if (ostr_array->array==0) { fprintf(stderr,"Error Allocating Organized String memory\n"); return 0;  }

      ostr_array->array_length=0;
      ostr_array->array_max_length=array_length;
      int i;
      for ( i=0; i<array_length; i++)
      {
         ostr_array->array[i].str=0;
         ostr_array->array[i].str_length=0;
         // Clear Everything!
      }
    } else
    { fprintf(stderr,"Error Organized String Array wasn`t cleared properly , cannot reallocate memory\n"); return 0; }
    return 1;
}

char IncreaseOStringArrayLength(struct CStringOArray * ostr_array,unsigned int inc_array_length)
{
   fprintf(stderr,"IncreaseOStringArrayLength Called!\n");
   if  ( ostr_array->array==0 ) {  return CreateOStringArray(ostr_array,inc_array_length); } // No array increasing means creating! :)
   else
   {
     //Reallocate memory..!
     struct CStringO * bigger_ostr_array;
     bigger_ostr_array = ( struct CStringO * ) malloc ( sizeof(struct CStringO) * (ostr_array->array_max_length+inc_array_length) );

     int i;
     for ( i = 0; i<ostr_array->array_max_length; i++ )
     {
         bigger_ostr_array[i] = ostr_array->array[i];
     }

     free (ostr_array->array);
     ostr_array->array = bigger_ostr_array;
     ostr_array->array_max_length+=inc_array_length;


     return 1;
   }
   return 0;
}

char DeleteOStringArray(struct CStringOArray * ostr_array)
{   fprintf(stderr,"DeleteOSString Called!\n");
    if  ( ostr_array->array==0 )
    {
      // STRING ALREADY DELETED , Nothing to do!
    } else
    {
      int i;
      for ( i=0; i<ostr_array->array_max_length; i++)
      {
         Delete_OString(&ostr_array->array[i]);
      }
      // This should clean all allocated memory , now freeing the array structure itself
      free(ostr_array->array);
    }

    return 1;
}

char AddToOStringArray(struct CStringOArray * org_arr,char * cstr)
{
    if  ( ( org_arr->array==0 ) || (org_arr->array_max_length==0) )
    {
       // THERE IS NO String Array allocated..! , fix it!
       if ( CreateOStringArray(org_arr,ArrayReservedSpaceForNewStrings) == 0 ) { return 0; }
    }

    if  (org_arr->array_length+1>=org_arr->array_max_length)
    {
       // Reallocate String Memory!
       IncreaseOStringArrayLength(org_arr,ArrayReservedSpaceForNewStrings);
    }

    unsigned int mem = org_arr->array_length;
    char retres = StoreCstr(&org_arr->array[mem],cstr);
    if (retres == 1 ) org_arr->array_length+=1;

    return retres;
}

signed int CheckOStringArrayContainsCStr(struct CStringOArray * ostr_array,char * cstr)
{
     int i;
     for ( i = 0; i<ostr_array->array_max_length; i++ )
     {
          if ( cstrEqualNoCase(ostr_array->array[i].str,cstr)!=0 ) { return i; }
     }
  return -1;
}

unsigned long GetOStringArrayLength(struct CStringOArray * org_arr)
{
    if  ( org_arr->array==0 ) return 0; // No array -> 0 length ..!
    return org_arr->array_length;
}
// *******************************************************************************
// STRINGARRAY FUNCTIONS
// *******************************************************************************
// *******************************************************************************


