/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:34:24 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:54:13 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/main.h"

int	main(int argc, char **argv)
{
	int		i;
	char	obj[4];
	char	*map;

	i = 1;
	while (i < argc)
	{
		map = parser(argv[i], obj, &i);
		if (map == NULL)
		{
			write(1, ERROR_MSG, SIZE_ERROR);
			return (-1);
		}
		solveur(map, i, obj);
	}

	return (0);
}
