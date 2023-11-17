/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:02 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/17 17:45:14 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	temp;

	temp = stack->content;
	while (stack)
	{
		if (temp > stack->content)
			return (0);
		temp = stack->content;
		stack = stack->next;
	}
	return (1);
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
	//free(lst);
	exit (-1);
}

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
				return (-1);
		}
		head = head->next;
	}
	return (0);
}

int	getpos(t_list *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == nbr)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
