#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valueInList(char*,char*);


main()
{
    char *string = NULL;

    string = "Ori|Boldi|C|D|E|F|G|H|I|L|M|N|O";

    return valueInList("Z",string);
}

int valueInList(char *value, char *ValueList)
{
    if(value == NULL || ValueList == NULL)
        return -1;

    char ** res  = NULL;
    const char *sep = "|";
    char *tok = NULL;
    int n_sep = 0,i;

    char *ValueListCopy = (char*) malloc(strlen(ValueList)*sizeof(char)+1);
    strcpy(ValueListCopy,ValueList);

    tok = strtok(ValueListCopy,sep);
    if(tok==NULL)
    {   free(ValueListCopy);
        return -1;
    }

    /* split string and append tokens to 'res' */
    while(tok)
    {   res = (char**) realloc (res, sizeof (char*) * ++n_sep);
        if(res == NULL)
        {   free(res);
            free(ValueListCopy);
            return -1; /* memory allocation failed */
        }

        res[n_sep-1] = tok;
        tok = strtok (NULL, sep);
    }

    /* realloc one extra element for the last NULL */
    res = (char**) realloc (res, sizeof (char*) * (n_sep+1));
    res[n_sep] = 0;

    for (i=0; i < n_sep;++i)
    {   if(strcmp(value,res[i])==0)
        {   return 1;
            free(res);
            free(ValueListCopy);
        }
    }

    free(res);
    free(ValueListCopy);
    return 0;
}

