#include "push_swap.h"

/* CHECKING FOR ERRORS
- Check for any non integer ascii characters (except negative sign and positive signs)
- Check if there is no input
- CASE 1: EMPTY INPUT
- CASE 2: NON INTEGER INPUT (AND NOT +, -, OR SPACE)
- CASE 3: 
- CASE 4:
*/
int check_for_errors(char *argv[])
{
	int i;
	int j;

	i = 1;
	ft_printf("Entering error function\n");
	if (!argv[i])
	{
		ft_printf("Error 1: Input is empty");
		return (-1);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			ft_printf("%c ", argv[i][j]);
			if ((!ft_isdigit(argv[i][j])) && (argv[i][j] != '-' && argv[i][j] != '+' && !ft_isspace(argv[i][j])))
			{
				ft_printf("\nError 2: Only integers are allowed\nYou used %c\n", argv[i][j]);
				return (-2);
			}
			if ((ft_isdigit(argv[i][j])) && (!ft_isspace(argv[i][j + 1]) && !ft_isdigit(argv[i][j + 1])) && (argv[i][j + 1] != '\0'))
			{
				ft_printf("\nError 3: j = %i & Only integers are allowed\nYou used %c\n", j, argv[i][j + 1]);
				return (-3);
			}
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (!ft_isdigit(argv[i][j + 1])))
			{
				ft_printf("\nError 4: Only integers are allowed\nYou used %c\n", argv[i][j]);
				return (-4);
			}
			j++;
		}
		i++;
	}
	printf("\n");
	return (1);
}

int	check_for_duplicates(t_node *num)
{
	t_stack	*temp;
	t_stack	*num2;
	int		i;
	int		j;

	ft_printf("Entered check for duplicates function\n");
	temp = num->a;
	i = 0;
	ft_printf("number of ints = %i\n", num->number_of_ints);
	while (i < num->number_of_ints)
	{
		j = 0;
		num2 = num->a;
		ft_printf("i = %i\n", i);
		ft_printf("temp[%i] = %i\n", i, temp->num);
		while (j < num->number_of_ints)
		{
			ft_printf("num2[%i] = %i\n", j, num2->num);
			if (num2->num == temp->num && j != i)
				return (TRUE);
			num2 = num2->next;
			j++;
		}
		temp = temp->next;
		i++;
	}
	ft_printf("Returning false\n");
	return (FALSE);
}
