/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:05:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/29 16:59:57 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	int		tot_len;
	char	*temp;

	i = 0;
	j = 0;
	tot_len = len(s1, 0) + len(s2, 0);
	temp = malloc(sizeof(char) * (tot_len + 1));
	if (!temp)
		return (NULL);
	if (s1)
	{
		while (s1[j])
			temp[i++] = s1[j++];
		free(s1);
		s1 = NULL;
	}
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

int	split(char **line, char **save, char **temp, int ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*line = malloc(sizeof(char) * (len(*temp, 1) + 1));
	if (!*line)
		return (free_all(*temp, *line, save, -1));
	while ((*temp)[i] != '\n' && (*temp)[i])
		(*line)[j++] = (*temp)[i++];
	(*line)[j] = '\0';
	if (ret == 0 && !(*temp)[i])
		return (free_all(*temp, *line, save, 0));
	if ((*temp)[i] == '\0')
		return (free_all(*temp, *line, save, 1));
	if ((*temp)[i + 1])
	{
		i++;
		*save = join(*save, *temp + i);
		if (!*save)
			return (free_all(*temp, *line, save, -1));
	}
	return (free_all(*temp, *line, save, 1));
}

int	get_line(int fd, char **line, char **save, char **temp)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
		return (free_all(*temp, *line, save, -1));
	buff[ret] = '\0';
	*temp = join(*temp, buff);
	if (!temp)
		return (free_all(*temp, *line, save, -1));
	while (!is_nl(*temp) && ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (free_all(*temp, *line, save, -1));
		buff[ret] = '\0';
		*temp = join(*temp, buff);
		if (!temp)
			return (free_all(*temp, *line, save, -1));
	}
	return (split(line, &save[fd], temp, ret));
}

int	get_next_line(int fd, char **line)
{
	static char	*save[MAX_FD];
	char		*temp;

	temp = NULL;
	if (fd < 0 || read(fd, temp, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (save[fd])
	{
		temp = join(temp, save[fd]);
		if (!temp)
			return (free_all(temp, *line, save, -1));
		free (save[fd]);
		save[fd] = NULL;
	}
	return (get_line(fd, line, save, &temp));
}
