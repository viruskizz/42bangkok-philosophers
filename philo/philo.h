#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

# define S_SLEEPING	0
# define S_THINK	1
# define S_EATING	2
# define S_DIED		9
# define USEC		0
# define MSEC		1

/**
 * @brief programe data struct
 * n	number_of_philosophers
 * ttd	time_to_die
 * tte	time_to_eat
 * tts	time_to_sleep
 * m	number_of_times_each_philosopher_must_eat
 */
typedef struct s_data
{
	int			n;
	int			ttd;
	int			tte;
	int			tts;
	int			m;
	unsigned long int	t;
}	t_data;

typedef struct s_philo
{
	pthread_t		tid;
	t_data			data;
	int				idx;
	int				time;
	int				status;
	struct s_philo	*next;
}	t_philo;


/* Utilities */
int	ft_atoi(const char *nb);
unsigned long int	gettimestamp(int unit);
unsigned long int	getgametime(t_data data, int unit);

// main
void	*routine(void *arguments);
void	dinner_create(t_philo **philos, t_data data);
void	dinner_start(t_philo **philos);

// debug
void	print_dinner(t_philo **philo);
void	print_philo(t_philo *philo);
void	stat_philo(t_philo *philo);
#endif
