/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:45:45 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:32:54 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/help_solve.h"

static void	update_best(struct s_square *b, int r, int c, int size)
{
	if (size > b->lenght)
	{
		b->lenght = size;
		b->x1 = c - size + 1;
		b->y1 = r - size + 1;
	}
}

static void	dp_pass_row(t_ctx *c, int r)
{
	int	cx;
	int	idx;

	cx = 0;
	while (cx < c->cols)
	{
		idx = r * (c->cols + 1) + cx;
		if (c->map[idx] == c->obst)
			c->curr[cx] = 0;
		else if (c->map[idx] == c->empty)
		{
			if (r == 0 || cx == 0)
				c->curr[cx] = 1;
			else
				c->curr[cx] = min3(c->prev[cx],
						c->prev[cx - 1], c->curr[cx - 1]) + 1;
			update_best(&c->best, r, cx, c->curr[cx]);
		}
		else
			c->curr[cx] = 0;
		cx++;
	}
}

static void	dp_swap_reset(t_ctx *c)
{
	int	i;

	i = 0;
	while (i < c->cols)
	{
		c->prev[i] = c->curr[i];
		c->curr[i] = 0;
		i++;
	}
}

static void	paint_square(t_ctx *c)
{
	int	dy;
	int	dx;
	int	idx;
	int	stride;

	if (c->best.lenght <= 0)
		return ;
	stride = c->cols + 1;
	dy = 0;
	while (dy < c->best.lenght)
	{
		dx = 0;
		while (dx < c->best.lenght)
		{
			idx = (c->best.y1 + dy) * stride + (c->best.x1 + dx);
			if (c->map[idx] != '\n' && c->map[idx] != '\0')
				c->map[idx] = c->full;
			dx++;
		}
		dy++;
	}
}

void	solveur(char *map, int i, char obj[4])
{
	t_ctx	c;
	int		r;

	if (!ctx_init(&c, map, i, obj))
		return ;
	r = 0;
	while (r < c.rows)
	{
		dp_pass_row(&c, r);
		dp_swap_reset(&c);
		r++;
	}
	paint_square(&c);
	print_map(c.map);
	free(c.prev);
	free(c.curr);
}
