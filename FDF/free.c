#include "fdf.h"

void	free_parsed_map(t_position **points, t_data *img)
{
	int	y;

	y = 0;
	while (y + 1 < img->rows)
	{
		free(points[y]);
		y++;
	}
	free (points);
}