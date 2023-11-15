/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:44:56 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/08 20:18:29 by ecaliska         ###   ########.fr       */
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
