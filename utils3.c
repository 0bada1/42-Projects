/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:29:36 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/12 05:37:12 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_all_info(t_node *stack)
{	
	stack->largest_num = find_largest(stack);
	stack->smallest_num = find_smallest(stack);
	return (stack);
}

// THE 2 FUNCTIONS BELOW ARE NOT PROTECTED!!
int	find_largest(t_node *stack)
{
	t_stack	*temp;
	int		largest_num;

	temp = stack->a;
	largest_num = temp->num;
	while (temp != NULL)
	{
		// ft_printf("stack->a = %i\nlargest num = %i\ntemp->num = %i\n", stack->a->num, largest_num, temp->num);
		// check_list(stack->a);
		// ft_printf("temp->num = %i\n", temp->num);
		if (largest_num < temp->num)
			largest_num = temp->num;
		temp = temp->next;
	}
	// ft_printf("Largest num = %i\n", largest_num);
	return (largest_num);
}

int	find_smallest(t_node *stack)
{
	t_stack	*temp;
	int		smallest_num;

	temp = stack->a;
	smallest_num = temp->num;
	while (temp != NULL)
	{
		// ft_printf("stack->a = %i\nlargest num = %i\ntemp->num = %i\n", stack->a->num, smallest_num, temp->num);
		// check_list(stack->a);
		// ft_printf("temp->num = %i\n", temp->num);
		if (smallest_num > temp->num)
			smallest_num = temp->num;
		temp = temp->next;
	}
	// ft_printf("Smallest num = %i\n", smallest_num);
	return (smallest_num);
}