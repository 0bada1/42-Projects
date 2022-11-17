/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:10:15 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/14 04:17:37 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pushing_to_b(t_node *stack)
{
	int	number_of_ints_pushed_per_chunk;
	int	chunk_num;

	if (!stack || !stack->a)
		return (stack);
	chunk_num = 0;
	number_of_ints_pushed_per_chunk = 0;
	while (stack->a != NULL || (check_if_sorted(stack->a) == FALSE && stack->))
	{
		if (number_of_ints_pushed_per_chunk >= stack->chunk_size)
		{
			number_of_ints_pushed_per_chunk = 0;
			chunk_num++;
		}
		if (stack->a->chunk_num > chunk_num)
		{
			while (stack->a->chunk_num != chunk_num)
				ra(stack);
		}
		if (stack->a->chunk_num == chunk_num)
		{
			pb(stack);
			number_of_ints_pushed_per_chunk++;
		}
	}
	return (stack);
}

t_node	*pushing_to_a(t_node *stack)
{
	int		ints_pushed;
	int		current_chunk;
	int		index;

	if (!stack || !stack->b)
		return (stack);
	current_chunk = 9;
	index = stack->number_of_ints - 1;
	ints_pushed = 0;
	while (stack->b != NULL)
	{
		if (ints_pushed == stack->chunk_size)
		{
			ints_pushed = 0;
			current_chunk--;
		}
		if (stack->b->index == index)
		{
			ints_pushed++;
			pa(stack);
			index--;
		}
		if (check_index_location(stack, stack->b, index) == 1)
		{
			while (stack->b->index != index)
			{
				rb(stack);
			}
		}
		if (check_index_location(stack, stack->b, index) == 2)
		{
			while (stack->b->index != index)
			{
				rrb(stack);
			}
		}
	}
	return (stack);
}

int	check_index_location(t_node *node, t_stack *stack, int index)
{
	int		chunk_num;
	int		counter;
	t_stack	*temp;

	if (!node || !stack)
		return (0);
	counter = 0;
	temp = stack;
	chunk_num = temp->chunk_num;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (1);
		counter++;
		if (counter > node->chunk_size || temp->chunk_num != chunk_num)
			return (2);
		temp = temp->next;
	}
	return (0);
}

int	check_chunk_half(t_node *stack)
{
	if (stack->a->chunk_num * stack->chunk_size + stack->chunk_size / 2 > stack->a->index)
		return (1);
	return (2);
}
