/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:37:41 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/13 12:51:31 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	char	*ptr_dst;

	ptr_dst = (char *)dst;
	while (len--)
		*(ptr_dst++) = (char)c;
	return (dst);
}
