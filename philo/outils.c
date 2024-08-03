/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:22:21 by hibenouk          #+#    #+#             */
/*   Updated: 2024/08/03 11:21:33 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (table_status(philo, GET) != 0)
		printf("%ld %d %s\n", time_now(philo), philo->id, state);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	print_state(philo, TFORK);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	print_state(philo, TFORK);
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

int	table_status(t_philo *philo, enum e_flag opt)
{
	int	status;

	pthread_mutex_lock(&philo->data->stop_mutex);
	if (opt == STOP)
		philo->data->running = 0;
	status = philo->data->running;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (status);
}
