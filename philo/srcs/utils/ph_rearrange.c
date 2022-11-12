#include "philo.h"

void	ph_rearrange(t_philo **philos)
{
	t_philo *philo;
	t_philo *nphilo;
	t_philo *lphilo;

	philo = *philos;
	printf("cur ph:\n");
	print_philo(philo);
	
	nphilo = philo->next;
	printf("next ph:\n");
	print_philo(nphilo);

	lphilo = ph_lstlast(philo);
	printf("last ph:\n");
	print_philo(lphilo);
	printf("lock: %p\n", &philo->mute);
	pthread_mutex_lock(&philo->mute);
	if (philo != nphilo)
	{
		printf("REARRANGE\n");
		// sleep(2);
		lphilo->next = nphilo;
	}
	else
	{
		lphilo = NULL;
	}
	printf("unlock: %p\n", &philo->mute);
	pthread_mutex_unlock(&philo->mute);
	printf("size = %d\n", ph_lstsize(lphilo));
	printf("=====\n");
	// ph_lstfree(philo);
}
