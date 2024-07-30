/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:19:30 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/25 15:21:37 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"


int main(int ac,  char **argv) 
{
	t_data *data;
	t_philo *philo;
	if (ac < 5 || ac > 6)
		return (printf("Error: invalid number of argument\n"));
	data = parsing(argv);
	if (!data)
		return (1);
	philo = init_mutex(data);
	perror("Error");
}

