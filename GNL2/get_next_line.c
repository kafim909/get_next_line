/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:43:39 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/24 18:57:41 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int new_save(char *save, char *buff, char *line, int bol)
{
	int 	start;
	int 	end;
	char	*temp;

	temp = NULL;

	if (bol == 1)
	{
		start = len(save, 1);
		end = len(save, 0);
		temp = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!temp)
			return (free_all(line, save));
		copy(temp, save, start, end);
	}
	else
	{
		start = len(buff, 1);
		end = len(buff, 0);
		// printf("*%d | %d | %s*\n", end - start + 1, len(&buff[start], 0) + 1, &buff[start]);
		// temp = (char *)calloc((end - start + 1), 1);
		temp = (char *)malloc(sizeof(char) * (end - start + 100));
		temp[0] = '\0';
		if (!temp)
			return (free_all(line, save));
		copy(temp, buff, start, end);
	//	printf("||%d | %d | %p||\n", end - start + 1, len(&buff[start], 0) + 1, temp);
	}
	if (save)
		free (save);
	temp[end] = '\0';
	save = temp;
	return (1);
}

int	save_to_line(char *line, char *save)
{
	int i;
	int j;

	i = len(save, 1);
	j = 0;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free_all(line, save));
	j = copy(line, save, j, i);
	line[j]= '\0';
	if (is_new_save(save))
		return (new_save(save, NULL,  line, 1));
	return (1);
}

char	*join(char *line, char *save, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = (char *)malloc(sizeof(char) * (len(line, 0) + len(save, 0) + len(buff, 1) + 1));
	if (!temp)
		return (NULL);
	if (save)
	{
		j = copy(temp, save, j, len(save, 0));
		free(save);
		save = NULL;
	}
	if (line)
	{
		j = copy(temp, line, j, j + len(line, 0));
		free(line);
		line = NULL;
	}
	j = copy(temp, buff, j, j + len(buff, 1));
	// printf("//[%s] [%s]*[%d][%d]//\n", temp, buff, j, len(buff, 1));
	return (temp);
}

int	get_line(char **line, char *save, char *buff, int fd)
{
	int	ret;

	ret = 1;
	*line = join(*line, save, buff); 							// je vide mon save et mon buff dans ma line. 
	if (!*line)
		return (free_all(*line, save));
	while (!is_nl(buff) && ret > 0)  							// je boucle tant que pas de NL dans mon buff et que je ne suis pas a EOF;
	{
		ret = read(fd, buff, BUFFER_SIZE); 	
		// printf("{%s}\n", buff);
		if (ret < 0)
			return (free_all(*line, save));
		buff[ret] = '\0';
		*line = join(*line , save, buff);
	//	printf("%s\n", *line);
		if (!*line)
			return (free_all(*line, save));
	}
	if (is_new_save(buff))    									// si il y a du contenu après NL dans buff, je sauvegarde ce contenu dans save 
		return (new_save(save, buff , *line, 0));
//	printf("%s\n", *line);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	static char	*save = NULL;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)          		// input error check
		return (-1);
	if (is_nl(save))	                        			 // si j'ai une NL dans save = ligne complète dans save ou alors si ret vaux 0?
		return (save_to_line(save, *line));
	ret = read(fd, buff, BUFFER_SIZE);	     				// je fais un premier read pour avoir une valeur de ret dans ma FT GNL
	if (ret < 0)
		return (free_all(*line, save));
	buff[ret] = '\0';
	if (!ret && !save)                              		// si save est vide et que ret == 0, fini GNL
		return (0);
	return (get_line(line, save, buff, fd));		
}