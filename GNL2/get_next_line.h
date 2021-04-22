/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:52:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/21 10:47:49 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(int fd, char **line);
int		is_nl(char *s);
int		len(char *s);
int		len_to_nl(char *s);
int		free_all(char *line, char *save);
int		is_new_save(char *s);
char    *dup_to_line(char *str);
char	*new_save(char *str);
char	*join(char *src, char *dst);

#endif
