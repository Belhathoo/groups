
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