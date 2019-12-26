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


lst				*create_maillon(void);
void		ft_alloc(lst **grp, lst **curr, lst **tt);
int		cardinal(lst *e);

int     check_repete(lst *tt, float x, int i);

void    trouver_intersection(group *A, group *B);
void    trouver_union(group *A, group *B);
void    trouver_element(float x, group *E);
int     verifier_egalite(group *A, group *B);
int     verifier_inclusion(group *A, group *B);
void    afficher_group(group *E);
