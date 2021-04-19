/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:47:59 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/15 10:39:47 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *src, char *dst)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (len(src) + len(dst) + 1));
	if (!str)
		return (NULL);
	if (dst)
	{
		while (dst[j])
			str[i++] = dst[j++];
		free (dst);
	}
	j = 0;
	while (src[j] && src[j] != '\n')
		str[i++] = src[j++];
	str[i] = '\0';
	return (str);
}

char	*put_save(char *str) 
{
	char	*save;  
	size_t	i;
	
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])   // problème si on à plusieurs '\n' d'affilée? et si on rencontre un '\0'?
	{
		save = ft_strdup(str + i);
		if (!save)
			return(NULL);
		free(str);
		return (save);
	}
	return(NULL);
}

int	free_all(char *save, char *line)
{
	if (save)
		free(save);
	if (line)
		free(line);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	size_t		ret;
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	
	while (!is_newline(save))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (free_all(save, *line));
		buff[ret] = '\0';
		save = join(buff, save);
		if(!save)
			return (free_all(save, *line));
	}
	line = dup_to_line(save);
	save = put_save(save);

}
