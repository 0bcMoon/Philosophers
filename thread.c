/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:34:31 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 11:09:40 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

int started_philosophy(t_philo *philo)
{
	int idx;
	long start;

	idx = 0;
	start = get_time_ms();
	philo->data->start = start;
	while (idx < philo->data->count)
	{
		philo[idx].last_meal_time = start;
		pthread_create(&philo[idx].thread, NULL, routine, &philo[idx]);
		idx++;
	}
	idx = 0;
	while (idx < philo->data->count)
		pthread_join(philo[idx].thread, NULL);
	return (0);
}
