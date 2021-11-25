/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:48:00 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/25 17:25:05 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_mng(t_philo philo, t_state state)
{
	if (philo.data->dead == false && state == FORK)
	{
		printf("At %ld : Philosopher %zu has taken a fork.\n", get_time(), \
				philo.name);
		//prend une fourchette
	}
	else if (philo.data->dead == false && state == EAT)
	{
		//mange
	}
	else if (philo.data->dead == false && state == SLEEP)
	{
		//dors
	}
	else if (philo.data->dead == false && state == THINK)
	{
		//pense
	}
	else if (philo.data->dead == false && state == DIE)
	{
		//meurt
	}
	else if (philo.data->dead == false && state == ATE_ENOUGH)
	{
		//assez manger (nbr_eat atteint)
	}
}
