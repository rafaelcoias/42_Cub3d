/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:24:40 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:20:08 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	exit_cub(t_data *data)
{
	int	i = 0;
	if (!data)
		exit(0);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	while (i < 20)
	{
		free(data->world_map[i]);
		i++;
	}
	free(data->world_map);
	free(data->mlx);
	exit(0);
}

int	handle_key(int key, t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	if (key == ESCAPE)
		exit_cub(data);
	else if (key == KEY_W)
		move_w(data);
	else if (key == KEY_S)
		move_s(data);
	else if (key == KEY_D)
		move_d(data);
	else if (key == KEY_A)
		move_a(data);
	else if (key == KEY_LEFT)
	{
		data->angle_r = data->angle_r - 0.5;
      	data->dirX = data->dirX * cos(0.5) - data->dirY * sin(0.5);
     	data->dirY = oldDirX * sin(0.5) + data->dirY * cos(0.5);
		data->planeX = data->planeX * cos(0.5) - data->planeY * sin(0.5);
		data->planeY = oldPlaneX * sin(0.5) + data->planeY * cos(0.5);
	}
	return (0);
}
