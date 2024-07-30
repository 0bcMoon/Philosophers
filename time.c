/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:17:44 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 12:28:52 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000L) + (tp.tv_usec / 1000));
}

/*
 * tts : time to sleep
 */
void	custom_sleep(long tts)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < tts)
		usleep(50);
}
