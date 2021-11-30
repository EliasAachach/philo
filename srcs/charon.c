/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:44:57 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/30 14:15:34 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thanathos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
		pthread_join(data->philo[i++].thread, NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&(data->philo[i].write));
		pthread_mutex_destroy(&(data->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->read));
	free_struct(&data);
}

bool	check_eat(t_data	*data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&(data->philo[i].write));
		if (data->philo[i].nbr_eat < data->nbr_eat)
		{
			pthread_mutex_unlock(&(data->philo[i].write));
			return (false);
		}
		pthread_mutex_unlock(&(data->philo[i].write));
		i++;
	}
	return (true);
}

void	charon(t_data	*data)
{
	size_t	i;
	time_t	last_eat;

	i = 0;
	while (i < data->nbr_philo && data->nbr_philo != 1)
	{
		pthread_mutex_lock(&(data->philo[i].write));
		last_eat = data->philo[i].last_eat;
		pthread_mutex_unlock(&(data->philo[i].write));
		if ((get_time() - last_eat) > data->die_time)
		{
			state_display(data->philo[i], DIE);
			break ;
		}
		if (++i == data->nbr_philo)
		{
			i = 0;
			if (data->nbr_eat != -1 && check_eat(data) == true)
			{
				state_display(data->philo[i], ATE_ENOUGH);
				break ;
			}
		}
	}
	thanathos(data);
}
