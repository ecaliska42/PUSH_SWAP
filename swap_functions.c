/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:30 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/13 18:50:00 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	sa(t_list *head)
{
	int	node;

	if (ft_lstsize(head) < 2)
		return ;
	node = head->next->content;
	head->next->content = head->content;
	head->content = node;
	write(1, "sa\n", 3);
}

void	sb(t_list *head)
{
	int	node;

	if (ft_lstsize(head) < 2)
		return ;
	node = head->next->content;
	head->next->content = head->content;
	head->content = node;
	write(1, "sb\n", 3);
}

void	swpa(t_list *head)
{
	int	node;

	if (ft_lstsize(head) < 2)
		return ;
	node = head->next->content;
	head->next->content = head->content;
	head->content = node;
}

void	swpb(t_list *head)
{
	int	node;

	if (ft_lstsize(head) < 2)
		return ;
	node = head->next->content;
	head->next->content = head->content;
	head->content = node;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swpa(stack_a);
	swpb(stack_b);
	write(1, "ss\n", 3);
}
