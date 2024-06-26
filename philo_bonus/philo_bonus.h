/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahlee <hahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:31:21 by hahlee            #+#    #+#             */
/*   Updated: 2023/03/21 20:00:50 by hahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

# define INT_MAX 2147483647
# define LEFT 0
# define RIGHT 1
# define UNLOCK 0
# define LOCK 1
# define DIE 0
# define LIVE 1
# define START 0
# define RECENT 1
# define FALSE 0
# define TRUE 1
# define NUM_PHILO 0
# define TIME_DIE 1
# define TIME_EAT 2
# define TIME_SLEEP 3
# define MUST_EAT 4
# define PROCESS 5
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define C_NRML "\033[0m"
# define C_GREN "\033[32m"
# define C_YLLW "\033[33m"
# define C_BLUE "\033[34m"
# define C_RED "\033[31m"

typedef struct timeval	t_time;

// typedef struct s_philo
// {
// 	int			id;
// 	int			*argv;
// 	t_time		*start_time;
// 	t_eat		eat_info;
// 	t_time		recent_time;
// }	t_philo;

typedef struct s_table
{
	int			id;
	int			argv[6];
	sem_t		*forks;
	sem_t		*eat_enough;
	sem_t		*print;
	t_time		start_time;
	t_time		recent_time;
}	t_table;

/* init_struct */
int		init_argv(int argc, char *src[], int argv[][6], int j);
void	init_table(t_table *table);

/* process.c */
int		create_process(t_table *table, pid_t **pid);
int		create_eat_monitoring(t_table *table, pid_t **pid);
int		kill_process(t_table *table, pid_t **pid);
int		close_sem(t_table *table);

/* do_action.c */
int		do_action(t_table *table);
int		do_think(t_table *table);
int		do_eat(t_table *table, int *eat_count);
void	add_eat_count(t_table *table, int *eat_count);
int		do_sleep(t_table *table);

/* do_action2.c */
int		pick_up_fork(t_table *table);
int		lock_the_fork(t_table *table);
void	spend_time_when_alone(t_table *table);
int		put_down_fork(t_table *table);
int		unlock_the_fork(t_table *table);

/* check_state.c */
void	check_die(t_table *table, pid_t **pid);
int		check_eat_enough(t_table *table);

/* check_state2.c */
int		am_i_die(t_table *table);
int		msleep(int ms);
long	get_time_diff(t_time start);
int		time_to_ms(t_time time);

/* utils.c */
int		ft_atoi(const char *str);
int		safe_free(void **ptr);
size_t	ft_strlen(const char *s);
void	print_message(t_table *table, int flag);

#endif