/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miggonza <miggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:54:09 by miggonza          #+#    #+#             */
/*   Updated: 2023/01/12 11:49:24 by miggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = s;
	while (i < n)
		temp[i++] = 0;
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*recive;

	recive = malloc(count * size);
	if (!recive)
		return (NULL);
	ft_bzero(recive, count * size);
	return (recive);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*recive;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
	recive = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!recive)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		recive[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		recive[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (recive);
}
