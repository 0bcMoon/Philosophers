/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:19:30 by hibenouk          #+#    #+#             */
/*   Updated: 2024/08/03 12:18:37 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

int	main(int ac, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	// atexit(leaks);
	if (ac < 5 || ac > 6)
		return (printf("Error: invalid number of argument\n"), 1);
	data = parsing(argv);
	if (!data)
		return (1);
	else if (data->eat_count == 0)
		return (free(data), 0);
	philo = init_mutex(data);
	if (!philo)
		return (printf("%s", EMUTEX), 1);
	if (started_philosophy(philo))
		return (printf("%s", ETHREAD), 1);
}
