/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:01:37 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:16:30 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/help_parser.h"

int	first_line(char	*line, char obj[4])
{
	int		i;

	i = 0;
	obj[3] = (char)_atoi(line, &i);
	if (is_same(line, &i, obj) == -1)
		return (-1);
	if (line[i] != '\n')
		return (-1);
	return (i + 1);
}

int	is_object(char c, char obj[4])
{
	if (obj[2] == c)
	{
		return (0);
	}
	return (c == obj[0] || c == obj[1]);
}

int	check_map(char *map, int i, char obj[4])
{
	int	count;
	int	nb_char;

	nb_char = 0;
	count = 0;
	while (map[i] != '\0' && map[i] != '\n' && is_object(map[i], obj))
	{
		nb_char++;
		i++;
	}
	if (map[i] != '\n')
		return (-1);
	i++;
	count++;
	while (map[i] != '\0' && is_object(map[i], obj))
	{
		while (map[i] != '\0' && map[i] != '\n' && is_object(map[i], obj))
			i++;
		count++;
		i++;
	}
	if (count != obj[3])
		return (-1);
	return (nb_char);
}

char	*parser(const char *path, char obj[4], int *j)
{
	int		fd;
	int		n;
	int		i;
	char	*line;

	line = malloc(sizeof(char) * BUFFSIZE);
	fd = open(path, O_RDONLY);
	if (fd < 1)
		return (0);
	n = read(fd, line, BUFFSIZE);
	i = first_line(line, obj);
	if (i == -1)
		return (free(line), close(fd), NULL);
	*j = check_map(line, i, obj);
	if (*j == -1)
	{
		return (free(line), close(fd), NULL);
	}
	close(fd);
	return (line);
}

/*
#include <stdio.h>

int main(int argc, char **argv) 
{
	char obj[3];
	int j;
	char *a = parser(argv[1], obj, &j);
	printf("%s", a);
	printf("%d\n", j);
	printf("%s\n", obj);
	return argc;
}
*/
