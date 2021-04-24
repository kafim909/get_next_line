/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:59:09 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/24 18:50:27 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	copy(char *s1, char *s2, int start, int end)
{
	int i;

	i = 0;
	// printf("***%s***\n", s1);
	// printf("***[%s][%d][%d]***\n", s2, start, end);
	while (start < end && s2[i])
	{
	//	printf("[%d][%d]\n", start, end);
		// printf("[%c]", s2[i]);
		s1[start++] = s2[i++];
	}
	s1[start] = '\0';
//	printf("****%s**\n", s1);
	return (start);
}

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

int	free_all(char *line, char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (-1);
}

int is_nl(char *s)
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

int	is_new_save(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = len(s, 1);
	while (s[i] == '\n' && s[i])
		i++;
	if (s[i])
		return (1);
	return (0);
}