/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:19:10 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/15 06:54:13 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] || s1[i] != '\n')
		str[i++] = s1[i++];
	str[i] = '\0';
	return (str);
}

char	*dup_to_line(char *s1)
{
	char	*str;

	str = ft_strdup(s1);
	free(s1);
	return (str);
}

int is_newline(char *s)
{
    size_t  i;

    i = 0;
    while(s[i])
    {
        if (s[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}