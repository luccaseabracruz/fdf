#include "fdf.h"

// delete after tests
static void	print_map(t_map *map)
{
	int		i;
	t_point	point;

	i = 0;
	while (i < map->size)
	{
		point = map->p_arr[i];
		ft_printf("point %d\nx: %d\ny: %d\nz: %d\n\n", i, point.x, point.y, point.z);
		i++;
	}
}

//testing
static void	print_limits(t_limits lim)
{
	ft_printf("WIN_WIDTH: %d\n", WIN_WIDTH);
	ft_printf("WIN_HEIGHT: %d\n", WIN_HEIGHT);
	ft_printf("x_max: %d\nx_min: %d\n", lim.x_max, lim.x_min);
	ft_printf("y_max: %d\ny_min: %d\n", lim.y_max, lim.y_min);
	ft_printf("z_max: %d\nz_min: %d\n", lim.z_max, lim.z_min);
}