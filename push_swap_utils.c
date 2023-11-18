/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:14:02 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 19:55:47 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	temp;

	temp = stack->content;
	while (stack)
	{
		if (temp > stack->content)
			return (0);
		temp = stack->content;
		stack = stack->next;
	}
	return (1);
}

void	freeall(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = temp->next;
		free (temp);
	}
}

int	hasdouble(t_list *head)
{
	int		tmpnbr;
	t_list	*temp;

	while (head)
	{
		temp = head;
		tmpnbr = head->content;
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (tmpnbr == temp->content)
				return (-1);
		}
		head = head->next;
	}
	return (0);
}

int	getpos(t_list *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == nbr)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

/*void list_remove_if(t_list **head, t_list *node)
{
	if (head == NULL || *head == NULL)
		return ;

	t_list *cur = *head;

	if (cur->content == node->content)
	{
		*head = cur->next;
		free(cur);
		cur = NULL;
		list_remove_if(head, node);
	}
	cur = *head;
	list_remove_if(&cur->next, node);
}*/

void list_remove_if(t_list **head, t_list *node)
{
   if (head == NULL || *head == NULL)
       return;

   t_list *cur = *head;
   t_list *prev = NULL;

   while (cur != NULL)
   {
       if (cur->content == node->content)
       {
           if (prev == NULL)
               *head = cur->next;
           else
               prev->next = cur->next;

           free(cur);
           cur = NULL;
           break;
       }

       prev = cur;
       cur = cur->next;
   }
}
