/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliasaachach <eliasaachach@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:15:07 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/22 18:49:00 by eliasaachac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data **data, int argc, char **argv)
{
	(*data)->nbr_philo = atoi(argv[1]);
	(*data)->die_time = atoi(argv[2]);
	(*data)->nbr_philo = atoi(argv[3]);
	(*data)->nbr_philo = atoi(argv[4]);
	if (argc == 6)
		(*data)->nbr_philo = atoi(argv[5]);
	else
		(*data)->nbr_philo = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv) == true)
	{
		ft_putstr_fd(2, "entree\n");
		data = malloc(sizeof(t_data));
		ft_putstr_fd(2, "malloc ok\n");
		memset(data, '\0', sizeof(t_data));
		ft_putstr_fd(2, "memset ok\n");
		init_data(&data, argc, argv);
		ft_putstr_fd(2, "init ok\n");
		birth(&data);
	}
	else
		return (1);
}
