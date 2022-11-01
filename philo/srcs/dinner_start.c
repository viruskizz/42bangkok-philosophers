#include "philo.h"

void	dinner_start(t_philo **philos)
{
	t_philo	*tmp;
	t_data	data;

	if (!*philos)
		return ;
	tmp = *philos;
	while (tmp && tmp->next != *philos)
	{
		pthread_create(&tmp->tid, NULL, &routine, tmp);
		tmp = tmp->next;
	}
	pthread_create(&tmp->tid, NULL, &routine, tmp);
	tmp = *philos;
	while (tmp && tmp->next != *philos)
	{
		pthread_join(tmp->tid, NULL);
		tmp = tmp->next;
	}
	pthread_join(tmp->tid, NULL);
}
