#include "CStringOrganize.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// *******************************************************************************
// *******************************************************************************
// *******************************************************************************
// HELPER FUNCTIONS
// *******************************************************************************
void UpcaseIt(unsigned char * text,unsigned int textsize) //Metatrepei String se Upcase
{
  unsigned int i;
  for (i=0; i<textsize; i++) text[i]=toupper(text[i]);
}


inline unsigned long inline_sdbm(char *str)
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
// *******************************************************************************


// *******************************************************************************
// *******************************************************************************
// STRING FUNCTIONS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

unsigned long Cstr2KBstr_Hash(struct CStringO * kbstr,char * cstr)
{
    if  ( kbstr->str!=0 ) { free(kbstr->str); }
    unsigned short len = strlen(cstr);

    kbstr->str = (char *) malloc(sizeof(char) * (len+1) ); // + zero termination
    kbstr->str_length = len;
    strcpy (kbstr->str , cstr) ;

    return inline_sdbm(cstr);
}

void KBstr_Create(struct CStringO * kbstr)
{
    if  ( kbstr->str!=0 ) { free(kbstr->str); }
    return;
}

void KBstr_Delete(struct CStringO * kbstr)
{
    if  ( kbstr->str!=0 ) { free(kbstr->str); }
    return;
}

void AddToStringArray(struct CStringOArray * kbarr,char * cstr)
{/*
    if  ( kbarr->kbstr==0 )
    {
      kbarr->kbstr = (struct KBString * ) malloc ( sizeof(struct KBString) * ( KBStringArrayLimit + 1 ) );
    } else
    if ( kbarr->array_length+1 >= kbarr->array_max_length )
    {

    }
*/
    //Cstr2KBstr_Hash(struct KBString * kbstr,char * cstr)

    return;
}

void DeleteStringArray(struct CStringOArray * kbarr)
{/*
    if  ( kbarr->kbstr==0 )
    {
    } else
    {
      int i=0;
     // for ( i=0 i<kbarr->array_max_length
    }
*/
    return;
}

unsigned long GetArrayLength(struct CStringOArray * kbarr)
{
    if  ( kbarr->kbstr==0 ) return 0; // No array -> 0 length ..!
    return kbarr->array_length;
}
// STRING FUNCTIONS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// *******************************************************************************
// *******************************************************************************


