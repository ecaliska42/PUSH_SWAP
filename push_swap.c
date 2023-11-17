/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:29:25 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/17 19:09:22 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getindex(t_list *stack_a, t_list *sorted)
{
	t_list *temp = stack_a;
	int j = 0;
	while(sorted)
	{
		if (temp->content == sorted->content)
		{
			temp->content = j;
			j++;
			sorted = sorted->next;
			temp = stack_a;
		}
		else
			temp = temp->next;
	}
	temp = stack_a;
}

void printindex(t_list *head, char c) //THIS FUNCTION IS ONLY FOR TESTING AND NOT NEEDED
{
	int	nb;
	t_list *temp;

	temp = head;
	while(temp)
	{
		nb = temp->content;
		ft_printf("%c=|%d|\n", c, nb);
		temp = temp->next;
	}
	temp = head;
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

void	smaller_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) == 2)
		sorttwo(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 3)
		sortthree(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 4)
		sortfour(&(*stack_a), &(*stack_b));
	else if (ft_lstsize((*stack_a)) == 5)
		sortfive(&(*stack_a), &(*stack_b));
	freeall(&(*stack_a));
	exit(0);
}

void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	int		len;
	unsigned long long	raiser;
	raiser = 0;
	while (is_sorted(*stack_a) == 0)
	{
		len = ft_lstsize(*stack_a);
		while (len--)
		{
			if ((*stack_a)->content >> raiser & 1)
				ra(&(*stack_a));
			else
				pb(&(*stack_a), &(*stack_b));
			
		}
		while (*stack_b)
			pa(&(*stack_a), &(*stack_b));
		raiser++;
	}
}

int	containsneg(t_list *stack_a)
{
	while(stack_a)
	{
		if(stack_a->content < 0)
			return 1;
		stack_a = stack_a->next;
	}
	return 0;
}

void	error(int check, t_list **stack)
{
	if (check == 1)
		exit(ft_printf("no numbers\n"));
	else if (check == -1)
	{
		freeall(&(*stack));
		exit(ft_printf("has double\n"));
	}
}

t_list	*copy_list(t_list *stack)
{
	t_list *node;
	if (stack == NULL)
		return NULL;
	else
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return NULL;
		node->content = stack->content;
		node->next = copy_list(stack->next);
	}
	return node;
}

void	swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void	sorted(t_list **stack)
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

int	main(int ac, char **av)
{
	int		i;
	int		nb;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*add_back;
	t_list	*temp;

	error(ac, NULL);
	i = 1;
	nb = ft_atoi(av[i], NULL);
	stack_a = ft_lstnew(nb);
	stack_b = NULL;
	while (i < ac - 1)
	{
		nb = ft_atoi(av[i + 1], &stack_a);
		add_back = ft_lstnew(nb);
		if (!add_back)
			freeall(&stack_a);
		ft_lstadd_back(&stack_a, add_back);
		i++;
	}
	error(hasdouble(stack_a), &stack_a);
	if (ft_lstsize(stack_a) <= 5)
		smaller_five(&stack_a, &stack_b);
	temp = copy_list(stack_a);
	if (!temp)
	{
		freeall(&stack_a);
		return -1;
	}
	sorted(&temp);
	getindex(stack_a, temp);
	sorting_algorithm(&stack_a, &stack_b);
	if (is_sorted(stack_a) == 1)
		ft_printf("everything is sorted\n");
	freeall(&stack_a);
	free(temp);
	if (stack_b)
		free(stack_b);
}
