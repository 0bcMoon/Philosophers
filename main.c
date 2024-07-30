/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:19:30 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 11:12:25 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac,  char **argv) 
{
	t_data *data;
	t_philo *philo;

	if (ac < 5 || ac > 6)
		return (printf("Error: invalid number of argument\n"), 1);
	data = parsing(argv);
	if (!data)
		return (1);
	philo = init_mutex(data);
	if (!philo)
		return (printf("%s", EMUTEX), 1);
	started_philosophy(philo);
}

