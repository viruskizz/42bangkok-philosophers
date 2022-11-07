#include "philo.h"

int	to_eat(t_philo *philo);

void *routine(void *arguments)
{
	t_philo	*philo;
	t_data	data;
	int		count;
	int		max;
	int		rt;
	int		ttl;
	int		unlimit;

	philo = ((t_philo *) arguments);
	data = philo->data;
	ttl = data.ttd - data.tte - data.tts;
	max = data.m;
	count = 0;
	while (count < max || data.unlimit)
	{
		if (philo->status == S_SLEEPING)
		{
			stat_philo(philo);
			usleep(philo->data.tts * 1000);
			philo->status = S_THINK;
		}
		else if (philo->status == S_EATING)
		{
			stat_philo(philo);
			usleep(philo->data.tte * 1000);
			count++;
			philo->status = S_SLEEPING;
		}
		else
		{
			rt = rand() % ttl;
			stat_philo(philo);
			usleep(rt);
			philo->status = S_EATING;
		}
	}
	return (NULL);
}

int	to_eat(t_philo *philo)
{
	
	return (0);
}
