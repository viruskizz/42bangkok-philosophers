/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:42:41 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:42:42 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	to_eat(t_philo *philo);
static void	to_sleep(t_philo *philo);
static void	to_think(t_philo *philo);
static int	is_live(t_philo *philo);

void	*routine(void *arguments)
{
	t_philo	*philo;
	t_data	data;

	philo = ((t_philo *) arguments);
	data = philo->data;
	if (philo->next == philo)
		philo->status = S_DIED;
	while (1)
	{
		pthread_mutex_lock(&philo->mute);
		to_eat(philo);
		pthread_mutex_unlock(&philo->mute);
		if (philo->status == S_DIED || philo->count == data.m)
			return (NULL);
		to_sleep(philo);
		to_think(philo);
	}
	return (NULL);
}

static void	to_eat(t_philo *philo)
{
	if (philo->status != S_THINK)
		return ;
	if (!is_live(philo))
		return ;
	pthread_mutex_lock(&philo->next->mute);
	philo->status = S_FORK;
	ph_print(philo);
	philo->status = S_EATING;
	ph_print(philo);
	usleep(philo->data.tte * 1000);
	philo->count++;
	pthread_mutex_unlock(&philo->next->mute);
}

static void	to_sleep(t_philo *philo)
{
	if (philo->status != S_EATING)
		return ;
	philo->status = S_SLEEPING;
	philo->time = getgametime(philo->data, USEC);
	ph_print(philo);
	usleep(philo->data.tts * 1000);
}

static void	to_think(t_philo *philo)
{
	if (philo->status != S_SLEEPING)
		return ;
	philo->status = S_THINK;
	ph_print(philo);
	if (philo->next == philo)
		philo->status = S_DIED;
}

static int	is_live(t_philo *philo)
{
	unsigned long int	ttl;
	unsigned long int	ttd;

	ttl = getgametime(philo->data, USEC) - philo->time;
	ttd = philo->data.ttd * 1000;
	if (ttl + philo->data.tte * 1000 > ttd)
	{
		philo->status = S_DIED;
		return (0);
	}
	else
		return (1);
}
