/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:00 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/30 14:30:16 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_display(t_philo philo, t_state state)
{
	pthread_mutex_lock(&(philo.data->read));
	if (philo.data->dead == false && state == FORK)
		printf("%ld %zu has taken a fork\n", get_time(), philo.name);
	else if (philo.data->dead == false && state == EAT)
		printf("%ld %zu is eating\n", get_time(), philo.name);
	else if (philo.data->dead == false && state == SLEEP)
		printf("%ld %zu is sleeping\n", get_time(), philo.name);
	else if (philo.data->dead == false && state == THINK)
		printf("%ld %zu is thinking\n", get_time(), philo.name);
	else if (philo.data->dead == false && state == DIE)
	{
		philo.data->dead = true;
		printf("%ld %zu died\n", get_time(), philo.name);
	}
	else if (philo.data->dead == false && state == ATE_ENOUGH)
	{
		philo.data->dead = true;
		printf("All philosophers ate enough.");
	}
	pthread_mutex_unlock(&(philo.data->read));
}
