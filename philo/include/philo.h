/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:35 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:27:18 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdint.h>
# include <pthread.h>

enum e_diner_state
{
	diner_eating,
	diner_sleeping,
	diner_thinking,
	diner_lock,
	diner_must_die,
	diner_dead
};

typedef struct s_diner
{
	int					id;
	int					times_eat;
	uint64_t			time_to_death;
	uint64_t			excess_time;
	pthread_t			pthread;
	pthread_mutex_t		*chopstick_min_mutex;
	pthread_mutex_t		*chopstick_max_mutex;
	enum e_diner_state	state;
	struct s_philo		*parent;
}				t_diner;

typedef struct s_philo
{
	t_diner			*diners;
	uint64_t		start_time;
	int				diner_count;
	uint64_t		time_to_eat;
	uint64_t		time_to_die;
	uint64_t		time_to_sleep;
	int				times_must_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*chopstick_mutex_list;
	_Bool			unlimited;
	_Bool			diners_exit;
}				t_philo;

void		dsleep(uint64_t msecs, t_philo *philo);
void		print_state(char *str, t_diner *diner);
_Bool		init_philo(t_philo *philo, char **args);
void		init_diners(t_philo *philo);
void		free_philo(t_philo *philo);
void		*diner_loop(void *data);
void		start_diner_threads(t_philo *philo);
void		wait_diners(t_philo *philo);
void		monitor_loop(t_philo *philo);
_Bool		should_die(t_diner *diner);
uint64_t	now(void);

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *dst, int c, size_t len);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_isnumber(char *nbr);
int			ft_isspace(int c);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char n, int fd);
void		ft_putendl_fd(char *s, int fd);
#endif
