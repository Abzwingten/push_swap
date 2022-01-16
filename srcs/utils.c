/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */  
/*   Created: 2022/01/09 13:15:24 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:42:12 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_pusw *t_b, char **arg, int ac)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (arg[i])
	{
		append(t_b, t_b->a, get_int(t_b, arg[i]));
		if (ac == 2)
			free(arg[i]);
		i++;
	}
	if (ac == 2)
		free(arg);
}

int	free_all(t_pusw *t_b)
{
	while (t_b->a->head)
		free(pop(t_b->a));
	free(t_b->a);
	while (t_b->b->head)
		free(pop(t_b->b));
	free(t_b->b);
	if (t_b->arr)
		free(t_b->arr);
	if (t_b->tmp)
		free(t_b->tmp);
	free(t_b);
	return (0);
}

int	get_int(t_pusw *t_b, const char *str)
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
		error_exit(t_b);
	while ('0' <= *str && *str <= '9')
		modulus = modulus * 10 + *(str++) - '0';
	if (*str || (int64_t)(modulus * sign) < (int64_t)INT_MIN
		|| (int64_t)INT_MAX < (int64_t)(modulus * sign))
		error_exit(t_b);
	return (modulus * sign);
}

void	error_exit(t_pusw *t_b)
{
	ft_putstr_fd("Error\n", 1);
	free_all(t_b);
	exit(1);
}
