#include "philo.h"

void *routine(void *arguments)
{
	t_philo	*philo;
	t_data	data;
	int		count;
	int		max;
	int		rt;
	int		ttl;

	philo = ((t_philo *) arguments);
	data = philo->data;
	ttl = data.ttd - data.tte - data.tts;
	max = data.m;
	count = 0;
	while (count < max)
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
			// if (ttl < 0)
			// {
			// 	philo->status = S_DIED;
			// 	stat_philo(philo);
			// 	break;
			// }
			// else
			// {
			// 	stat_philo(philo);
			// 	usleep(rt);
			// 	philo->status = S_EATING;
			// }
		}
	}
	return (NULL);
}
