/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:06:56 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/14 04:15:47 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* algorithm
Sorted_stacks store all the numbers that are already sorted
*/
t_node	*algorithm(t_node *stack)
{
	// t_stack	**sorted_stacks = NULL;

	if (stack->number_of_ints <= 5)
	{
		stack = hardcode_sort(stack);
		return (stack);
	}
	get_all_info(stack);
	// check_if_sorted(stack->a);
	// ft_printf("Entering algorithm2\n");
	stack = algorithm2(stack);
	return (stack);
}

t_node	*hardcode_sort(t_node *stack)
{
	if (stack->number_of_ints == 2)
	{
		if (check_if_sorted(stack->a) == FALSE)
			sa(stack);
	}
	else if (stack->number_of_ints == 3)
	{
		sort3(stack);
	}
	return (stack);
}

t_node	*sort2(t_node *stack)
{
	sa(stack);
	return (stack);
}

t_node	*sort3(t_node *stack)
{
	if (check_if_sorted(stack->a) == FALSE)
		{
			while (check_if_sorted(stack->a) == FALSE)
			{
				stack->largest_num = find_largest(stack);
				stack->smallest_num = find_smallest(stack);
				if (stack->a->num == stack->largest_num && stack->a->next->num == stack->smallest_num)
					ra(stack);
				else if (((stack->a->num != stack->smallest_num ||stack->a->num != stack->largest_num) && stack->a->next->num == stack->smallest_num) || (stack->a->num == stack->largest_num && stack->a->next->num != stack->smallest_num))
				{
					sa(stack);
					if (check_if_sorted(stack->a) == FALSE)
						rra(stack);
				}
				else if ((stack->a->num == stack->smallest_num && stack->a->next->num == stack->largest_num) || ((stack->a->num != stack->smallest_num || stack->a->num != stack->largest_num) && stack->a->next->num == stack->largest_num))
				{
					rra(stack);
					if (check_if_sorted(stack->a) == FALSE)
						sa(stack);
				}
			}
		}
	return (stack);
}

/* Algorithm2
- Get an already sorted list for comparison
- Loop through the list and pb all ints less than a number in chunk
-
*/
t_node	*algorithm2(t_node *stack)
{
	if (!stack || !stack->a)
		return (stack);
	stack = pushing_to_b(stack);
	stack = pushing_to_a(stack);
	return (stack);
}
