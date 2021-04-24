/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:29:54 by mtournay          #+#    #+#             */
/*   Updated: 2021/04/24 19:00:13 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char    *line;

 //   int ret;

    fd = open("test.txt", O_RDONLY);
    line = NULL;
//  printf("%d\n", fd);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        free(line);
        line = NULL; 
//        printf("coucou");
    } 
//    printf("%d\n", get_next_line(fd, &line));
//    ret = get_next_line(fd, &line);
//    printf("%d\n", ret);
    close(fd);
    return (0);
}
