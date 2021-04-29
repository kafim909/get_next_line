/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:57:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/29 16:27:08 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *s, int bol)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (bol == 1)
	{
		while (s[i] && s[i] != '\n')
			i++;
		return (i);
	}
	while (s[i])
		i++;
	return (i);
}

int	free_all(char *temp, char *line, char **save, int return_val)
{
	int		i;

	i = 0;
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	if (*save && return_val == -1)
	{
		free(*save);
		*save = NULL;
	}
	if (line && return_val == -1)
	{
		free(line);
		line = NULL;
	}
	return (return_val);
}

int	is_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
