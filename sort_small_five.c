/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:47:34 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/16 14:53:31 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorttwo(t_list **stack_b) //sorts two numbers only
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

void	sortthree(t_list **stack_a) //sorts three numbers only
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
