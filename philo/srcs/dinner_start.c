#include "philo.h"

void	start_order(t_philo *philo, t_dinner dinner, int order);

void	dinner_start(t_dinner dinner, t_philo **philos)
{
	t_philo	*tmp;
	t_data	data;

	if (!*philos)
		return ;
	pthread_create(&dinner.tid, NULL, &observer, &dinner);
	start_order(*philos, dinner, ODD);
	// usleep(200);
	start_order(*philos, dinner, EVEN);
	pthread_join(dinner.tid, NULL);
}

void	start_order(t_philo *philo, t_dinner dinner, int order)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	tmp = philo;
	while (i <= dinner.data.n)
	{
		if (i % 2 == order)
		{
			pthread_create(&philo->tid, NULL, &routine, philo);
			pthread_detach(philo->tid);
		}
		philo = philo->next;
		i++;
	}
}
