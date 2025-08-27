/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:24:23 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:24:35 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/help_solve.h"

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	count_rows(const char *map)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
}

int	ctx_init(t_ctx *c, char *map, int cols, char obj[4])
{
	c->map = map;
	c->cols = cols;
	c->rows = count_rows(map);
	c->empty = obj[0];
	c->obst = obj[1];
	c->full = obj[2];
	c->best.x1 = 0;
	c->best.y1 = 0;
	c->best.lenght = 0;
	c->prev = (int *)malloc(sizeof(int) * (cols + 1));
	c->curr = (int *)malloc(sizeof(int) * (cols + 1));
	if (!c->prev || !c->curr)
		return (0);
	return (1);
}
