/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:14:20 by hubretec          #+#    #+#             */
/*   Updated: 2022/09/29 18:19:29 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src, char c)
{
	int		i;
	char	*string;

	i = 0;
	if (!c)
		c = '\0';
	while(src[i] && src[i] != c)
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (0);
	i = -1;
	while (src[++i] != c)
		string[i] = src[i];
	string[i] = '\0';
	return (string);
}
