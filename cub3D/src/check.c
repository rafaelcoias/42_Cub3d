/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:24 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 19:05:50 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_extension(t_data *data, char *path)
{
	char	**splitted_path;

	splitted_path = ft_split(path, '.');
	if (!ft_equals(splitted_path[ft_mtxlen(splitted_path) - 1], "cub"))
	{
		ft_free_mtx(splitted_path);
		error_msg(data, INVALID_EXTENSION);
	}
	ft_free_mtx(splitted_path);
}

int	check_line(t_data *data, char **splitted, char *line)
{
	if (ft_equals(splitted[0], "F") || ft_equals(splitted[0], "C"))
		check_rgb(data, splitted, line);
	else if (ft_equals(splitted[0], "NO") || ft_equals(splitted[0], "SO")
		|| ft_equals(splitted[0], "WE") || ft_equals(splitted[0], "EA"))
		check_texture(data, splitted, line);
	else
		return (1);
	if (data->error)
	{
		free(line);
		ft_free_mtx(splitted);
		error_msg(data, data->error);
	}
	return (0);
}

void	check_texture_rgb(t_data *data, char *line)
{
	char	**splitted;
	char	*trim;

	trim = ft_strtrim(line, "\n");
	splitted = ft_split(trim, ' ');
	free(trim);
	if (!splitted || !splitted[0]
		|| ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2
		|| !splitted[1] || ft_mtxlen(splitted) >= 3)
	{
		ft_free_mtx(splitted);
		free(line);
		error_msg(data, INVALID_ELEMENT);
	}
	if (check_line(data, splitted, line))
	{
		ft_free_mtx(splitted);
		free(line);
		error_msg(data, INVALID_ELEMENT);
	}
	ft_free_mtx(splitted);
}
