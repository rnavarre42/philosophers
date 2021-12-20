/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_die.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:15 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:30 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

_Bool
	should_die(t_diner *diner)
{
	if (diner->time_to_death < now())
	{
		print_state("die", diner);
		diner->state = diner_dead;
		return (true);
	}
	return (false);
}
