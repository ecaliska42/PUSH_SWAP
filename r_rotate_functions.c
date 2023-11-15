/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:56:09 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/13 16:51:11 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	add = ft_lstnew(node);
	temp->next = NULL;
	ft_lstadd_front(&(*stack_a), add);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	add = ft_lstnew(node);
	temp->next = NULL;
	ft_lstadd_front(&(*stack_b), add);
	write(1, "rra\n", 4);
}

void	revra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	add = ft_lstnew(node);
	temp->next = NULL;
	ft_lstadd_front(&(*stack_a), add);
}

void	revrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	add = ft_lstnew(node);
	temp->next = NULL;
	ft_lstadd_front(&(*stack_b), add);
}


void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(&(*stack_a));
	rrb(&(*stack_b));
	write(1, "rrr\n", 4);
}
