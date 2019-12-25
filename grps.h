# include <stdio.h>
# include <stdlib.h>

typedef struct lst
{
	float 		n;
	struct lst 	*next;
}  lst;

typedef struct group
{
    lst   *lst;
    int     card;
    char    name;
}   group;
