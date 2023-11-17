/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:29:25 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/17 16:59:09 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmaxlen(t_list *stack_a)
{
	t_list	*temp;
	int		max;
	int		len;
	//int		absolute_value;

	len = 0;
	temp = stack_a;
	max = temp ->content;
	while (temp)
	{
		// if (temp->content < 0)
		// 	-temp->content;
		// else
		// 	temp->content;
		// absolute_value = temp->content;
		int absolute_value = temp->content < 0 ? -temp->content : temp->content;
		if (max < absolute_value)
			max = absolute_value;
		temp = temp->next;
	}
	while (max)
	{
		max /= 2;
		len++;
	}
	return (len);
}

void	getindex(t_list *stack_a, t_list *sorted)
{
	t_list *temp = stack_a;
	int j = 0;
	while(sorted)
	{
		if (temp->content == sorted->content)
		{
			temp->content = j;
			j++;
			sorted = sorted->next;
			temp = stack_a;
		}
		else
			temp = temp->next;
	}
}

void printindex(t_list *head, char c) //THIS FUNCTION IS ONLY FOR TESTING AND NOT NEEDED
{
	int	nb;
	t_list *temp;

	temp = head;
	while(temp)
	{
		nb = temp->content;
		ft_printf("%c=|%d|\n", c, nb);
		temp = temp->next;
	}
	temp = head;
}

void printstack(t_list *head, char c) //THIS FUNCTION IS ONLY FOR TESTING AND NOT NEEDED
{
	int	nb;
	while(head)
	{
		nb = head->content;
		ft_printf("%c=|%d|\n", c, nb);
		head = head->next;
	}
}

void	smaller_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) == 2)
		sorttwo(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 3)
		sortthree(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 4)
		sortfour(&(*stack_a), &(*stack_b));
	else if (ft_lstsize((*stack_a)) == 5)
		sortfive(&(*stack_a), &(*stack_b));
	exit(0);
}

void	sorting_algorithm_pos(t_list **stack_a, t_list **stack_b)
{
	int		len;
	unsigned long long	raiser;
	int		maxlen;
	int		neg;
	int		cntrforloop;
	//cntrforloop++ <= maxlen
	//is_sorted(*stack_a) == 0
	raiser = 0;
	cntrforloop = 0;
	maxlen = getmaxlen(*stack_a);
	while (is_sorted(*stack_a) == 0)
	{
		len = ft_lstsize(*stack_a);
		while (len--)
		{
			//printf("bit = %d\n", (*stack_a)->index >> raiser);
			// printstack(*stack_a,'a');
			// printstack(*stack_b,'b');
			printindex(*stack_a, 'i');
			if ((*stack_a)->content >> raiser & 1)
				ra(&(*stack_a));
			else
				pb(&(*stack_a), &(*stack_b));
			
		}
		while (*stack_b)
			pa(&(*stack_a), &(*stack_b));
		raiser++;
	}
}


int	containsneg(t_list *stack_a)
{
	while(stack_a)
	{
		if(stack_a->content < 0)
			return 1;
		stack_a = stack_a->next;
	}
	return 0;
}

// void	sorting_algorithm_neg(t_list **stack_a, t_list **stack_b)
// {
// 	int		len;
// 	int		shifter;
// 	shifter = 0;
// 	while (shifter <= 31)
// 	{
// 		len = ft_lstsize(*stack_a);
// 		while (len--)
// 		{
// 			if (((*stack_a)->content >> shifter & 1) == 0)
// 				pb(&(*stack_a), &(*stack_b));
// 			else
// 				ra(&(*stack_a));
// 		}
// 		while (*stack_b)
// 			pa(&(*stack_a), &(*stack_b));
// 		shifter++;
// 	}
// }


void	error(int check, t_list **stack)
{
	if (check == 1)
		exit(ft_printf("no numbers\n"));
	else if (check == -1)
	{
		freeall(&(*stack));
		exit(ft_printf("has double\n"));
	}
}


t_list	*copy_list(t_list *stack)
{
	t_list *node;
	if (stack == NULL)
		return NULL;
	else
	{
		node = malloc(sizeof(t_list));
		node->content = stack->content;
		node->next = copy_list(stack->next);
	}
	return node;
}

void	swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

t_list	*sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while(temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			swap(&temp->content, &temp->next->content);
			temp = *stack;
		}
		else
			temp = temp->next;
	}
	temp = *stack;
	return temp;
}

int	getlast(t_list *stack_a)
{
	t_list *temp = stack_a;
	while(temp->next)
	{
		temp = temp->next;
	}
	return temp->content;
}


// void	swap_neg(t_list **stack_a, t_list **stack_b)
// {
// 	while(getlast(*stack_a) < 0)
// 	{
// 		rra(&(*stack_a));
// 		pb(&(*stack_a), &(*stack_b));
// 	}
// 	while((*stack_b))
// 	{
// 		rrb(&(*stack_b));
// 		pa(&(*stack_a), &(*stack_b));	
// 	}
// }



int	main(int ac, char **av)
{
	int		i;
	int		nb;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*add_back;
	t_list	*temp;

	error(ac, NULL);
	i = 1;
	nb = ft_atoi(av[i], NULL);
	stack_a = ft_lstnew(nb);
	stack_b = NULL;
	while (i < ac - 1)
	{
		nb = ft_atoi(av[i + 1], &stack_a);
		add_back = ft_lstnew(nb);
		ft_lstadd_back(&stack_a, add_back);
		i++;
	}
	error(hasdouble(stack_a), &stack_a);
	if (ft_lstsize(stack_a) <= 5)
		smaller_five(&stack_a, &stack_b);
	temp = copy_list(stack_a);
	t_list	*sortedstack = sorted(&temp);
	// if (containsneg(stack_a) == 1)
	// {
	// 	sorting_algorithm_neg(&stack_a, &stack_b);
	// 	swap_neg(&stack_a, &stack_b);
	// }
	// else
	getindex(stack_a, temp);
	sorting_algorithm_pos(&stack_a, &stack_b);
	//printstack(stack_a,'a');
	// printf("\n\n\n\n");
	// printstack(temp,'t');
	// printf("\n\n\n\n");
	//printindex(stack_a, 'i');
	//printindex(temp, 's');
	// ft_printf("\n----------------\n");
	// printstack(stack_b,'b');
	if (is_sorted(stack_a) == 1)
		ft_printf("everything is sorted\n");
	//freeall(&stack_a);
}
