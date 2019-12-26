#include "grps.h"

int	check_repete(lst *a, float x, int i)
{
	int j;

	j = i;
	while (a && j)
	{
		if (a->n == x)
			return (1);
		a = a->next;
		j--;
	}
	return (0);
}

group	*remplir_ensemble(float *a, int size, char name)
{
	group *grpA;
	lst *curr = NULL;
	lst *tt = NULL;
	int i = 0;

	grpA = (group *)malloc(sizeof(group));
	curr = create_maillon();
	while (i < size)
	{
		curr->n = a[i];
		if (i && (check_repete(tt, a[i], i) == 1))
			i++;
		else
		{
			ft_alloc(&grpA->lst, &curr, &tt);
			i++;	
		}
	}
	free(curr);
	grpA->lst = tt;
	grpA->name = name;
	return (grpA);
}

int		cardinal(lst *e)
{
	int card = 0;
	lst	*g = NULL;

	g = e;
	while (g != NULL)
	{
		card++;
		g = g->next;
	}
	return (card);
}

void	afficher_group(group *grp)
{
	int 	i = 0;
	lst		*l = NULL;
	if (grp->card == 0)
	{
		printf("L'ensemble %c est vide.\n", grp->name);
		return;
	}
	printf("%c = {", grp->name);
	l = grp->lst;
	while (l != NULL)
	{
		printf("%.2f",l->n);
		if (i == grp->card - 1)
		{
			printf("}");
			printf("\ncard(%c) = %d\n", grp->name, grp->card);
		}
		else
			printf(", ");
		l = l->next;
		i++;
	}
	printf("------------------------------\n");
}

int main()
{
	float	a[10] = {-20, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//	float	b[10] = {-20, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float	b[12] = {-9, -8, 0, 10, 0 , 3, 40, 55, 60, 70, 80, 9};
	group	*A;
	group	*B;

	A = remplir_ensemble(a, 10,'A');
	B = remplir_ensemble(b, 12,'B');
	A->card = cardinal(A->lst);
	B->card = cardinal(B->lst);
	afficher_group(A);
	afficher_group(B);
	trouver_intersection(A, B);
	trouver_union(A, B);
//	trouver_element(1, A);
	verifier_egalite(A, B);
}
