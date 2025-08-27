/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:24:02 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/27 21:07:52 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_same(char *line, int *i, char obj[3])
{
	obj[0] = line[*i];
	obj[1] = line[*i + 1];
	obj[2] = line[*i + 2];
	(*i) = *i + 3;
	if (obj[0] == obj[1])
		return (-1);
	if (obj[0] == obj[2])
		return (-1);
	if (obj[2] == obj[1])
		return (-1);
	return (1);
}

char	_atoi(char *str, int *i)
{
	char	res;

	res = 0;
	*i = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10;
		res = res + str[*i] - '0';
		(*i)++;
	}
	return (res);
}
