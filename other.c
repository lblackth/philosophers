/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:14:22 by lblackth          #+#    #+#             */
/*   Updated: 2022/04/10 16:38:21 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	timeval_comp(struct timeval fst, struct timeval snd)
// {
// 	return ((snd.tv_sec - fst.tv_sec) * 1000000 + snd.tv_usec - fst.tv_usec);
// }

// void	ft_sleep(t_phil *phil, int ms)
// {
// 	struct timeval	tmp;

// 	usleep(ms * 920);
// 	gettimeofday(&tmp, NULL);
// 	while (timeval_comp(phil->tek, tmp) < ms * 1000)
// 	{
// 		usleep(ms * 3);
// 		gettimeofday(&tmp, NULL);
// 	}
// }

long int	gettime(struct timeval start)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000 ;
	res -= 1000 * (size_t)start.tv_sec + (size_t)start.tv_usec / 1000;
	return (res);
}

long	timeval_comp(struct timeval fst, struct timeval snd)
{
	return (snd.tv_usec - fst.tv_usec + (snd.tv_sec - fst.tv_sec) * 1000000);
}

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

void	ft_sleep(int milisec)
{
	long	time;

	time = ft_time();
	usleep(milisec * 920);
	while (ft_time() < time + milisec)
		usleep(milisec * 3);
}