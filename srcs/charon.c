/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:44:57 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/28 21:06:52 by elaachac         ###   ########.fr       */
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
}