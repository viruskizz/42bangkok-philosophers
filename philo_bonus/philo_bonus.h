#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
#include  <string.h>
#include  <sys/types.h>
# include <sys/time.h>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

# define S_SLEEPING	0
# define S_THINK	1
# define S_FORK		2
# define S_EATING	3
# define S_DIED		9
# define USEC		0
# define MSEC		1

typedef struct s_data
{
	int					n;
	int					ttd;
	int					tte;
	int					tts;
	int					m;
	int					unlimit;
	int					is_end;
	unsigned long int	t;
}	t_data;

typedef struct s_philo
{
	int				idx;
	int				time;
	int				status;
	int				count;
	t_data			data;
	struct s_philo	*next;
}	t_philo;

typedef struct s_dinner
{
	t_data				data;
	unsigned long int	time;
	t_philo				*philos;
}	t_dinner;


/* Utilities */
int		ft_atoi(const char *nb);
unsigned long int	gettimestamp(int unit);
unsigned long int	getgametime(t_data data, int unit);

#endif
