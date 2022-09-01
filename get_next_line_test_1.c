/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenrique <aenrique@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:35:11 by aenrique          #+#    #+#             */
/*   Updated: 2022/09/01 08:35:14 by aenrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"stdarg.h"

char	*get_next_line(int fd)
{
	int		flrd;
	char	c;
	char	*str;
	char	*str2;

	str = malloc(1000000);
	str2 = str;
	if (flrd == read(fd, &c, 1) == 0)
		return(NULL);
	*str++ = c;
	while (flrd == read(fd, &c, 1) > 0 && c != '\n')
		*str++ = c;
	if (c == '\n')
		*str++ = '\n';
	str++ = '\0';
	return (str2);
}
