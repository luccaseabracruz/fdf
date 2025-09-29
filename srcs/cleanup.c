/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:06:22 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:20:55 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Free memory and set pointer to NULL.
 *
 * Safely frees the memory pointed by `*ptr` and avoids dangling
 * pointers by setting it to NULL.
 *
 * @param ptr Address of the pointer to free.
 */
void	free_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * @brief Free a NULL-terminated array of strings.
 *
 * Iterates through the array, freeing each string, then frees
 * the array itself and sets it to NULL.
 *
 * @param arr NULL-terminated array of strings.
 */
void	free_strarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free_and_null((void **)&arr[i]);
		i++;
	}
	free_and_null((void **)&arr);
}

/**
 * @brief Destroy all MLX resources and reset handles to NULL.
 *
 * Cleans up the MLX image, window, and display objects associated
 * with the given program state.
 *
 * @param dt Program data containing program data and MLX-related resources.
 */
static void	exit_window(t_data *dt)
{
	if (dt->mlx_img)
	{
		mlx_destroy_image(dt->mlx, dt->mlx_img);
		dt->mlx_img = NULL;
	}
	if (dt->mlx_win)
	{
		mlx_destroy_window(dt->mlx, dt->mlx_win);
		dt->mlx_win = NULL;
	}
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
		dt->mlx = NULL;
	}
}

/**
 * @brief Cleanup program resources and terminate execution.
 *
 * This function:
 * - Cleans up all MLX resources (window, image, display).
 * - Frees the map and its internal arrays.
 * - Exits the program with the given status code.
 *
 * @param dt     Program data to clean up.
 * @param status Exit status code (e.g., EXIT_SUCCESS or EXIT_FAILURE).
 */
void	exit_with_cleanup(t_data *dt, int status)
{
	exit_window(dt);
	if (dt->map)
	{
		if (dt->map->p_arr)
			free_and_null((void **)&dt->map->p_arr);
		if (dt->map->proj_arr)
			free_and_null((void **)&dt->map->proj_arr);
		free_and_null((void **)&dt->map);
	}
	exit(status);
}
