#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*nums;
	// int	i;

	// i = 1;
	if (argc > 1)
	{
		// while (argv[i] != NULL)
		// 	ft_printf("%s\n", argv[i++]);
		if (check_for_errors(argv) < 0)
		{
			ft_printf("returning now\n");
			return (0);
		}
		ft_printf("No errors found\n");
		nums = parse(argv);
		if (nums->number_of_ints == 1)
			return (1);
		ft_printf("Successfully finished parsing\n");
		ft_printf("checking parsed list\n");
		check_list(nums->a);
		check_list(nums->b);
		if (check_for_duplicates(nums) == TRUE)
		{
			ft_printf("Duplicates are not allowed\nExiting program");
			free_everything(*nums);
			return (0);
		}
		initialize_variables_and_space(nums);
		// ft_printf("--------list->b = %p\n", nums->b);
		// ft_printf("nums->b = %i\n", nums->b->num);
		// ft_printf("--------list->b before null = %p\n", nums->b);
		nums->b = NULL;
		// ft_printf("--------list->b after null = %p\n", nums->b);
		ft_printf("num_of_ints = %i\n", nums->number_of_ints);
		ft_printf("Running algorithm\n");
		algorithm(nums);
		// pb(nums);
		// pb(nums);
		// pb(nums);
		// pb(nums);
		// pb(nums);
		// pa(nums);
		ft_printf("Checking list a\n");
		check_list(nums->a);
		ft_printf("Checking list b\n");
		check_list(nums->b);
		check_if_sorted(nums->a);
		// ft_printf("Checking a\n");
		// ft_printf("Checking b\n");
		// check_list(nums->b);
		// pb(nums);
		// ft_printf("Checking a\n");
		// check_list(nums->a);
		// ft_printf("Checking b\n");
		// check_list(nums->b);
		// while (nums[i++])
		// 	ft_printf("nums = %i\n", nums[i]);
	}
}
