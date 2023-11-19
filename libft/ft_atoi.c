/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:31:50 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/19 20:22:36 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_my_nodes(t_list **stack)
{
	t_list	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free (temp);
	}
}

static void	error(t_list **stack)
{
	free_my_nodes(&(*stack));
	exit(write(1, "Error\n", 6));
}

long int	ft_atoi(const char *nptr, t_list **stack)
{
	long int	num;
	int			neg;

	num = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		neg *= -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		error(&(*stack));
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			num = num * 10 + (*nptr - '0');
		else
			error(&(*stack));
		if (num > 2147483647 || (neg == -1 && num > 2147483648))
			error(&(*stack));
		nptr++;
	}
	return (num * neg);
}
