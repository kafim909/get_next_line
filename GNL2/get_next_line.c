/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:43:39 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/21 19:05:47 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *src, char *dst)
{
	int		i;
	int 	j;
	char	*save;

	i = 0;
	j = 0;
	save = (char *)malloc(sizeof(char) * (len(src) + len(dst) + 1));
	if (dst)
	{
		while (dst[j])
			save[i++] = dst[j++];
	}
	j = 0;
	while (src[j])
		save[i++] = src[j++];
	save[i] = '\0';
	return (save);
}

char	*new_save(char *str) // si jamais je tombe sur le NULL BYTE, je vais renvoyer une string vide, ce qui pourras etre prit pour un malloc qui foire.
{
	int		i;
	int		j;
	char 	*save;

	j = 0;
	i = len_to_nl(str);
	while (str[i] == '\n' && str[i])
		i++;
	save = (char *)malloc(sizeof(char) * (len(str + i) + 1));
	if (!save)
		return (NULL);
	while (str[i])
		save[j++] = str[i++];
	save [j] = '\0';
	free (str);
	return (save);
}

char	*dup_to_line(char *str)
{
	int 	i;
	int 	len;
	char	*line;

	i = 0;
	len = len_to_nl(str);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	static char	*save;

	while(!is_nl(save))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (free_all(line, save));
		if (ret == 0)
			break;
		buff[ret] = '\0';
		save = join(buff, save);
		if (!save)
			return (free_all(line, save));
	}
	line = dup_to_line(save);
	if (!line)

	if (is_new_save(save))
	if (line)
		return (1);
	return (0);
}