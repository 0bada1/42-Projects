#include "push_swap.h"

// void    pa(int num1, int num2)
// {

// }

// t_node	*sa(t_node *list)
// {
// 	t_stack	*temp;

// 	if (!list)
// 		return (NULL);
// 	temp = list->a->next;
// 	list->a->next = list->a->next->next;
// 	list->a = temp;
// 	return (list);
// }

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
	ft_printf("sb\n");
	return (stack);
}

// Edit this function to manually do sa and sb in ss,
// meaning just copy paste 2 functions above down here
t_node	*ss(t_node *stack)
{
	// ft_printf("ss\n");
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
	return (stack);
}

t_node	*pa(t_node *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack || !stack->b)
		return (stack);
	i = 0;
	if (!stack->a)
	{
		stack->a = malloc(sizeof(t_stack) * 1);
		stack->a->next = NULL;
		// ps_del_before_last(stack->a);
		i = 1;
	}
	temp = stack->b;
	if (stack->b->next != NULL)
		stack->b = stack->b->next;
	else
		stack->b = NULL;
	if (i == 1)
		temp->next = NULL;
	else
		temp->next = stack->a;
	stack->a = temp;
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
	if (!stack->b)
	{
		stack->b = malloc(sizeof(t_stack) * 1);
		stack->b->next = NULL;
		// ps_del_before_last(stack->b);
		i = 1;
	}
	temp = stack->a;
	if (stack->a->next != NULL)
		stack->a = stack->a->next;
	else
		stack->a = NULL;
	if (i == 1)
		temp->next = NULL;
	else
		temp->next = stack->b;
	stack->b = temp;
	ft_printf("pb\n");
	return (stack);
}

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
	ft_printf("ra\n");
	return (stack);
}

t_node	*rb(t_node *stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	if (!stack || !stack->b || !stack->b->next)
		return (stack);
	last_node = get_last_node(stack->b);
	// ft_printf("last node = %i\n", last_node->num);
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = NULL;
	last_node->next = temp;
	// ft_printf("temp->num = %i\n", temp->num);
	ft_printf("rb\n");
	return (stack);
}

t_node	*rr(t_node *stack)
{
	ra(stack);
	rb(stack);
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
	ft_printf("rrb\n");
	return (stack);
}

t_node	*rrr(t_node *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
	return (stack);
}