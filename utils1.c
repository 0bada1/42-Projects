#include "push_swap.h"

int	find_num_of_ints_2D(char *cnums[])
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	j = 0;
	counter = 0;
	while (cnums[i])
	{
		if (j == 0 && (cnums[i][j] >= '0' && cnums[i][j] <='9'))
			counter++;
		if ((cnums[i][j] >= '0' && cnums[i][j] <='9') && (cnums[i][j - 1] == '-' || cnums[i][j - 1] == ' ' || cnums[i][j] == '\"' || cnums[i][j] == '\'') && (cnums[i][j]))
			counter++;
		j++;
		if (!cnums[i][j])
		{
			j = 0;
			i++;
		}
	}
	return (counter);
}

int	find_num_of_ints(char *cnums)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (cnums[i])
	{
		if ((cnums[i] < '0' && cnums[i] > '9'))
			counter++;
		i++;
	}
	ft_printf("\ncounter = %i\n", counter);
	return (counter);
}

int	ft_isspace(char	c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*temp;

	if (!stack || !stack->next)
		return (stack);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*get_before_last_node(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!stack || !stack->next)
		return (stack);
	temp = stack;
	while (temp->next != NULL)
	{
		before_last = temp;
		temp = temp->next;
	}
	return (before_last);
}