/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:44:56 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 13:59:55 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	if (*lst == NULL || !del)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = temp -> next;
		del(temp -> content);
		free (temp);
	}
}
