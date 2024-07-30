/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:34:31 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 15:27:27 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

static void manger(t_philo *philo)
{
	int idx;
	long curr_time;
	int flag;

	flag = 1;
	while (flag)
	{
		idx = 0;
		curr_time = get_time_ms();
		while (idx < philo->data->count)
		{
			if (curr_time - eat_time(philo + idx, GET) >= philo->data->time_to_die)
			{
				table_status(philo, STOP);
				flag = 0;
				print_state(philo + idx, DIE);
				usleep(500);
				printf("%ld %d %s\n", time_now(philo), philo->id, DIE);
				break;
			}
			idx++;
		}
	}
}

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
	manger(philo);
	idx = 0;
	while (idx < philo->data->count)
		pthread_join(philo[idx++].thread, NULL);
	return (0);
}
