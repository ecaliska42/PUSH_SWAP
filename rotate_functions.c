/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:55:31 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 17:47:31 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"




void	ra(t_list **stack_a)
{
	t_list	*node;
	t_list	*temp;

	if (!(*stack_a) || ft_lstsize((*stack_a)) < 2)
		return ;
	node = ft_lstnew((*stack_a)->content);
	if (!node)
		return ;
	//temp = (*stack_a)->next;
	//delone(&(*stack_a));
	//stack_a = &temp;
	ft_list_remove_if(&(*stack_a), node);
	ft_lstadd_back(&(*stack_a), node);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*node;

	if (!(*stack_b) || ft_lstsize((*stack_b)) < 2)
		return ;
	node = ft_lstnew((*stack_b)->content);
	if (!node)
		return ;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(&(*stack_b), node);
	write(1, "rb\n", 3);
}

void	rota(t_list **stack_a)
{
	t_list	*node;

	if (!(*stack_a) || ft_lstsize((*stack_a)) < 2)
		return ;
	node = ft_lstnew((*stack_a)->content);
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(&(*stack_a), node);
}

void	rotb(t_list **stack_b)
{
	t_list	*node;

	if (!(*stack_b) || ft_lstsize((*stack_b)) < 2)
		return ;
	node = ft_lstnew((*stack_b)->content);
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(&(*stack_b), node);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rota(&(*stack_a));
	rotb(&(*stack_b));
	write(1, "rr\n", 3);
}
