/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifourni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:05:31 by pifourni          #+#    #+#             */
/*   Updated: 2025/08/26 10:35:10 by pifourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_PARSER_H
# define HELP_PARSER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFSIZE 1073741824

int	is_same(char *line, int *i, char obj[3]);
int	_atoi(char *str, int *i);

#endif
