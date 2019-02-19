/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:20:42 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/09 15:20:43 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_line_end(char **red, char **line, int fd)
{
	*line = ft_strdup(red[fd]);
	ft_strdel(&red[fd]);
}

static void	ft_line_n(char **red, char **line, int fd, int len)
{
	char *temporari;

	*line = ft_strsub(red[fd], 0, len);
	temporari = ft_strdup(red[fd] + len + 1);
	free(red[fd]);
	red[fd] = ft_strdup(temporari);
	free(temporari);
}

static int	ft_line_len(char **red, int fd, char **line, int ret)
{
	int len;

	len = 0;
	if (ret == 0 && (red[fd] == 0 || red[fd][0] == '\0'))
		return (0);
	while (red[fd][len] != '\n' && red[fd][len] != '\0')
		len++;
	if (red[fd][len] == '\n')
		ft_line_n(red, line, fd, len);
	else if (red[fd][len] == '\0')
		ft_line_end(red, line, fd);
	if (line > 0)
		return (1);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*red[MAX_FD];
	char		*buf;
	int			ret;
	char		*tnt;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || (read(fd, buf, 0) < 0))
	{
		free(buf);
		return (-1);
	}
	while (!(ft_strchr(buf, '\n'))
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (red[fd] == NULL)
			red[fd] = ft_strnew(1);
		tnt = ft_strjoin(red[fd], buf);
		free(red[fd]);
		red[fd] = ft_strdup(tnt);
		free(tnt);
	}
	free(buf);
	return (ft_line_len(red, fd, line, ret));
}
