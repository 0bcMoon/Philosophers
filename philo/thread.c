/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:34:31 by hibenouk          #+#    #+#             */
/*   Updated: 2024/08/03 15:31:37 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	announce_death(t_philo *philo)
{
	table_status(philo, STOP);
	printf("%ld %d %s\n", time_now(philo), philo->id, DIE);
	return (0);
}

static int	manger(t_philo *philo)
{
	int		idx;
	long	curr_time;
	int		meal_count;

	while (1)
	{
		idx = 0;
		curr_time = get_time_ms();
		meal_count = 0;
		while (idx < philo->data->count)
		{
			if (curr_time - eat_time(philo + idx,
					GET) >= philo->data->time_to_die)
				return (announce_death(philo + idx));
			else if (eat_count(philo + idx, GET) >= philo->data->eat_count)
				meal_count++;
			idx++;
		}
		if (meal_count == philo->data->count)
			return (table_status(philo, STOP));
	}
}

static void	wait_thread(t_philo *philo)
{
	int	idx;

	manger(philo);
	idx = 0;
	while (idx < philo->data->count)
		pthread_join(philo[idx++].thread, NULL);
	clean_thread(philo);
}

int	started_philosophy(t_philo *philo)
{
	int		idx;
	long	start;

	start = get_time_ms();
	philo->data->start = start;
	idx = 0;
	while (idx < philo->data->count)
	{
		philo[idx].last_meal_time = start;
		if (pthread_create(&philo[idx].thread, NULL, routine, &philo[idx]) != 0)
			return (clean_thread(philo), 1);
		idx += 2;
	}
	idx = 1;
	while (idx < philo->data->count)
	{
		philo[idx].last_meal_time = start;
		if (pthread_create(&philo[idx].thread, NULL, routine, &philo[idx]) != 0)
			return (clean_thread(philo), 1);
		idx += 2;
	}
	wait_thread(philo);
	return (0);
}
