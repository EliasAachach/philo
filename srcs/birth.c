/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:35 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/22 19:24:44 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data **data)
{
	size_t	i;

	(*data)->philo = malloc(sizeof(t_philo) * ((*data)->nbr_philo));
	(*data)->fork = malloc(sizeof(pthread_mutex_t) * ((*data)->nbr_philo));
	if ((*data)->philo == NULL || (*data)->fork == NULL)
		return ;
	(*data)->dead = false;
	i = 0;
	memset((*data)->philo, '\0', sizeof(t_philo) * ((*data)->nbr_philo));
	while (i < (*data)->nbr_philo)
	{
		(*data)->philo[i].name = i + 1;
		(*data)->philo[i].data = (*data);
		(*data)->philo[i].last_eat = 0;
		(*data)->philo[i].filled = false;
		pthread_mutex_init(&((*data)->fork[i]), NULL);
		pthread_mutex_init(&((*data)->philo[i].write), NULL);
		i++;
	}
}

void	birth(t_data **data)
{
	size_t	i;

	i = 0;
	init_philo(&data);
}
