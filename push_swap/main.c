#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*nums;

	if (argc > 1)
	{
		if (check_for_errors(argv) < 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		nums = parse(argv);
		if (nums->number_of_ints == 1)
			return (1);
		if (check_for_duplicates(nums) == TRUE)
		{
			ft_printf("Error\n");
			return (0);
		}
		initialize_variables_and_space(nums);
		algorithm(nums);
		free_everything(nums);
	}
	return (0);
}

// ft_printf("number of steps = %i\n", nums->num_of_steps);
// /usr/bin/python3 visualizer.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
