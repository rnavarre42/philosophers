/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:04 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:37 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int
	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	if (!init_philo(&philo, argv))
		return (1);
	if (philo.times_must_eat == 0)
		return (0);
	init_diners(&philo);
	start_diner_threads(&philo);
	monitor_loop(&philo);
	wait_diners(&philo);
	free_philo(&philo);
	return (0);
}
