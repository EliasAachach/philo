/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:53:52 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/26 12:52:46 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*socrate;

	socrate = (t_philo *)philo;
	// tant que pas mort -> manger/penser/dormir
	return (NULL);
}

void	*lonely_routine(void *philo)
{
	t_philo	*socrate;

	socrate = (t_philo *)philo;
	state_mng(*socrate, FORK);
	state_mng(*socrate, SLEEP);
	//DORMIR(jusqu'a socrate->data->die_time)
	state_mng(*socrate, DIE);
	//MOURIR
	return (NULL);
}
