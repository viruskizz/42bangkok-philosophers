#include "philo.h"

t_philo	*ph_lstlast(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp && tmp->next != philo)
		tmp = tmp->next;
	return (tmp);
}
