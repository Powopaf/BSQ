/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_solve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:26:34 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:46:57 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_SOLVE_H
# define HELP_SOLVE_H

# include <stdlib.h>
# include "../Include/square.h"
# include "../Include/solver.h"

void	print_map(const char *map);

typedef struct s_ctx
{
	char			*map;
	int				cols;
	int				rows;
	char			empty;
	char			obst;
	char			full;
	int				*prev;
	int				*curr;
	struct s_square	best;
}	t_ctx;

int		min3(int a, int b, int c);
int		count_rows(const char *map);
int		ctx_init(t_ctx *c, char *map, int cols, char obj[4]);
void    print_map(const char *map);

#endif
