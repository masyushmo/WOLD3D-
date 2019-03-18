/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:13:46 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/11 13:13:46 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		stop(char *str)
{
	if (str != NULL)
	{
		ft_putendl("\033[22;36mUsage: ./wolf3d maps/[mapname]");
		ft_putendl("\033[23;32m[labrint] | [sample] | [minec]");
	}
	ft_putstr(str);
	exit(1);
}

void	chose(t_core *core, char *name)
{
	if ((!(ft_strcmp("./maps/labrint", name))) ||
		(!(ft_strcmp("maps/labrint", name))))
		core->name = 1;
	else if ((!(ft_strcmp("maps/minec", name))) ||
		(!(ft_strcmp("./maps/minec", name))))
		core->name = 2;
	else
		core->name = 0;
}

int		main(int argc, char **argv)
{
	t_core	*core;

	if (argc < 2)
		stop("\033[22;31mERROR: not enough args\n");
	if (argc > 2)
		stop("\033[22;31mERROR: too many args\n");
	if (!(core = ft_memalloc(sizeof(t_core))))
		stop("\033[22;31mERROR: failed to malloc main struct");
	if (!(read_map(core, argv[1])))
		stop("\033[22;31mERROR: invalid map\n");
	chose(core, argv[1]);
	game_loop(core);
	clean(core);
	return (0);
}
