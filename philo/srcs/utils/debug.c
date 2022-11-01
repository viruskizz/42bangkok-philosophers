#include "philo.h"

char	*get_stat_title(int	stat)
{
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

void	print_philo(t_philo *philo)
{
	printf("idx: %d\n", philo->idx);
	printf("ptr: %p\n", philo);
}

void	stat_philo(t_philo *philo)
{
	
	printf("%ld %d %s\n", getgametime(philo->data, MSEC), philo->idx,  get_stat_title(philo->status));
}

void	print_dinner(t_philo **philo)
{
	t_philo	*tmp;

	tmp = *philo;
	while (tmp && tmp->next != *philo)
	{
		print_philo(tmp);
		tmp = tmp->next;
	}
	print_philo(tmp);
}
