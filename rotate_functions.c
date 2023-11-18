/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:55:31 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 20:53:18 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static void	list_remove_if(t_list **head, t_list *node)
{
	t_list	*cur;
	t_list	*prev;

	if (head == NULL || *head == NULL)
		return ;
	cur = *head;
	prev = NULL;
	while (cur != NULL)
	{
		if (cur->content == node->content)
		{
			if (prev == NULL)
				*head = cur->next;
			else
				prev->next = cur->next;
			free(cur);
			cur = NULL;
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	ra(t_list **stack_a, int print)
{
	t_list	*node;

	if (!(*stack_a) || ft_lstsize((*stack_a)) < 2)
		return ;
	node = ft_lstnew((*stack_a)->content);
	if (!node)
		return ;
	list_remove_if(&(*stack_a), node);
	ft_lstadd_back(&(*stack_a), node);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int print)
{
	t_list	*node;

	if (!(*stack_b) || ft_lstsize((*stack_b)) < 2)
		return ;
	node = ft_lstnew((*stack_b)->content);
	if (!node)
		return ;
	list_remove_if(&(*stack_b), node);
	ft_lstadd_back(&(*stack_b), node);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(&(*stack_a), -1);
	rb(&(*stack_b), -1);
	write(1, "rr\n", 3);
}
