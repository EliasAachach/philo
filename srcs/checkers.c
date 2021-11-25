/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:49:27 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/25 14:12:14 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd(2, "Wrong number of arguments. Follow this path->\n\
./philo <number_of_philoshophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_time_each_philo_must_eat].\n");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i]) == false)
		{
			ft_putstr_fd(2, "Wrong arguments :\n\
arguments must be digits only.\n");
			return (false);
		}
		i++;
	}
	return (true);
}
