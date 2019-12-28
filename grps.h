# include <stdio.h>
# include <stdlib.h>

typedef struct lst
{
	float 		n;
	struct lst 	*next;
}  lst;

typedef struct group
{
    lst             *lst;
    int             card;
    char            name;
    struct group    *next;
}   group;


lst				*create_maillon(void);
void		ft_alloc(lst **grp, lst **curr, lst **tt);

void	ajouter_maillon(group *c, group *a);
group	*trouver_dernier_maillon(group *a);



group    *affect_premiers_groups(void);
group	*remplir_ensemble(float *a, int size, char name);



int		cardinal(lst *e);

int     check_repete(lst *tt, float x, int i);

void    trouver_intersection(group *A, group *B);
void    trouver_union(group *A, group *B);
void    trouver_element(float x, group *E);
int     verifier_egalite(group *A, group *B);
int     verifier_inclusion(group *A, group *B);

void    afficher_group(group *E);


void    afficher_tout(group **A);
void     creer_ensemble(group **A);
