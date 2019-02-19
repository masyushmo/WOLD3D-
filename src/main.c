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
		ft_putendl("\033[22;36mUsage: ./wolf3d ./maps/[mapname]");
		ft_putendl("\033[23;32m[level1] | [level2] | [level3]");
	}
	ft_putstr(str);
	SDL_Quit();
	exit(1);
	return (0);
}

void	start(t_core *core)
{
	player_init(core->player);
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
	create_win(core);
	return (0);
}