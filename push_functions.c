/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:57 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/17 19:23:02 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_add;
	t_list	*temp_b;

	if (!(*stack_b))
		return ;
	node_to_add = ft_lstnew((*stack_b)->content);
	if (!node_to_add)
		exit (-1);
	ft_lstadd_front(stack_a, node_to_add);
	temp_b = *stack_b;
	*stack_b = temp_b->next;
	free (temp_b);
	//free (node_to_add);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_add;
	t_list	*temp_a;

	if (!(*stack_a))
		return ;
	node_to_add = ft_lstnew((*stack_a)->content);
	if (!node_to_add)
		exit (-1);
	ft_lstadd_front(stack_b, node_to_add);
	temp_a = *stack_a;
	*stack_a = temp_a->next;
	free (temp_a);
	//free (node_to_add);
	write(1, "pb\n", 3);
}
