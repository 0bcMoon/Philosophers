/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:22:06 by hibenouk          #+#    #+#             */
/*   Updated: 2024/07/30 11:45:23 by hibenouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EMUTEX "An error occurred when init mutex"
# define EAT "has taken a fork"
# define TFORK "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
enum				e_flag
{
	NONE = 0b0,
	WRITE = 0b1,
	STOP = 0b10,
	TIME = 0b100,
	STATE = 0b1000,
};

enum				e_state
{
	DIED = 0b10000,
	FULL = 0b100000,
	LIFE = 0b1000000,
};

typedef struct s_data
{
	int				running;
	int				count;
	int				eat_count;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			time_to_die;
	time_t			philo_start;
	time_t			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	stop_mutex;

}					t_data;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				nb_time_eat;
	t_data			*data;
	enum e_state	state;
	pthread_t		thread;
	time_t			last_meal_time;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	time_mutex;
}					t_philo;

void				free_mutex(t_data *data, int count, enum e_flag flag);
void				free_thread_mutex(t_philo *philo, int count,
						enum e_flag flag);

t_data				*parsing(char **argv);
t_philo				*init_mutex(t_data *data);
int					started_philosophy(t_philo *philo);
void				*routine(void *prama);
long				get_time_ms(void);
void				print_state(t_philo *philo, const char *state);
void				custom_sleep(long tts);
void				put_forks(t_philo *philo);
void				take_forks(t_philo *philo);

#endif // !PHILO_H
