/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:38 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 14:36:35 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

long eat_time(t_philo *philo, enum e_flag opt)
{
	long time;

	pthread_mutex_lock(&philo->time_mutex);
	if (opt == SET)
		philo->last_meal_time = get_time_ms();
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mutex);
	return (time);
}
