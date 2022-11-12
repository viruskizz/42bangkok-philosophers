#include "philo.h"

int	is_died(t_dinner dinner);
int	is_full(t_dinner dinner);

void *observer(void *arguments)
{
	t_dinner	dinner;

	dinner = *(t_dinner *) arguments;
	while (1)
	{
		if (is_died(dinner))
			return (NULL);
		else if (is_full(dinner))
			return (NULL);
	}
	return (NULL);
}

int	is_died(t_dinner dinner)
{
	int	i;
	t_philo	*philo;

	i = 1;
	philo = dinner.philos;
	while (i <= dinner.data.n)
	{
		if (philo->status == S_DIED)
		{
			ph_print(philo);
			return (1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}


int	is_full(t_dinner dinner)
{
	int	i;
	t_philo	*philo;

	i = 1;
	philo = dinner.philos;
	if (dinner.data.unlimit)
		return (0);
	while (i <= dinner.data.n)
	{
		if (philo->count < dinner.data.m)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}
