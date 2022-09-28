/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:14:55 by hubretec          #+#    #+#             */
/*   Updated: 2022/09/28 18:55:28 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	char	*str;

	s1len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (s1len + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - s1len])
	{
		str[i] = s2[i - s1len];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free((char *)s1);
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
	{
		while (s1[++i])
			tab[j++] = s1[i];
	}
	i = -1;
	if (s2)
	{
		while (s2[++i] && s2)
			tab[j++] = s2[i];
	}
	free((char *)s1);
	tab[j] = 0;
	return (tab);
}