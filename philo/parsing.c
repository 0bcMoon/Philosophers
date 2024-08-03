/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:06:07 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/31 13:40:44 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\v' || c == '\t'
		|| c == '\f');
}

static int	ft_atoi(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
		if (res > INT_MAX)
			return (-1);
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	return (res);
}

t_data	*parsing(char **argv)
{
	t_data *data;

// TODO : make better parsing
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Error : could not alloc\n"), NULL);
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->eat_count = ft_atoi(argv[5]);
	else
		data->eat_count = LONG_MAX;
	if (data->eat_count < 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| data->count <= 0)
		return (printf("Error : invalid data\n"), free(data), NULL);
	data->running = 1;
	return (data);
}
