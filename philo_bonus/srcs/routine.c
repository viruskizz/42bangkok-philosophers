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
#include "philo_bonus.h"

static void	to_eat(t_data data, t_philo *philo);
static void	to_sleep(t_data data, t_philo *philo);
static void	to_think(t_data, t_philo *philo);
static int	is_live(t_data data, t_philo *philo);

void	routine(t_data data, int idx)
{
	t_philo	philo;

	philo.idx = idx;
	philo.count = 0;
	philo.status = S_THINK;
	data.t = gettimestamp(USEC);
	philo.time = getgametime(data, USEC);
	if (data.n == 1)
	{
		philo.status = S_DIED;
		usleep(data.ttd * 1000);
		ph_print(data, &philo);
		exit(0);
	}
	while (1)
	{
		sem_wait(data.semt);
		sem_wait(data.semt);
		to_eat(data, &philo);
		sem_post(data.semt);
		sem_post(data.semt);
		if (philo.status == S_DIED || philo.count == data.m)
		{
			ph_print(data, &philo);
			exit(0);
		}
		to_sleep(data, &philo);
		to_think(data, &philo);
	}
	exit(0);
}

static void	to_eat(t_data data, t_philo *philo)
{
	if (philo->status != S_THINK)
		return ;
	if (!is_live(data, philo))
		return ;
	philo->status = S_FORK;
	ph_print(data, philo);
	ph_print(data, philo);
	philo->status = S_EATING;
	ph_print(data, philo);
	usleep(data.tte * 1000);
	philo->count++;
}

static void	to_sleep(t_data data, t_philo *philo)
{
	if (philo->status != S_EATING)
		return ;
	philo->status = S_SLEEPING;
	philo->time = getgametime(data, USEC);
	ph_print(data, philo);
	usleep(data.tts * 1000);
}

static void	to_think(t_data data, t_philo *philo)
{
	if (philo->status != S_SLEEPING)
		return ;
	philo->status = S_THINK;
	ph_print(data, philo);
	usleep(5);
}

static int	is_live(t_data data, t_philo *philo)
{
	unsigned long int	ttl;
	unsigned long int	ttd;

	ttl = getgametime(data, USEC) - philo->time;
	ttd = data.ttd * 1000;
	if (ttl + data.tte * 1000 > ttd)
	{
		philo->status = S_DIED;
		return (0);
	}
	else
		return (1);
}
