/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:04:28 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/01 13:06:09 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD_COUNT];
	char		buffer[BUFFER_SIZE + 1];
	int			c_read;
	char		*line;

	if (fd < 0 || fd > MAX_FD_COUNT || BUFFER_SIZE < 1)
		return (NULL);
	if (leftover[fd] == NULL)
		leftover[fd] = malloc_leftover();
	if (ft_strchr(leftover[fd], '\n') == -1)
	{
		c_read = read(fd, &buffer, BUFFER_SIZE);
		while (c_read > 0)
		{
			*(buffer + c_read) = '\0';
			leftover[fd] = ft_strjoin(leftover[fd], buffer);
			if (ft_strchr(leftover[fd], '\n') != -1)
				break ;
			c_read = read(fd, &buffer, BUFFER_SIZE);
		}
	}
	line = chop_string(&leftover[fd]);
	leftover[fd] = save_leftovers(leftover[fd]);
	return (line);
}

// Norm issues. If leftover is NULL (not malloc()-ed),
// this function creaates a malloc()-ed (kinda) NULL value
char	*malloc_leftover(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	*empty = '\0';
	return (empty);
}

char	*save_leftovers(char *leftover)
{
	char	*return_str;
	int		chop_at;
	int		i;

	if (leftover == NULL || ft_strchr(leftover, '\0') == 0)
		return (NULL);
	chop_at = ft_strchr(leftover, '\n');
	if (chop_at < 0)
		return (NULL);
	else
	{
		return_str = malloc(sizeof(char) * (ft_strlen(leftover) - chop_at + 1));
		i = -1;
		while (*(leftover + (++i) + chop_at + 1))
			*(return_str + i) = *(leftover + i + chop_at + 1);
		*(return_str + i) = '\0';
	}
	free(leftover);
	return (return_str);
}

char	*chop_string(char **leftover)
{
	char	*return_str;
	int		chop_at;
	int		i;

	chop_at = ft_strchr(*leftover, '\n');
	if (chop_at < 0)
	{
		if (ft_strchr(*leftover, '\0') != 0)
			return (*leftover);
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
	return_str = malloc(sizeof(char) * (chop_at + 2));
	*(return_str + chop_at + 1) = '\0';
	i = -1;
	while (++i <= chop_at)
		*(return_str + i) = *(*(leftover) + i);
	return (return_str);
}
