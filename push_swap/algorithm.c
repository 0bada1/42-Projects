/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:06:56 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/31 13:37:32 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* algorithm
Sorted_stacks store all the numbers that are already sorted
*/
t_node	*algorithm(t_node *stack)
{
	// t_stack	**sorted_stacks = NULL;

	// if (stack->number_of_ints <= 4)
	// stack = hardcode_sort(stack);
	get_all_info(stack);
	check_if_sorted(stack->a);
	ft_printf("Entering algorithm1\n");
	stack = algorithm1(stack);
	return (stack);
}

// Can be optimized by seeing if ra or rra is better
t_node	*algorithm1(t_node *stack)
{
	int		i = 0;
	int		max;

	if (!stack)
		return (stack);
	while (stack->a != NULL)
	{
		// check_list(stack->a);
		max = find_smallest(stack);
		if (stack->a->num == max)
			pb(stack);
		else
			ra(stack);
		i++;
	}
	while (stack->b != NULL)
	{
		ft_printf("stack->b->num = %i\n", stack->b->num);
		pa(stack);
		i++;
	}
	ft_printf("i = %i\n", i);
	return (stack);
}

t_node	*hardcode_sort(t_node *stack)
{
	int	i = 0;

	if (stack->number_of_ints == 2)
	{
		if (check_if_sorted(stack->a) == 1)
			sa(stack);
	}
	else if (stack->number_of_ints == 3)
	{
		if (check_if_sorted(stack->a) == 1)
		{
			while (check_if_sorted(stack->a) == 1)
			{
				stack->largest_num = find_largest(stack);
				if (stack->a->num == stack->largest_num || stack->a->next->num == stack->largest_num)
					rra(stack);
				else
					sa(stack);
				i++;
			}
		}
	}
	ft_printf("i = %i\n", i);
	check_list(stack->a);
	return (stack);
}

/* Algorithm2 uses bubble sort..


*/
// t_node	*algorithm2(t_node *stack)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack || !stack->a)
// 		return (stack);
// 	while (stack->a != NULL)
// 	{

// 	}
// }