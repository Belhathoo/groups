#include "grps.h"

int	check_repete(lst *a, float x, int i)
{
	int j;

	j = i;
	while (a && j >= 0)
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
		if ((check_repete(tt, a[i], i) == 1))
			i++;
		else
		{
			printf("LMLM %.2f\n", curr->n);
			ft_alloc(&grpA->lst, &curr, &tt);
			i++;	
		}
	}
	free(curr);
	grpA->lst = tt;
	grpA->name = name;
	grpA->next = NULL;
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
		printf("L'ensemble '%c' est vide.\n", grp->name);
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

int	menu(void)
{
	char choix = '9';

	while((choix != 'x' && choix != 'X' && choix != 'm') && (choix < '1' || choix > '7'))
	{
		printf("\n******************** MENU ********************\n\n");
		printf(" 1- Afficher Les Ensembles Disponibles:\n");
		printf(" 2- Creer Un Ensemble:\n");
		printf(" 3- Calculer L'Intersection De Deux Ensembles:\n");
		printf(" 4- Calculer L'Union De Deux Ensembles:\n");
		printf(" 5- Difference & Difference Symetrique:\n");
		printf(" 6- Tester L'appartenance d'Un Element à Un Ensemble\n");
		printf(" 7- Comparer Deux Ensemblles:\n"); /* = C Disjoint*/

		printf("    Appuyer sur 'X'/'x' pour quitter.\n\tVotre choix: ");
		scanf("%c", &choix);
		printf("\n");
		if ((choix != 'x' && choix != 'X' && choix == 'm') && (choix < '1' || choix > '7'))
			printf("\n!!CHOIX INVALIDE!!");
	}
	return (choix);
}


group	*trouver_dernier_maillon(group *a)
{
	group *tmp;
	group *tt;
	tt = a;
	while(a->next)
	{
		a = a->next;
	}
	tmp = a;
	a = tt;
	return (tmp);
}

int main()
{
	char	choix = 'm';

	group	*A;

	A = affect_premiers_groups();	
	//choix = menu();
	while(1)
	{
		if (choix == '1')
			afficher_tout(&A);
		if (choix == '2')
			creer_ensemble(&A);
		if (choix == 'x')
			return (0);
		if (choix == 'X')
			return (0);
	//	if (choix == 'm')
		else
			choix = menu();
	//	choix = 'm';
	}

//	trouver_intersection(A, A->next);
//	trouver_union(A, A->next);
	
//	afficher_group(A->next->next);
	//	trouver_element(1, A);
//	verifier_egalite(A, A->next);
}
