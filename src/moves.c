/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:49:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/26 14:49:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	moveUP(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coordY)][(int)(player->coordX
		+ player->dirX * player->speedMOVE)] == 0)
		player->coordX += player->dirX * player->speedMOVE;
	if (core->map[(int)(player->coordY + player->dirY
		* player->speedMOVE)][(int)(player->coordX)] == 0)
		player->coordY += player->dirY * player->speedMOVE;
}

void	moveDOWN(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coordY)][(int)(player->coordX
		- player->dirX * player->speedMOVE)] == 0)
		player->coordX -= player->dirX * player->speedMOVE;
	if (core->map[(int)(player->coordY - player->dirY
		* player->speedMOVE)][(int)(player->coordX)] == 0)
		player->coordY -= player->dirY * player->speedMOVE;
}

void	moveRIGHT(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coordY)][(int)(player->coordX
		+ player->planX * player->speedMOVE)] == 0)
		player->coordX += player->planX * player->speedMOVE;
	if (core->map[(int)(player->coordY + player->planY
		* player->speedMOVE)][(int)(player->coordX)] == 0)
		player->coordY += player->planY * player->speedMOVE;
}

void	moveLEFT(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coordY)][(int)(player->coordX
		- player->planX * player->speedMOVE)] == 0)
		player->coordX -= player->planX * player->speedMOVE;
	if (core->map[(int)(player->coordY - player->planY
		* player->speedMOVE)][(int)(player->coordX)] == 0)
		player->coordY -= player->planY * player->speedMOVE;
}