/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timelord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:05:36 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/26 15:58:51 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	passtime(time_t time_to_pass)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < time_to_pass)
		usleep(3);
}

time_t	instant_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

time_t	get_time(void)
{
	static time_t	start_time = 0;

	if (start_time == 0)
	{
		start_time = instant_time();
		return (0);
	}
	return (instant_time() - start_time);
}
