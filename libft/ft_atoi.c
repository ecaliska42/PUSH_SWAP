/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:31:50 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/20 15:50:47 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>
#include <string.h>

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

static void	error(t_list **stack, char *temp)
{
	free_my_nodes(&(*stack));
	free (temp);
	exit(write(1, "Error\n", 6));
}

int	calculate(const char *nptr, int neg, t_list **stack)
{
	long int	num;

	num = 0;
	while(*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			num = num * 10 + (*nptr - '0');
		else
			error(&(*stack), NULL);
		if (num > 2147483647 || (neg == -1 && num > 2147483648))
			error(&(*stack), NULL);
		nptr++;
	}
	return (num);
}

long int	ft_atoi(const char *nptr, t_list **stack)
{
	long int	num;
	int			neg;
	const char	*str;
	char		*temp;

	num = 0;
	neg = 1;
	str = nptr;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		neg *= -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		error(&(*stack), NULL);
	num = calculate(nptr, neg, stack);
	temp = ft_itoa(num);
	if (strcmp(str, temp) != 0)
		error(&(*stack), temp);
	free(temp);
	temp = NULL;
	return (num * neg);
}
