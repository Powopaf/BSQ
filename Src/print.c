/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:21:41 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:32:35 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != '.' && s[i] != 'o' && s[i] != 'x')
		i--;
	return (i + 1);
}

static void	ft_putstr(const char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 0)
		(void)write(1, s, len);
}

void	print_map(const char *map)
{
	int	offset;

	offset = 0;
	while (map[offset] != '\n')
	{
		offset++;
	}
	ft_putstr(map + offset + 1);
	write(1, "\n", 1);
}
