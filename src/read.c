/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:14:01 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/11 13:14:01 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	check_map(t_core *core)
{
	int x;
	int y;

	x = 0;
	while (x <= core->map_width - 1)
	{
		if ((core->map[0][x] < 1 || core->map[0][x] > 9) || \
			(core->map[core->map_height - 1][x] < 1 || \
			core->map[core->map_height - 1][x] > 9))
		{
			ft_putnbr(core->map[0][x]);
			return (0);
		}
		x++;
	}
	y = 0;
	while (y <= core->map_height - 1)
	{
		if ((core->map[y][0] < 1 || core->map[y][0] > 9) || \
			(core->map[y][core->map_width - 1] < 1 || \
			core->map[y][core->map_width - 1] > 9))
			return (0);
		y++;
	}
	return (1);
}

int	map(t_core *core, int fd)
{
	char	*line;
	char	**temp;
	int		ret;
	int		coord[2];

	coord[0] = 0;
	core->map = ft_memalloc(sizeof(int*) * core->map_height);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		coord[1] = 0;
		temp = ft_strsplit(line, ' ');
		core->map[coord[0]] = ft_memalloc(sizeof(int) * core->map_width);
		while (temp[coord[1]] != NULL)
		{
			core->map[coord[0]][coord[1]] = ft_atoi(temp[coord[1]]);
			free(temp[coord[1]]);
			coord[1]++;
		}
		free(temp);
		free(line);
		coord[0]++;
	}
	if (ret == -1)
		return (0);
	return (1);
}

int	check(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			line[i]++;
		else if (line[i] < '0' || line[i] > '9')
		{
			free(line);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count(t_core *core, int fd)
{
	char	**temp;
	char	*line;
	int		ret;
	int		i;

	core->map_width = 0;
	core->map_height = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		temp = ft_strsplit(line, ' ');
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
		if (!(check(line)))
			return (0);
		free(line);
		if (core->map_height == 0)
			core->map_width = i;
		else if (i != core->map_width)
			return (0);
		core->map_height++;
	}
	return (1);
}

int	read_map(t_core *core, char *file)
{
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (get_next_line(fd, &line) < 1)
		return (0);
	free(line);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(count(core, fd)))
		return (0);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(map(core, fd)))
		return (0);
	if (!(check_map(core)))
		return (0);
	close(fd);
	return (1);
}
