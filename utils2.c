/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:21:00 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/24 13:21:00 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initializing variables
- Constant is to find an appropriate chunk size
to work with based on the number of ints available
*/
void    initialize_variables_and_space(t_node *nums)
{
	nums->num_of_steps = 0;
	return ;
}

t_stack	*copy_list(t_stack *list)
{
	t_stack	*head;
	t_stack	*list2;

	ft_printf("Entered copy_list function\n");
	list2 = list;
	head = list2;
	while (list->next != NULL)
	{
		ft_printf("list->num = %i\n", list->num);
		list2->num = list->num;
		list = list->next;
		list2 = list2->next;
	}
	list2 = head;
	ft_printf("list->num = %i\n", list2->num);
	ft_printf("Finsihed copy_list function\n");
	return (list2);
}

void	check_list(t_stack *list)
{
	t_stack	*temp;

	if (!list)
	{
		return ;
	}
	ft_printf("starting function \"check_list\"\n");
	temp = list;
	while (temp != NULL)
	{
		ft_printf("list->num = %i && has index %i && temp->chunk_num = %i\n", temp->num, temp->index, temp->chunk_num);
		temp = temp->next;
	}
	if (temp != NULL)
		ft_printf("list->num = %i && has index %i && temp->chunk_num = %i\n\n", temp->num, temp->index, temp->chunk_num);
}

int	check_if_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
	{
		return (FALSE);
	}
	temp = stack;
	while (temp && temp->next)
	{
		if (temp->num > temp->next->num)
		{
			return (FALSE);
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	size_of_stack(t_stack *stack)
{
	t_stack	*temp;
	int	i;

	temp = stack;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	ft_printf("i = %i\n", i);
	return (i);
}

// Used for function copy_list_and_sort
// int	get_next_num(t_node *stack, int current_num)
// {
// 	int		num;
// 	t_stack	*temp;

// 	num = current_num;
// 	temp = stack->a;
// 	while (temp->next != NULL)
// 	{
// 		if (temp->num > current_num)
// 		{
// 			num = temp->num;
// 			if (current_num < num)
// 			{
// 				current_num = temp->num;
// 			}
// 		}
// 		temp = temp->next;
// 	}
// 	return (current_num);
// }

// t_stack	*return_list(t_stack *stack, int current_num)
// {
// 	t_stack	*temp;
// 	t_stack	*temp2;
// 	t_stack	*stack2;

// 	temp = stack;
// 	stack2 = malloc(sizeof(t_stack));
// 	temp2 = stack2;
// 	while (temp->next != NULL)
// 	{
// 		if (temp->num > current_num)
// 		{
// 			temp2->num = temp->num;
// 			temp2->next = malloc(sizeof(t_stack));
// 			temp2 = temp2->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (stack2);
// }
