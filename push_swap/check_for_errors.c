#include "push_swap.h"

// FIX LATER
/* CHECKING FOR ERRORS
- Check for any non integer ascii characters (except negative sign and positive signs)
- Check if there is no input
- CASE 1: EMPTY INPUT
- CASE 2: NON INTEGER INPUT (AND NOT +, -, OR SPACE)
- CASE 3: ./push_swap "" " "
- CASE 4: ./push
*/
int check_for_errors(char *argv[])
{
	int i;
	int j;

	i = 1;
	// ft_printf("Entering error function\n");
	if (!argv[i] || argv[1][0] == '\0')
		return (-1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			// ft_printf("%c ", argv[i][j]);
			if ((!ft_isdigit(argv[i][j])) && (argv[i][j] != '-' && argv[i][j] != '+' && !ft_isspace(argv[i][j])))
				return (-2);
			if ((ft_isdigit(argv[i][j])) && (!ft_isspace(argv[i][j + 1]) && !ft_isdigit(argv[i][j + 1])) && (argv[i][j + 1] != '\0'))
				return (-3);
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (!ft_isdigit(argv[i][j + 1])))
				return (-4);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_for_duplicates(t_node *num)
{
	t_stack	*temp;
	t_stack	*num2;
	int		i;
	int		j;

	temp = num->a;
	i = 0;
	while (i < num->number_of_ints)
	{
		j = 0;
		num2 = num->a;
		while (j < num->number_of_ints)
		{
			if (num2->num == temp->num && j != i)
					return (TRUE);
			num2 = num2->next;
			j++;
		}
		temp = temp->next;
		i++;
	}
	return (FALSE);
}
