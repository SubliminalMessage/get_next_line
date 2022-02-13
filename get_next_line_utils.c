/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:06:27 by dangonza          #+#    #+#             */
/*   Updated: 2022/02/01 13:07:46 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	size_t	char_index;

	char_index = 0;
	while (*(s + char_index))
	{
		if (*(s + char_index) == (char)c)
			return (char_index);
		char_index++;
	}
	if (c == '\0')
		return (char_index);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (*(s1 + (++i)) != '\0')
		*(new_str + i) = *(s1 + i);
	i = -1;
	while (*(s2 + (++i)) != '\0')
		*(new_str + s1_len + i) = *(s2 + i);
	*(new_str + s1_len + s2_len) = '\0';
	free(s1);
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
