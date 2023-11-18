/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:06:19 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 20:41:34 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **head);
void	rrb(t_list **head);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sorttwo(t_list **stack_b);
void	sortthree(t_list **stack_a);
int		is_sorted(t_list *stack);
void	freeall(t_list **lst);
void	sortfour(t_list **stack_a, t_list **stack_b);
void	sortfive(t_list **stack_a, t_list **stack_b);
int		hasdouble(t_list *head);
void	pushmin(t_list **stack_a, t_list **stack_b);
int		getpos(t_list *stack, int nbr);
void	swap(int *a, int *b);
int		getlast(t_list *stack_a);
void	printstack(t_list *head, char c); //THIS FUNCTION IS ONLY FOR TESTING

#endif