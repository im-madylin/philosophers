/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahlee <hahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:28:03 by hahlee            #+#    #+#             */
/*   Updated: 2023/03/22 19:19:14 by hahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_action(t_philo *philo)
{
	philo->recent_time = *(philo->start_time);
	if (philo->id % 2 == 0)
		msleep(5);
	while (am_i_die(philo) == LIVE)
	{
		if (do_think(philo) == 0)
			return (0);
		if (do_eat(philo) == 0)
			return (0);
		if (do_sleep(philo) == 0)
			return (0);
	}
	return (0);
}

int	do_think(t_philo *philo)
{
	int	*argv;
	int	think_time;

	if (am_i_die(philo) == DIE)
		return (0);
	print_message(philo, THINK);
	argv = philo->argv;
	think_time = argv[TIME_DIE] - (argv[TIME_EAT] + argv[TIME_SLEEP] + 100);
	if (think_time <= 0)
		return (1);
	msleep(think_time);
	return (1);
}

int	do_eat(t_philo *philo)
{
	pick_up_fork(philo);
	if (am_i_die(philo) == DIE)
		return (0);
	print_message(philo, EAT);
	gettimeofday(&(philo->recent_time), NULL);
	msleep(philo->argv[TIME_EAT]);
	add_eat_count(philo);
	put_down_fork(philo);
	return (1);
}

void	add_eat_count(t_philo *philo)
{
	philo->eat_info.count++;
	if (philo->eat_info.count == philo->argv[MUST_EAT])
	{
		pthread_mutex_lock(philo->eat_info.mutex);
		philo->eat_info.is_enough = TRUE;
		pthread_mutex_unlock(philo->eat_info.mutex);
	}
}

int	do_sleep(t_philo *philo)
{
	if (am_i_die(philo) == DIE)
		return (0);
	print_message(philo, SLEEP);
	msleep(philo->argv[TIME_SLEEP]);
	return (1);
}
