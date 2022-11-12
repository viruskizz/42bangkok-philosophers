/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:28:06 by araiva            #+#    #+#             */
/*   Updated: 2022/10/03 18:28:07 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	setup(int argc, char *argv[], t_data *data);
static void	setup_dinner(t_dinner *dinner, t_data data);
static void	setup_print(t_data data);

int	main(int argc, char *argv[])
{
	t_data		data;
	t_dinner	dinner;
	t_philo		*philos;

	int	i;

	philos = NULL;
	if (!!setup(argc, argv, &data))
		return (0);
	setup_dinner(&dinner, data);
	dinner_create(&philos, data);
	dinner.philos = philos;
	dinner_start(dinner, &philos);
	return (0);
}

static int	setup(int argc, char *argv[], t_data *data)
{
	if (argc < 5)
		return (printf("%sError: need at least 4 argument%s\n", LRED, RESET));
	data->n = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->t = gettimestamp(USEC);
	if (argc > 5 && ft_atoi(argv[5]))
	{
		data->m = ft_atoi(argv[5]);
		data->unlimit = 0;
	}
	else
	{
		data->m = 0;
		data->unlimit = 1;
	}
	data->is_end = 0;
	if (data->n < 1 || data->m < 0 || data->ttd < 1 || data->tte < 1 || data->tts < 1)
		return (printf("%sError:invalid argument%s\n", LRED, RESET));
	return (0);
}

static void	setup_dinner(t_dinner *dinner, t_data data)
{
	pthread_t		tid;
	pthread_mutex_t mute;

	dinner->tid = tid;
	dinner->data = data;
	dinner->time = gettimestamp(USEC);
	pthread_mutex_init(&dinner->mute, NULL);
}

static void	setup_print(t_data data)
{
	printf("%sPhisophers programe%s\n", YELLOW, RESET);
	printf("• number_of_philosophers: %d ea\n", data.n);
	printf("• time_to_die: %d ms\n", data.ttd);
	printf("• time_to_eat: %d ms\n", data.tte);
	printf("• time_to_sleep: %d ms\n", data.tts);
	printf("• number_of_times_each_philosopher_must_eat: %d times\n", data.m);
	printf("• unlimit: %d\n", data.unlimit);
	printf("%s=====================%s\n", YELLOW, RESET);
}