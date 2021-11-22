/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:16:46 by elaachac          #+#    #+#             */
/*   Updated: 2021/11/22 19:24:37 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_philo
{
	size_t			name;
	ssize_t			nbr_eat;
	time_t			last_eat;
	bool			filled;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	write;	
};

struct s_data
{
	size_t			nbr_philo;
	time_t			die_time;
	time_t			eat_time;
	time_t			sleep_time;
	ssize_t			nbr_eat;
	bool			dead;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	aff;
};

int		ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
bool	check_args(int argc, char **argv);
bool	ft_isdigit(char *str);
int		ft_strlen(char *str);

#endif
