#include "philo.h"

static t_philo	*create_philo(int idx, t_data data);
static void		ph_lstadd(t_philo **philo, t_philo *new);

void	dinner_create(t_philo **philos, t_data data)
{
	int		i;
	t_philo *philo;

	i = 0;
	while (i < data.n)
	{
		philo = create_philo(i, data);
		ph_lstadd(philos, philo);
		i++;
	}
}

static t_philo	*create_philo(int idx, t_data data)
{
	t_philo			*philo;
	pthread_t		tid;
	pthread_mutex_t mute;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->idx = idx + 1;
	philo->tid = tid;
	philo->data = data;
	philo->next = philo;
	pthread_mutex_init(&philo->mute, NULL);
	return (philo);
}

static void	ph_lstadd(t_philo **philo, t_philo *new)
{
	t_philo	*tmp;

	if (!*philo)
		*philo = new;
	else
	{
		tmp = *philo;
		while (tmp->next != *philo)
			tmp = tmp->next;
		tmp->next = new;
		new->next = *philo;
	}
}
