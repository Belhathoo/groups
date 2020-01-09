
#include "grps.h"

group    *affect_premiers_groups(void)
{
   	float	a[11] = {-20, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//	float	b[10] = {-20, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float	b[12] = {-9, -8, 0, 10, 0 , 3, 40, 55, 60, 70, 80, 9};
   	group	*A = NULL;

	A = remplir_ensemble(a, 11,'A');
	A->next = remplir_ensemble(b, 12,A->name + 1);
	A->card = cardinal(A->lst);
	A->next->card = cardinal(A->next->lst);
    return (A);
}   

void    afficher_tout(group **A)
{
    group *tmp;

    tmp = *A;
    printf("\n*** Les Ensembles Disponibles:\n");
    while (tmp)
    {
        afficher_group(tmp);
        tmp = tmp->next;
    }
    //A = tmp;
}

void   creer_ensemble(group **A)
{
    group   *e;
    group   *head;
    lst     *curr;
    lst     *tt;
    int     size = 0;
    int     i = 0;

    printf("\t\tCreer Un Ensemble:\n");
    head = *A;
    tt = NULL;
    printf("\n Donnez Le Nombre Des Elements De Votre Ensemble: ");
    scanf("%d", &size);
        
    e = (group *)malloc(sizeof(group));
    e->next = NULL;
    
    curr = create_maillon();        
    while(i < size)
    {

        printf("Inserez l'element %d: ",i + 1);
        scanf("%e", &curr->n);
        if ((check_repete(tt, curr->n, i) == 1))
			i++;
        else
        {
            
            ft_alloc(&e->lst, &curr, &tt);          
            printf("\n");
            i++;
        }
    }
    free(curr);
    e->lst = tt;
    while ((*A)->next)
        (*A) = (*A)->next;
    e->name = (*A)->name + 1;
    e->card = cardinal(e->lst);
    (*A)->next = e;
    (*A) = head;
}

group   *check_grp(char X, group *A)
{
    group   *e;

    while(A)
    {
        if (A->name == X)
            return (A);
        A = A->next;
    }
    return (NULL);
}

void    creer_intersection(group **A)
{
    group   *e;
    group   *a;
    group   *b;

    char    g;
    char    buff;
    int     nb;

	printf("\tCalculer L'Intersection De Deux Ensembles:\n");
    afficher_tout(A);
    printf("Entrez 2 groupes: \n");
    e = (*A);
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;
    if ((a = check_grp(g, e)) == NULL)
    {
        printf("\nCe groupe n'existe pas!");
        free(a);
        return ;
    }
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;    
    if ((b = check_grp(g, e)) == NULL)
    {
        printf("Ce groupe n'existe pas!");
        free(a);
        free(b);
        return ;
    }
    while ((*A)->next)
        (*A) = (*A)->next;
    (*A)->next = trouver_intersection(a, b);
    (*A)->next->name = (*A)->name + 1;
    printf("*** I L'intersection de %c et %c :\n",a->name, b->name);
	afficher_group((*A)->next);
    (*A) = e;
}

void    creer_union(group **A)
{
    group   *e;
    group   *a;
    group   *b;

    char    g;
    char    buff;
    int     nb;

	printf("\tCalculer L'Union De Deux Ensembles:\n");
    afficher_tout(A);
    printf("Entrez 2 groupes: \n");
    e = (*A);
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;
    if ((a = check_grp(g, e)) == NULL)
    {
        printf("\nCe groupe n'existe pas!");
        free(a);
        return ;
    }
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;    
    if ((b = check_grp(g, e)) == NULL)
    {
        printf("Ce groupe n'existe pas!");
        free(a);
        free(b);
        return ;
    }
    while ((*A)->next)
        (*A) = (*A)->next;
    (*A)->next = trouver_union(a, b);
    (*A)->next->name = (*A)->name + 1;
    printf("*** L'Union de %c et %c :\n%c U %c = ",a->name, b->name,a->name, b->name);
	afficher_group((*A)->next);
    (*A) = e;
}

void    test_appartenance(group **A)
{
    float   x;
    char    g;
    char    buff;
    int     nb;
    group   *e;
    group   *a;

	printf("\tTester L'appartenance d'Un Element à Un Ensemble:\n");
    e = (*A);
    printf("Entrez l'élément puis l'Ensemble:\n");
    scanf("%e", &x);
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;
    if ((a = check_grp(g, e)) == NULL)
    {
        printf("\nCe groupe n'existe pas!");
        free(a);
        return ;
    }
    trouver_element(x, a);
}

void    comparer_ensembles(group **A)
{
    group   *e;
    group   *a;
    group   *b;
    char    g;
    char    buff;
    int     nb;

    printf("<<<Comparer Deux Ensemblles:>>>");
    afficher_tout(A);
    printf("Entrez 2 groupes: \n");
    e = (*A);
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;
    if ((a = check_grp(g, e)) == NULL)
    {
        printf("\nCe groupe n'existe pas!");
        free(a);
        return ;
    }
    while((nb = read(0, &buff, 1)) && buff != '\n')
        g = buff;    
    if ((b = check_grp(g, e)) == NULL)
    {
        printf("Ce groupe n'existe pas!");
        free(a);
        free(b);
        return ;
    }
    verifier_egalite(a, b);
}