/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:58:23 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:58:24 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_print(t_philo *philo)
{
	unsigned long int	time;
	int					stat;

	time = getgametime(philo->data, MSEC);
	stat = philo->status;
	if (stat == S_FORK)
		printf("%ld %d has taken a fork\n", time, philo->idx);
	else if (stat == S_EATING)
		printf("%ld %d is eating\n", time, philo->idx);
	else if (stat == S_SLEEPING)
		printf("%s%ld %d is sleeping%s\n", GREEN, time, philo->idx, RESET);
	else if (stat == S_THINK)
		printf("%ld %d is thinking\n", time, philo->idx);
	else if (stat == S_DIED)
		printf("%ld %d died\n", time, philo->idx);
	else
		printf("%ld %d ??\n", time, philo->idx);
}
