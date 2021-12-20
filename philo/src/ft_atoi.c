/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:07:26 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/13 12:53:27 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	long long	nb;
	int			neg;

	nb = 0;
	neg = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		nptr++;
	if (*nptr == '-')
		neg = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (neg > 0 && nb > INT_MAX)
			return (-1);
		else if (neg < 0 && nb < INT_MIN)
			return (0);
		nb = nb * 10 + (*nptr++ - '0');
	}
	return (nb * neg);
}
