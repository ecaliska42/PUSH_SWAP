/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:31:50 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/16 14:43:06 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	return (i);
}

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

int	ft_atoi(const char *nptr, t_list **stack)
{
	int	num;
	int	neg;
	int	pos;

	num = 0;
	neg = 1;
	pos = number(nptr);
	if (nptr[pos] == '-')
	{
		neg *= -1;
		pos++;
	}
	if (!(nptr[pos] >= '0' && nptr[pos] <= '9'))
		exit(write(1, "Error\n", 6));
	while (nptr[pos])
	{
		if (nptr[pos] >= '0' && nptr[pos] <= '9')
			num = num * 10 + (nptr[pos++] - '0');
		else
		{
			free_my_nodes(&(*stack));
			exit(write(1, "Error\n", 6));
		}
	}
	return (num * neg);
}
