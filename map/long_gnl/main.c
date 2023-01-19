/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:34:27 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/19 16:07:59 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Open
#include <fcntl.h>

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	int		lineas;

	lineas = 5;
	//printf("%d", OPEN_MAX);
	//atexit(ft_leaks);
	
	//fd = open("./gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	fd = open("./gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	while (lineas > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		lineas--;
	}
	close(fd);
	return (0);
}
