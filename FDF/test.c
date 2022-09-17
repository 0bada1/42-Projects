

void	parse(int fd)
{
	int		**fdf_list;
	char	**char_fdf_list;
	char	*current_line;
	int		i;
	int		j;

	while (get_next_line != NULL)
	{
		current_line = get_next_line(fd);
		char_fdf_list = ft_split(current_line, ' ');
	}
	printf("%s\n", char_fdf_list[0]);
}

int	main(void)
{
	int fd = open("test_maps/42.fdf", O_RDONLY);
	parse(fd);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int num = 1;

// 	if (num == 1)
// 		printf("num = 1");
// 	else
// 		printf("num != 1");
// }