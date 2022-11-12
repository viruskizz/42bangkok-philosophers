#include "philo.h"

int	ph_lstsize(t_philo *philo)
{
	int	size;
	t_philo	*tmp;

	if (!philo)
		return (0);
	size = 0;
	tmp = philo;
	while (tmp && tmp->next != philo && ++size)
		tmp = tmp->next;
	return (size + 1);
}
