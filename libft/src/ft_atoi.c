/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:08:04 by hubretec          #+#    #+#             */
/*   Updated: 2022/09/29 19:36:57 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		minus = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		nb = nb * 10 + (*(nptr++) - '0');
	return (nb * minus);
}

int	ft_atoi_2(const char *nptr)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	while (*nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	if (*nptr < '0' && *nptr > '9')
		return (-1);
	while (*nptr >= '0' && *nptr <= '9')
		nb = nb * 10 + (*(nptr++) - '0');
	while (*nptr)
	{
		if (*nptr != ' ')
			return (-1);
		nptr++;
	}
	return (nb * minus);
}

