/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:34:08 by hibenouk          #+#    #+#             */
/*   Updated: 2024/08/03 11:21:22 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_data *data)
{
	int	idx;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (1);
	idx = 0;
	while (idx < data->count)
	{
		if (pthread_mutex_init(data->forks + idx, NULL) != 0)
			return (free_mutex(data, idx, NONE), 1);
		idx++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
		return (free_mutex(data, data->count, NONE), 1);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (free_mutex(data, data->count, WRITE), 1);
	return (0);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_philo	*init_thread(t_data *data)
{
	t_philo	*philo;
	int		idx;

	philo = malloc(sizeof(t_philo) * data->count);
	if (!philo)
		return (NULL);
	idx = 0;
	while (idx < data->count)
	{
		philo[idx].id = (idx + 1);
		philo[idx].l_fork = (idx);
		philo[idx].r_fork = (idx + 1) % data->count;
		if (idx & 1)
			ft_swap(&philo[idx].l_fork, &philo[idx].r_fork);
		if (pthread_mutex_init(&philo[idx].time_mutex, NULL) != 0)
			return (free_thread_mutex(philo + idx, idx, NONE), NULL);
		if (pthread_mutex_init(&philo[idx].state_mutex, NULL) != 0)
			return (free_thread_mutex(philo + idx, idx, TIME), NULL);
		philo[idx].data = data;
		philo[idx].eat_count = 0;
		idx++;
	}
	return (philo);
}

t_philo	*init_mutex(t_data *data)
{
	t_philo	*philo;

	if (init_fork(data))
		return (NULL);
	philo = init_thread(data);
	if (!philo)
		return (free_mutex(data, data->count, WRITE | STOP), NULL);
	return (philo);
}
