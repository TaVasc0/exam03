/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenrique <aenrique@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:44:37 by aenrique          #+#    #+#             */
/*   Updated: 2022/09/13 07:09:36 by aenrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>

char	*get_next_line(int fd)
{
	int		f;
	char	c;
	char	*s1;
	char	*s2;

	s1 = malloc(1000000);
	s2 = str;
	if ((f = read(fd, &c, 1)) == 0)
		return (NULL);
	*s1++ = c;
	while ((f = read(fd, &c, 1)) > 0 && c != '\n')
		*s1++ = c;
	if (c == '\n')
		*s1++ = '\n';
	*s1 = '\0';
	return (s2);
}

int	main(void)
{
	int		fd1;
	char	*line;

	fd1	= open("text.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);

	return (0);
}
