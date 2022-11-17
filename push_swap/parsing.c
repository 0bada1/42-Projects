#include "push_swap.h"

/* PARSING FUNCTION
As always, check for errors first
We first need to know how many numbers were entered (NOT ARGUMENTS) were entered by the user
We do that by using function 'find_num_of_ints which would tell us how many numbers we were given
next we assign each number into the 'nums' array and return..

NOTES
- When removing ft_printf, make this change to the line above it:
nums[counter.k++] = ft_(cnums[counter.j++]);
*/
t_node *parse(char *argv[])
{
	char		**cnums;
	t_node		*nums;
	t_stack		*tmp;
	t_counter	counter;

	nums = ft_calloc(sizeof(t_node), 1);
	nums->number_of_ints = find_num_of_ints_2D(argv);
	if (nums->number_of_ints == 0)
		return (NULL);
	counter.i = 1;
	nums->a = ft_calloc(sizeof(t_stack), 1);
	if (!argv)
		return (NULL);
	tmp = nums->a;
	nums->b = NULL;
	// tmp->next = ft_calloc(sizeof(t_stack), 1);
	counter.k = 0;
	while (counter.k < nums->number_of_ints + 1 && argv[counter.i] != NULL)
	{
		counter.j = 0;
		cnums = ft_split(argv[counter.i], ' ');
		while (cnums[counter.j] != NULL)
		{
			counter.k++;
			tmp->num = ft_atoi_ps(cnums[counter.j++], nums);
			if (counter.k < nums->number_of_ints)
				tmp->next = ft_calloc(sizeof(t_stack), 1);
			tmp = tmp->next;
		}
		free(cnums);
		counter.i++;
	}
	if (nums->number_of_ints >= 500)
		nums->chunk_size = nums->number_of_ints / 16;
	else if (nums->number_of_ints >= 100)
		nums->chunk_size = nums->number_of_ints / 6;
	else if (nums->number_of_ints >= 10)
		nums->chunk_size = nums->number_of_ints / 10;
	else
		nums->chunk_size = 1;
	tmp = NULL;
	nums = get_index(nums);
	nums = get_chunk_num(nums);
	return (nums);
}
// tmp->num = ft_atoi(cnums[counter.j++]);
// 			ft_printf("tmp->num = %d\n", tmp->num);
// 			tmp->next = malloc(sizeof(t_stack) * 1);
// 			tmp = tmp->next;

t_node	*get_index(t_node *stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		num;
	int		index;

	temp = stack->a;
	while (temp != NULL)
	{
		temp2 = stack->a;
		num = temp->num;
		index = 0;
		while (temp2 != NULL)
		{
			
			if (temp2->num < num)
				index++;
			temp2 = temp2->next;
		}
		temp->index = index;
		temp = temp->next;
	}
	return (stack);
}

t_node	*get_chunk_num(t_node *stack)
{
	t_stack	*temp;

	temp = stack->a;
	while (temp != NULL)
	{
		temp->chunk_num = temp->index / stack->chunk_size;
		temp = temp->next;
	}
	return (stack);
}