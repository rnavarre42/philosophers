/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:13:36 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/13 12:51:42 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

/*
**  Reserve memory and initialize with zeroes
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array_ptr;

	array_ptr = malloc(nmemb * size);
	if (!array_ptr)
		return (NULL);
	ft_memset(array_ptr, 0, nmemb * size);
	return (array_ptr);
}
