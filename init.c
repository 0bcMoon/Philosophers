/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:34:08 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/25 15:21:19 by hibenouk         ###   ########.fr       */
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
		if (pthread_mutex_init(&(philo + idx)->time_mutex, NULL) != 0)
			return (free_thread_mutex(philo + idx, idx, NONE), NULL);
		if (pthread_mutex_init(&(philo + idx)->state_mutex, NULL) != 0)
			return (free_thread_mutex(philo + idx, idx, TIME), NULL);
		philo->data = data;
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
