/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:22:21 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 12:14:32 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%ld %d %s\n", get_time_ms() - philo->data->start, philo->id, state);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	print_state(philo, TFORK);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	print_state(philo, TFORK);
}

void put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}
