#include "push_swap.h"

/* PARSING FUNCTION
As always, check for errors first
We first need to know how many numbers were entered (NOT ARGUMENTS) were entered by the user
We do that by using function 'find_num_of_ints which would tell us how many numbers we were given
next we assign each number into the 'nums' array and return..

NOTES
- When removing ft_printf, make this change to the line above it:
nums[counter.k++] = ft_atoi(cnums[counter.j++]);
*/
// int *parse(char *argv[])
// {
// 	char		**cnums;
// 	int 		*nums;
// 	int			num_of_ints;
// 	t_counter	counter;

// 	ft_printf("Entered parsing function and going into find_num_of_ints_2D\n");
// 	num_of_ints = find_num_of_ints_2D(argv);
// 	ft_printf("Exited find_num_of_ints_2D function\n");
// 	if (num_of_ints == 0)
// 		return (NULL);
// 	counter.i = 1;
// 	counter.k = 0;
// 	nums = malloc(sizeof(int) * num_of_ints + 1);
// 	if (!argv)
// 		return (NULL);
// 	ft_printf("Entering while loop\n");
// 	while (counter.i < num_of_ints + 1 && argv[counter.i] != NULL)
// 	{
// 		counter.j = 0;
// 		cnums = ft_split(argv[counter.i], ' ');
// 		while (cnums[counter.j])
// 		{
// 			nums[counter.k] = ft_atoi(cnums[counter.j++]);
// 			ft_printf("%i ", nums[counter.k++]);
// 		}
// 		free(cnums);
// 		counter.i++;
// 	}
// 	ft_printf("\n");
// 	ft_printf("Exiting parse function\n");
// 	return (nums);
// }
		// ft_printf("Entered while loop and counter.i = %i\n", counter.i);
		// ft_printf("\nwhile loop 1 before\n");
			// ft_printf("Cnums[%i] = %s\n", counter.i, cnums[counter.j]);
		// ft_printf("\nwhile loop 1 after\n");

t_node *parse(char *argv[])
{
	char		**cnums;
	t_node		*nums;
	t_stack		*tmp;
	t_counter	counter;

	nums = malloc(sizeof(t_node));
	ft_printf("Entered parsing function and going into find_num_of_ints_2D\n");
	nums->number_of_ints = find_num_of_ints_2D(argv);
	ft_printf("Exited find_num_of_ints_2D function\n");
	if (nums->number_of_ints == 0)
		return (NULL);
	counter.i = 1;
	nums->a = malloc(sizeof(t_stack));
	if (!argv)
		return (NULL);
	tmp = nums->a;
	nums->b = NULL;
	tmp->next = malloc(sizeof(t_stack) * 1);
	ft_printf("Entering while loop\n");
	while (counter.i < nums->number_of_ints + 1 && argv[counter.i] != NULL && tmp->next != NULL)
	{
		counter.j = 0;
		cnums = ft_split(argv[counter.i], ' ');
		while (cnums[counter.j] != NULL)
		{
			tmp->num = ft_atoi(cnums[counter.j++]);
			ft_printf("tmp->num = %d\n", tmp->num);
			tmp->next = malloc(sizeof(t_stack));
			tmp = tmp->next;
			// tmp2->next = malloc(sizeof(t_stack));
			// tmp2 = tmp2->next;
		}
		free(cnums);
		counter.i++;
	}
	ft_printf("Exited while loop\n");
	tmp->next = NULL;
	// tmp2->next = NULL;
	ps_dellast(nums->a);
	// ps_dellast(nums->b);
	// tmp->num = ft_atoi(argv[counter.i]);
	ft_printf("after change\n");
	// tmp->next = NULL;
	ft_printf("\n");
	ft_printf("Exiting parse function\n");
	return (nums);
}

// tmp->num = ft_atoi(cnums[counter.j++]);
// 			ft_printf("tmp->num = %d\n", tmp->num);
// 			tmp->next = malloc(sizeof(t_stack) * 1);
// 			tmp = tmp->next;