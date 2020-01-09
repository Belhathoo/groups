
# include "grps.h"

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

group	*trouver_intersection(group *A, group *B)
{
	group	*I;

	lst		*curr = NULL;
	lst		*tt = NULL;
    lst   	*a;
    lst   	*b;

    a = A->lst;    
	I = (group *)malloc(sizeof(group));
    curr = create_maillon();
	while (a)
	{
        b = B->lst;
		while (b)
		{
			if (a->n == b->n)
			{
				curr->n = b->n;
				ft_alloc(&I->lst, &curr, &tt);
            }
            b = b->next;
        }
        a = a->next;
	}
	free(curr);
    I->lst = tt;
	I->name = 'I';
	I->card = cardinal(I->lst);
	return (I);
}

group	*trouver_union(group *A, group *B)
{
	group	*U;

	lst		*curr = NULL;
	lst		*tt = NULL;

    lst   *a;
    lst   *b;
	int		i = 0;

    a = A->lst;
	b = B->lst;
	U = (group *)malloc(sizeof(group));
	curr = create_maillon();
	while (a)
	{
		curr->n = a->n;
		ft_alloc(&U->lst, &curr, &tt);
		a = a->next;	
	}
	while (b)
	{
		curr->n = b->n;
		if ((check_repete(tt, curr->n, i) == 1))
		{
			i++;
			b = b->next;
		}
		else
		{
			ft_alloc(&U->lst, &curr, &tt);
			b = b->next;
			i++;
		}
	}
	free(curr);
    U->lst = tt;
	U->name = 'U';
	U->card = cardinal(U->lst);
	return (U);	
}

void trouver_element(float x, group *E)
{
	lst	*l;
	l = E->lst;
	while(l)
	{
		if (l->n == x)
		{
			printf("L'element %.2f appartient à l'ensemble %c\n", x, E->name);
			return ;
		}
		l = l->next;
	}
	printf("L'element %.2f n'appartient pas à l'ensemble %c\n", x, E->name);
}

int		verifier_inclusion(group *A, group *B)
{
	lst	*a;
	lst	*b;
	int check = 2;

	a = A->lst;
	b = B->lst;
	if (A->card == 0)
	{
		check = 1;
		return (check);
	}
	if (B->card == 0)
	{
		check = 1;
		return (check);
	}
	while (a)
	{
		while (b && check)
		{
			if (a->n == b->n)
			{
				b = b->next;
				check = 1;
			}
			else
			{
				check = 0;
				b = b->next;
			}
		}
		a = a->next;
	}
	return (check);
}

int		verifier_egalite(group *A, group *B)
{
	int check;
	
	check = verifier_inclusion(A, B);
	if (check == 1)
	{
		if (A->card == B->card)
			printf("%c = %c\n", A->name, B->name);
		else if(A->card < B->card)
			printf("%c c %c\n", A->name, B->name);
		else
			printf("%c c %c\n", B->name, A->name);		
		check = 1;
	}
	else
	{
		if (trouver_intersection(A, B)->card == 0)
			printf("%c et %c sont Disjoints!\n",A->name, B->name);
		else
			printf("%c est different du %c\n",A->name, B->name);
		return (0);
	}
	return (1);
}