/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:52:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/24 17:40:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

int     copy(char *s1, char *s2, int start, int end);
int     len(char *s, int bol);
int     free_all(char *line, char *save);
int     is_nl(char *s);
int     is_new_save(char *s);
int     new_save(char *save, char *buff, char *line, int bol);
int     save_to_line(char *line, char *save);
char    *join(char *line, char *save, char *buff);
int     get_line(char **line, char *save, char *buff, int fd);
int		get_next_line(int fd, char **line);

#endif
