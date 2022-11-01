#include "philo.h"

unsigned long int	gettimestamp(int unit)
{
	struct timeval now;
	int	rc;
	long int	timestamp;

	rc = gettimeofday(&now, NULL);
	if (rc < 0)
		return (-1);
	timestamp = now.tv_sec * 1000000 + now.tv_usec;
	if (unit == USEC)
		return (timestamp);
	else
		return (timestamp / 1000);
}

unsigned long int	getgametime(t_data data, int unit)
{
	unsigned long int curtime;

	curtime = gettimestamp(USEC) - data.t;
	if (unit == USEC)
		return (curtime);
	else
		return (curtime / 1000);
}