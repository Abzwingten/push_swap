/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:24 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:42:12 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_pusw *tridge)
{
	while (tridge->a->head)
		free(pop(tridge->a));
	free(tridge->a);
	while (tridge->b->head)
		free(pop(tridge->b));
	free(tridge->b);
	if (tridge->arr)
		free(tridge->arr);
	if (tridge->tmp)
		free(tridge->tmp);
	free(tridge);
	return (0);
}

void	error_exit(t_pusw *tridge)
{
	ft_putstr_fd("Error\n", 1);
	free_all(tridge);
	exit(1);
}

int	get_int(t_pusw *tridge, const char *str)
{
	int			sign;
	uint64_t	modulus;

	modulus = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ((*str == '-' || *str == '+') && *(str++) == '-')
		sign *= -1;
	if (ft_strlen(str) > 10 || ft_strlen(str) == 0)
		error_exit(tridge);
	while ('0' <= *str && *str <= '9')
		modulus = modulus * 10 + *(str++) - '0';
	if (*str || (int64_t)(modulus * sign) < (int64_t)INT_MIN
		|| (int64_t)INT_MAX < (int64_t)(modulus * sign))
		error_exit(tridge);
	return (modulus * sign);
}
