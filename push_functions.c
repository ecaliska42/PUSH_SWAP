/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:57 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/13 16:51:47 by ecaliska         ###   ########.fr       */
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
	ft_lstadd_front(stack_a, node_to_add);
	temp_b = (*stack_b)->next;
	free (*stack_b);
	*stack_b = temp_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_add;
	t_list	*temp_a;

	if (!(*stack_a))
		return ;
	node_to_add = ft_lstnew((*stack_a)->content);
	ft_lstadd_front(stack_b, node_to_add);
	temp_a = (*stack_a)->next;
	free (*stack_a);
	*stack_a = temp_a;
	write(1, "pb\n", 3);
}
