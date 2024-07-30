/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:54:16 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 13:12:45 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

static void eating(t_philo *philo)
{
	print_state(philo, EAT);
	custom_sleep(philo->data->time_to_eat);
}

static void sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	custom_sleep(philo->data->time_to_sleep);
}

static void thinking(t_philo *philo)
{
	print_state(philo, THINK);
}

void manger(t_philo *philo)
{
	printf("TODO");
	abort();
}
void *routine(void *param)
{
	t_philo *philo;

	philo = param;
	while (philo->data->running)
	{
		take_forks(philo);
		eating(philo);
		put_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
