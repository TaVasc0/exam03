/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenrique <aenrique@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:44:37 by aenrique          #+#    #+#             */
/*   Updated: 2022/09/11 14:11:16 by aenrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>

char	*get_next_line(int fd)
{
	int		flrd;
	char	c;
	char	*str;
	char	*str2;

	str = malloc(1000000);
	str2 = str;
	if ((flrd = read(fd, &c, 1)) == 0)
		return (NULL);
	*str++ = c;
	while ((flrd = read(fd, &c, 1)) > 0 && c != '\n')
		*str++ = c;
	if (c == '\n')
		*str++ = '\n';
	*str = '\0';
	return (str2);
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
