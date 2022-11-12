#include "philo.h"

static char	*get_stat_title(int	stat);

void	ph_print(t_philo *philo)
{
	unsigned long int	time;
	int	stat;

	time = getgametime(philo->data, MSEC);
	stat = philo->status;
	if (stat == S_FORK)
		printf("%ld %d has taken a fork\n", time, philo->idx);
	else if (stat == S_EATING)
		printf("%ld %d is eating\n", time, philo->idx);
	else if (stat == S_SLEEPING)
		printf("%s%ld %d is sleeping%s\n", GREEN, time, philo->idx, RESET);
	else if (stat == S_THINK)
		printf("%ld %d is thinking\n", time, philo->idx);
	else if (stat == S_DIED)
		printf("%ld %d died\n", time, philo->idx);
	else
		printf("%ld %d ??\n", time, philo->idx);
}

static char	*get_stat_title(int	stat)
{
	if (stat == S_FORK)
		return ("has taken a fork");
	if (stat == S_EATING)
		return ("is eating");
	else if (stat == S_SLEEPING)
		return ("is sleeping");
	else if (stat == S_THINK)
		return ("is thinking");
	else if (stat == S_DIED)
		return ("died");
	else
		return ("??");
}