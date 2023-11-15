/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:29:25 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/15 22:05:40 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	hasdouble(t_list *head)
{
	int		tmpnbr;
	t_list	*temp;

	while (head)
	{
		temp = head;
		tmpnbr = head->content;
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (tmpnbr == temp->content)
				return (1);
		}
		head = head->next;
	}
	return (0);
}

void	freeall(t_list **lst)
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = temp->next;
		free (temp);
	}
}

int	is_sorted(t_list *stack)
{
	int	temp;
	
	temp = stack->content;
	while(stack)
	{
		if (temp > stack->content)
			return (0);
		temp = stack->content;
		stack = stack->next;
	}
	return (1);
}

void	sortthree(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted((*stack_a)) == 1)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa((*stack_a));
	else if (a > b && b > c && a > c)
	{
		sa((*stack_a));
		rra(&(*stack_a));
	}
	else if (a > b && b < c && a > c)
		ra(&(*stack_a));
	else if (a < b && b > c && a < c)
	{
		sa((*stack_a));
		ra(&(*stack_a));
	}
	else if (a < b && b > c && a > c)
		rra(&(*stack_a));
}

void	sorttwo(t_list **stack_b)
{
	int	a;
	int	b;
	
	if (is_sorted((*stack_b)) == 1)
		return ;
	a = (*stack_b)->content;
	b = (*stack_b)->next->content;
	if(a > b)
		ra(&(*stack_b));
}

void printstack(t_list *head, char c) //THIS FUNCTION IS ONLY FOR TESTING AND NOT NEEDED
{
	int	nb;
	while(head)
	{
		nb = head->content;
		ft_printf("%c=|%d|\n", c, nb);
		head = head->next;
	}
}

int	getpos(t_list *stack, int nbr)
{
	int i = 0;
	
	while(stack)
	{
		if (stack->content == nbr)
			return i;
		i++;
		stack = stack->next;
	}
	return i;
}

void	pushmin(t_list **stack_a, t_list **stack_b)
{
	int	min;
	t_list *temp;
	int	pos;

	temp = *stack_a;
	min = temp->content;
	while(temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	pos = getpos(*stack_a, min);
	while(min != (*stack_a)->content)
	{
		if (pos <= (ft_lstsize(*stack_a) / 2))
			ra(&(*stack_a));
		else
			rra(&(*stack_a));
	}
	pb(&(*stack_a), &(*stack_b));
}

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	pushmin(&(*stack_a), &(*stack_b));
	sortthree(&(*stack_a));
	pa(&(*stack_a), &(*stack_b));
}

void	sortfive(t_list **stack_a, t_list **stack_b)
{
	pushmin(&(*stack_a), &(*stack_b));
	pushmin(&(*stack_a), &(*stack_b));
	sortthree(&(*stack_a));
	pa(&(*stack_a), &(*stack_b));
	pa(&(*stack_a), &(*stack_b));
}

void	swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

t_list	*sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while(temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			swap(&temp->content, &temp->next->content);
			temp = *stack;
		}
		else
			temp = temp->next;
	}
	temp = *stack;
	return temp;
}

int	getmedi(t_list *stack_a)
{
	t_list *temp = stack_a;
	int med = ft_lstsize(stack_a) / 2;
	while(med--)
	{
		temp = temp->next;
	}
	return temp->content;
}

int	getlast(t_list *stack_a)
{
	t_list *temp = stack_a;
	while(temp->next)
	{
		temp = temp->next;
	}
	return temp->content;
}


int getmaxlen(t_list **stack_a)
{
	t_list *temp;
	int max;
	int len;

	len = 0;
	temp = *stack_a;
	max = temp ->content;
	while (temp)
	{
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
	}
	while(max)
	{
		max /= 2;
		len++;
	}
	return len;
}

int	main(int ac, char **av)
{
	int wc = ac - 1;
	if (wc == 0)
		exit(ft_printf("no numbers\n"));
	int i = 1;
	int nb = ft_atoi(av[i]);
	t_list *stack_a = ft_lstnew(nb);
	t_list *stack_b = NULL;
	t_list *add_back;
	t_list	*cheatsort;
	
	while(i < wc)
	{
		nb = ft_atoi(av[i + 1]);
		add_back = ft_lstnew(nb);
		ft_lstadd_back(&stack_a, add_back);
		i++;
	}
	if (hasdouble(stack_a) == 1)
	{
		freeall(&stack_a);
		exit(ft_printf("has double\n"));
	}
	if (ft_lstsize(stack_a) == 2)
		sorttwo(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sortthree(&stack_a);
	else if(ft_lstsize(stack_a) == 4)
		sortfour(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sortfive(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) <= 5)
		return 0;
	int len;
	if (is_sorted(stack_a)!=0)
		return (printf("already sorted\n"));
	t_list *last_node;
	
	int countfrlp = 1;
	int lengthofnbr = getmaxlen(&stack_a) + 1;
	int raiser = 1;
	while(countfrlp <= lengthofnbr)
	{
		len = ft_lstsize(stack_a);
		while (len--)
		{
			if (stack_a->content / raiser % 2 == 0)
				pb(&stack_a, &stack_b);
			else
				ra(&stack_a);
		}
		while (stack_b)
			pa(&stack_a, &stack_b);
		countfrlp++;
		raiser *= 2;
	}
	/*
		THIS BLOCK IS JUST TO PRINT THE STACKS
	*/
	// printstack(stack_a,'a');
	// ft_printf("\n----------------\n");
	// printstack(stack_b,'b');
}




/*
• 	You have 2 stacks named a and b.
•	At the beginning:
◦ 	The stack a contains a random amount of negative and/or positive numbers
		which cannot be duplicated.
◦ 	The stack b is empty.
• 	The goal is to sort in ascending order numbers into stack a. To do so you have the
		following operations at your disposal:
//allowed : read, write, malloc, free, exit

DONE:
	- has double function
	- check if it is sorted function
	- sorting functions
	- sort 3 integers
	- 

TO-DO:
	- get rid of leaks
	- finish function
	- 

*/