/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:03:33 by hibenouk          #+#    #+#             */
/*   Updated: 2024/08/03 15:31:45 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_data *data, int count, enum e_flag flag)
{
	int	idx;

	idx = 0;
	while (idx < count)
		pthread_mutex_destroy(data->forks + idx++);
	free(data->forks);
	if ((flag >> 0) & 1)
		pthread_mutex_destroy(&data->write_mutex);
	if ((flag >> 1) & 1)
		pthread_mutex_destroy(&data->stop_mutex);
}

void	free_thread_mutex(t_philo *philo, int count, enum e_flag flag)
{
	int	idx;

	idx = 0;
	while (idx < count)
	{
		pthread_mutex_destroy(&(philo + idx)->time_mutex);
		pthread_mutex_destroy(&(philo + idx)->state_mutex);
		idx++;
	}
	if ((flag >> 2) & 1)
		pthread_mutex_destroy(&(philo + idx)->time_mutex);
	if ((flag >> 3) & 1)
		pthread_mutex_destroy(&(philo + idx)->state_mutex);
}

void	clean_thread(t_philo *philo)
{
	table_status(philo, STOP);
	free_thread_mutex(philo, philo->data->count, TIME | STATE);
	free_mutex(philo->data, philo->data->count, WRITE | STOP);
	free(philo->data);
	free(philo);
}
