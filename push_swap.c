/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:29:25 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/16 14:56:58 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

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

t_list	*sorted(t_list **stack)//GHOSTFUNCTION
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

void	smaller_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) == 2)
		sorttwo(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 3)
		sortthree(&(*stack_a));
	else if(ft_lstsize((*stack_a)) == 4)
		sortfour(&(*stack_a), &(*stack_b));
	else if (ft_lstsize((*stack_a)) == 5)
		sortfive(&(*stack_a), &(*stack_b));
	exit(0);
}

void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	
}

int	main(int ac, char **av)
{
	int wc = ac - 1;
	if (wc == 0)
		exit(ft_printf("no numbers\n"));
	int i = 1;
	int nb = ft_atoi(av[i], NULL);
	t_list *stack_a = ft_lstnew(nb);
	t_list *stack_b = NULL;
	t_list *add_back;
	
	while(i < wc)
	{
		nb = ft_atoi(av[i + 1], &stack_a);
		add_back = ft_lstnew(nb);
		ft_lstadd_back(&stack_a, add_back);
		i++;
	}
	if (hasdouble(stack_a) == 1)
	{
		freeall(&stack_a);
		exit(ft_printf("has double\n"));
	}
	if (ft_lstsize(stack_a) <= 5)
		smaller_five(&stack_a, &stack_b);
	if (is_sorted(stack_a)!=0)
		return (printf("already sorted\n"));
	t_list *last_node;
	
	int len;
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
}
