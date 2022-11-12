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
#include "philo_bonus.h"

static int	validate(int argc, char *argv[]);
static int	setup(int argc, char *argv[], t_data *data);

// void	routine(t_data data)
// {
// 	int	i;

// 	i = 1;
// 	while (i < 10)
// 	{
// 		printf("x %d\n", getpid());
// 		sem_wait(data.semt);
// 		printf("Entered..\n");
// 		//critical section
// 		usleep(100);
// 		//signal
// 		printf("Just Exiting...\n");
// 		sem_post(data.semt);
// 		i++;
// 	}
// 	exit (1);
// }

int	main(int argc, char *argv[])
{
	t_data	data;
	pid_t	pid;
	int		*pids;

	int	i;
	int	n;
	int	stat;

	i = 0;
	printf("start\n");
	if (!!validate(argc, argv))
		return (0);
	setup(argc, argv, &data);
	pids = malloc(sizeof(int) * data.n);
	while (i < data.n)
	{
		pid = fork();
		if (pid == 0)
		{
			usleep(100);
			routine(data, i + 1);
			break;
		}
		else
		{
			printf("parent%d: %d/%d\n", i, pid, getpid());
			pids[i] = pid;
		}
		printf(">> %d\n", pid);
		i++;
	}
	waitpid(-1, &stat, 0);
	if (pid != 0 && WEXITSTATUS(stat) == 0)
	{
		i = 0;
		while (i < data.n)
		{
			kill(pids[i], SIGKILL);
			i++;
		}
		sem_close(data.semt);
		sem_close(data.semtp);
	}
	return (0);
}

static int	validate(int argc, char *argv[])
{
	if (argc < 5)
		return (printf("%sError: need at least 4 argument%s\n", LRED, RESET));
	if (ft_atoi(argv[1]) < 1
		|| ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 1
		|| ft_atoi(argv[4]) < 1)
		return (printf("%sError:invalid argument%s\n", LRED, RESET));
	if (argc > 5 && ft_atoi(argv[5]) <= 0)
		return (printf("%sError: times cannot less than 0%s\n", LRED, RESET));
	return (0);
}

static int	setup(int argc, char *argv[], t_data *data)
{
	data->n = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->t = gettimestamp(USEC);
	if (argc > 5 && ft_atoi(argv[5]))
		data->m = ft_atoi(argv[5]);
	else
		data->m = 0;
	sem_unlink("/araiva");
	sem_unlink("/araiva_print");
	data->semt = sem_open("/araiva", O_CREAT, S_IRUSR | S_IWUSR, data->n);
	data->semtp = sem_open("/araiva_print", O_CREAT, S_IRUSR | S_IWUSR, 1);
	return (0);
}
