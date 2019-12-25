#include "grps.h"


lst				*create_maillon(void)
{
	lst			*args;

	if (!(args = (lst *)malloc(sizeof(lst))))
		return (NULL);
	args->next = NULL;
	return (args);
}


void		ft_alloc(lst **grp, lst **curr, lst **tt)
{
	if ((*grp) == NULL)
	{
		(*grp) = create_maillon();
		(*tt) = (*grp);
		(*grp)->n = (*curr)->n;
	}
	else
	{
		(*grp)->next = create_maillon();
		(*grp)->next->n = (*curr)->n;
		(*grp) = (*grp)->next;
	}
}



group *remplir_ensemble(float *a, char name)
{
	group *grpA;
	lst *curr = NULL;
	lst *tt = NULL;
	int i = 0;

	grpA = (group *)malloc(sizeof(group));
	curr = create_maillon();
	while (i < 10)
	{
		curr->n = a[i];
		ft_alloc(&grpA->lst, &curr, &tt);
		i++;	
	}
	free(curr);
	grpA->lst = tt;
//	printf("LLLL %f lll\n",grpA->lst->n);
	grpA->name = name;
	return (grpA);
}

int		cardinal(lst *g)
{
	int card = 0;

	while (g != NULL)
	{
		card++;
		g = g->next;
	}
	return (card);
}
void	afficher_group(group *grp)
{
	int i = 0;
	printf("%c = {", grp->name);
	while (grp->lst != NULL)
	{
		printf("%.2f",grp->lst->n);
		if (i == grp->card - 1)
		{
			printf("}");
			printf("\ncard(%c) = %d\n", grp->name, grp->card);
		}
		else
			printf(", ");
		grp->lst = grp->lst->next;
		i++;
	}
}
int main()
{
	float a[10] = {-20, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float	b[12] = {-9, -8, 0, 10, 20 , 3, 40, 55, 60, 70, 80, 9};
	group *A;
	group	*B;

	A = remplir_ensemble(a, 'A');
	B = remplir_ensemble(b, 'B');
	A->card = cardinal(A->lst);
	B->card = cardinal(B->lst);
	afficher_group(A);
	afficher_group(B);
}
