/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:53:52 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/29 12:24:15 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	choose_fork(t_philo *socrate, pthread_mutex_t	**f1, \
	pthread_mutex_t	**f2)
{
	if (socrate->name % 2 == 0)
	{
		*f1 = &(socrate->data->fork[socrate->name - 1]);
		*f2 = &(socrate->data->fork[socrate->name % socrate->data->nbr_philo]);
	}
	else
	{
		*f1 = &(socrate->data->fork[socrate->name % socrate->data->nbr_philo]);
		*f2 = &(socrate->data->fork[socrate->name - 1]);
	}
}

void	hungry(t_philo *socrate)
{
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;

	choose_fork(socrate, &f1, &f2);
	pthread_mutex_lock(f1);
	state_display(*socrate, FORK);
	pthread_mutex_lock(f2);
	state_display(*socrate, FORK);
	pthread_mutex_lock(&(socrate->write));
	socrate->last_eat = get_time();
	socrate->nbr_eat++;
	if (socrate->nbr_eat == socrate->data->nbr_eat)
		socrate->filled = true;
	pthread_mutex_unlock(&(socrate->write));
	state_display(*socrate, EAT);
	passtime(socrate->data->eat_time);
	pthread_mutex_unlock(f1);
	pthread_mutex_unlock(f2);
}

void	working(t_philo *socrate)
{
	state_display(*socrate, SLEEP);
	passtime(socrate->data->sleep_time);
	state_display(*socrate, THINK);
}

void	*routine(void *philo)
{
	t_philo			*socrate;
	sig_atomic_t	dead;

	dead = false;
	socrate = (t_philo *)philo;
	while (dead == false)
	{
		if (socrate->filled == false)
		{
			hungry(socrate);
			working(socrate);
		}
		pthread_mutex_lock(&(socrate)->data->read);
		dead = socrate->data->dead;
		pthread_mutex_unlock(&(socrate)->data->read);
	}
	return (NULL);
}

void	*lonely_routine(void *philo)
{
	t_philo	*socrate;

	socrate = (t_philo *)philo;
	state_display(*socrate, FORK);
	state_display(*socrate, SLEEP);
	state_display(*socrate, DIE);
	return (NULL);
}
