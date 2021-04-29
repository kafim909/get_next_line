/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:55:24 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/29 16:51:06 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include   <stdlib.h>
# include   <unistd.h>
# include   <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 590432
# endif

char	*join(char *s1, char *s2);
int		split(char **line, char **save, char **temp, int ret);
int		get_line(int fd, char **line, char **save, char **temp);
int		get_next_line(int fd, char **line);
int		len(char *s, int bol);
int		free_all(char *temp, char *line, char **save, int return_val);
int		is_nl(char *s);

#endif
