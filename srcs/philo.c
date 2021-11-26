/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:15:07 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/26 12:35:42 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_data **data)
{
	if ((*data)->philo)
		free((*data)->philo);
	if ((*data)->fork)
		free((*data)->fork);
	if (*data)
		free(*data);
}

void	init_data(t_data **data, int argc, char **argv)
{
	(*data)->nbr_philo = atoi(argv[1]);
	(*data)->die_time = atoi(argv[2]);
	(*data)->eat_time = atoi(argv[3]);
	(*data)->sleep_time = atoi(argv[4]);
	if (argc == 6)
		(*data)->nbr_eat = atoi(argv[5]);
	else
		(*data)->nbr_eat = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv) == true)
	{
		data = malloc(sizeof(t_data));
		memset(data, '\0', sizeof(t_data));
		init_data(&data, argc, argv);
		birth(data);
		free_struct(&data);
	}
	else
		return (1);
}
