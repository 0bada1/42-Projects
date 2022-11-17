/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:27 by ooutabac          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:27 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap stack a has 4 steps
- Step 1 : Temp points to node 1
- Step 2 : Head points to node 2
- Step 3 : Node 1 points to node 3
- Step 4 : Node 2 points to node 1
*/
t_node	*sa(t_node *stack)
{
	t_stack	*temp;

	if (!stack || !stack->a || !stack->a->next)
		return (stack);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->a->next;
	stack->a->next = temp;
	stack->num_of_steps += 1;
	ft_printf("sa\n");
	return (stack);
}

t_node	*sb(t_node *stack)
{
	t_stack	*temp;

	if (!stack || !stack->b || !stack->b->next)
		return (stack);
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->b->next;
	stack->b->next = temp;
	stack->num_of_steps += 1;
	ft_printf("sb\n");
	return (stack);
}

// Edit this function to manually do sa and sb in ss,
// meaning just copy paste 2 functions above down here
t_node	*ss(t_node *stack)
{
	t_stack	*temp;

	if (!stack || !stack->a || !stack->a->next || !stack->b || !stack->b->next)
		return (stack);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = stack->a->next;
	stack->a->next = temp;
	// Doing b here
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = stack->b->next;
	stack->b->next = temp;
	stack->num_of_steps += 1;
	ft_printf("ss\n");
	return (stack);
}

// t_node	*pa(t_node *stack)
// {
// 	t_stack	*temp;
// 	int		i;

// 	if (!stack || !stack->b)
// 		return (stack);
// 	i = 0;
// 	if (!stack->a)
// 	{
// 		stack->a = malloc(sizeof(t_stack) * 1);
// 		stack->a->next = NULL;
// 		i = 1;
// 	}
// 	temp = stack->b;
// 	if (stack->b->next != NULL)
// 		stack->b = stack->b->next;
// 	else
// 		stack->b = NULL;
// 	if (i == 1)
// 		temp->next = NULL;
// 	else
// 		temp->next = stack->a;
// 	stack->a = temp;
// 	stack->num_of_steps += 1;
// 	ft_printf("pa\n");
// 	return (stack);
// }

t_node	*pa(t_node *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack || !stack->b)
		return (stack);
	i = 0;
	temp = NULL;
	if (stack->a)
		temp = stack->a;
	if (!stack->a)
	{
		stack->a = stack->b;
		i = 1;
	}
	if (stack->b->next != NULL)
		stack->b = stack->b->next;
	else
		stack->b = NULL;
	if (i == 1)
		stack->a->next = NULL;
	else
		stack->a->next = temp;
	stack->a = temp;
	stack->num_of_steps += 1;
	free(temp);
	ft_printf("pa\n");
	return (stack);
}

t_node	*pb(t_node *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack || !stack->a)
		return (stack);
	i = 0;
	temp = NULL;
	if (stack->b)
		temp = stack->b;
	if (!stack->b)
	{
		stack->b = stack->a;
		i = 1;
	}
	if (stack->a->next != NULL)
		stack->a = stack->a->next;
	else
		stack->a = NULL;
	if (i == 1)
		stack->b->next = NULL;
	else
		stack->b->next = temp;
	stack->b = temp;
	free(temp);
	stack->num_of_steps += 1;
	ft_printf("pa\n");
	return (stack);
}

// t_node	*pb(t_node *stack)
// {
// 	t_stack	*temp;
// 	int		i;

// 	if (!stack || !stack->a)
// 		return (stack);
// 	i = 0;
// 	if (!stack->b)
// 	{
// 		stack->b = malloc(sizeof(t_stack) * 1);
// 		stack->b->next = NULL;
// 		// ps_del_before_last(stack->b);
// 		i = 1;
// 	}
// 	temp = stack->a;
// 	if (stack->a->next != NULL)
// 		stack->a = stack->a->next;
// 	else
// 		stack->a = NULL;
// 	if (i == 1)
// 		temp->next = NULL;
// 	else
// 		temp->next = stack->b;
// 	stack->b = temp;
// 	stack->num_of_steps += 1;
// 	ft_printf("pb\n");
// 	return (stack);
// }

t_node	*ra(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!stack || !stack->a || !stack->a->next || !get_last_node(stack->a))
		return (stack);
	last_node = get_last_node(stack->a);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = NULL;
	last_node->next = temp;
	stack->num_of_steps += 1;
	ft_printf("ra\n");
	return (stack);
}

t_node	*rb(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!stack || !stack->b || !stack->b->next || !get_last_node(stack->b))
		return (stack);
	last_node = get_last_node(stack->b);
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = NULL;
	last_node->next = temp;
	stack->num_of_steps += 1;
	ft_printf("rb\n");
	return (stack);
}

t_node	*rr(t_node *stack)
{
	ra_no_count(stack);
	rb_no_count(stack);
	stack->num_of_steps += 1;
	ft_printf("rr\n");
	return (stack);
}

t_node	*rra(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!stack || !stack->a || !stack->a->next || !get_before_last_node(stack->a) || !get_last_node(stack->a))
		return (stack);
	last_node = get_last_node(stack->a);
	before_last_node = get_before_last_node(stack->a);
	temp = stack->a;
	stack->a = last_node;
	before_last_node->next = NULL;
	stack->a->next = temp;
	stack->num_of_steps += 1;
	ft_printf("rra\n");
	return (stack);
}

t_node	*rrb(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!stack || !stack->b || !stack->b->next || !get_before_last_node(stack->b) || !get_last_node(stack->b))
		return (stack);
	last_node = get_last_node(stack->b);
	before_last_node = get_before_last_node(stack->b);
	temp = stack->b;
	stack->b = last_node;
	before_last_node->next = NULL;
	stack->b->next = temp;
	stack->num_of_steps += 1;
	ft_printf("rrb\n");
	return (stack);
}

t_node	*rrr(t_node *stack)
{
	rra_no_count(stack);
	rrb_no_count(stack);
	stack->num_of_steps += 1;
	ft_printf("rrr\n");
	return (stack);
}

t_node	*ra_no_count(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!stack || !stack->a || !stack->a->next || !get_last_node(stack->a))
		return (stack);
	last_node = get_last_node(stack->a);
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = NULL;
	last_node->next = temp;
	return (stack);
}

t_node	*rb_no_count(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!stack || !stack->b || !stack->b->next || !get_last_node(stack->b))
		return (stack);
	last_node = get_last_node(stack->b);
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = NULL;
	last_node->next = temp;
	return (stack);
}

t_node	*rra_no_count(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!stack || !stack->a || !stack->a->next || !get_before_last_node(stack->a) || !get_last_node(stack->a))
		return (stack);
	last_node = get_last_node(stack->a);
	before_last_node = get_before_last_node(stack->a);
	temp = stack->a;
	stack->a = last_node;
	before_last_node->next = NULL;
	stack->a->next = temp;
	return (stack);
}

t_node	*rrb_no_count(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;
	t_stack	*before_last_node;

	if (!stack || !stack->b || !stack->b->next || !get_before_last_node(stack->b) || !get_last_node(stack->b))
		return (stack);
	last_node = get_last_node(stack->b);
	before_last_node = get_before_last_node(stack->b);
	temp = stack->b;
	stack->b = last_node;
	before_last_node->next = NULL;
	stack->b->next = temp;
	return (stack);
}