SRCS			=	\
					diner_loop.c			\
					dsleep.c				\
					free_philo.c			\
					ft_atoi.c				\
					ft_calloc.c				\
					ft_isdigit.c			\
					ft_memset.c				\
					init_diners.c			\
					init_philo.c			\
					main.c					\
					monitor_loop.c			\
					now.c					\
					print_state.c			\
					start_diner_threads.c	\
					should_die.c			\
					wait_diners.c

SRCS		   := $(addprefix $(SRC_PATH), $(SRCS))
