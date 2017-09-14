#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int valueInList(char*,char*);
int valueNotInList(char*,char*);
int valueInListInt(long long int , char*);
int valueNotInListInt(long long int , char*);

int main()
{
    char *string = NULL;
    string = "9930|9998|9999";
    int x = 10000;

    /* **********************
     * Examples
     *
     * valueNotInListStr("10000",string);
     * valueInListStr("10000",string);
     *
     *
     * valueNotInListInt(x,string);
     * valueInListInt(10000,string);
     */

    return valueNotInListStr("10000",string);
}

/* ****************************************************
 * Author:    Martin De Luca
 * Date:      14/09/2017
 * Version:   2.0
 * ***************************************************/
int valueInListStr(char *value, char *ValueList)
{
    if(value == NULL || ValueList == NULL)
        return -1;

    const char *sep = "|";
    char *tok = NULL;

    char *ValueListCopy = (char*) malloc(strlen(ValueList)*sizeof(char)+1);
    strcpy(ValueListCopy,ValueList);

    tok = strtok(ValueListCopy,sep);
    if(tok==NULL)
    {   free(ValueListCopy);
        return -1;
    }

    while(tok)
    {   if(strcmp(value,tok)==0)
        {   free(ValueListCopy);
            return 1;
        }
        tok = strtok (NULL, sep);
    }

    free(ValueListCopy);
    return 0;
}

/* ****************************************************
 * Author:    Martin De Luca
 * Date:      14/09/2017
 * Version:   2.0
 * ***************************************************/
int valueNotInListStr(char *value, char *ValueList)
{
    if(value == NULL || ValueList == NULL)
        return -1;

    const char *sep = "|";
    char *tok = NULL;

    char *ValueListCopy = (char*) malloc(strlen(ValueList)*sizeof(char)+1);
    strcpy(ValueListCopy,ValueList);

    tok = strtok(ValueListCopy,sep);
    if(tok==NULL)
    {   free(ValueListCopy);
        return -1;
    }

    while(tok)
    {   if(strcmp(value,tok)==0)
        {   free(ValueListCopy);
            return 0;
        }
        tok = strtok (NULL, sep);
    }

    free(ValueListCopy);
    return 1;
}

/* ****************************************************
 * Author:    Martin De Luca
 * Date:      14/09/2017
 * Version:   2.0
 * ***************************************************/
int valueInListInt(long long int value, char *ValueList)
{
    if(ValueList == NULL)
        return -1;

    const char *sep = "|";
    char *tok = NULL;
    long long int tok_int=0;

    char *ValueListCopy = (char*) malloc(strlen(ValueList)*sizeof(char)+1);
    strcpy(ValueListCopy,ValueList);

    tok = strtok(ValueListCopy,sep);
    if(tok==NULL)
    {   free(ValueListCopy);
        return -1;
    }

    while(tok)
    {   tok_int=strtoll(tok, NULL, 10);
        if(value==tok_int)
        {   free(ValueListCopy);
            return 1;
        }
        tok = strtok (NULL, sep);
    }

    free(ValueListCopy);
    return 0;
}

/* ****************************************************
 * Author:    Martin De Luca
 * Date:      14/09/2017
 * Version:   2.0
 * ***************************************************/
int valueNotInListInt(long long int value, char *ValueList)
{
    if(ValueList == NULL)
        return -1;

    const char *sep = "|";
    char *tok = NULL;
    long long int tok_int=0;

    char *ValueListCopy = (char*) malloc(strlen(ValueList)*sizeof(char)+1);
    strcpy(ValueListCopy,ValueList);

    tok = strtok(ValueListCopy,sep);
    if(tok==NULL)
    {   free(ValueListCopy);
        return -1;
    }

    while(tok)
    {   tok_int=strtoll(tok, NULL, 10);
        if(value==tok_int)
        {   free(ValueListCopy);
            return 0;
        }
        tok = strtok (NULL, sep);
    }

    free(ValueListCopy);
    return 1;
}

