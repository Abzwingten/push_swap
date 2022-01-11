/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:20 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 20:55:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_pusw *tridge, char **arg, int ac)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (arg[i])
	{
		append(tridge, tridge->a, get_int(tridge, arg[i]));
		if (ac == 2)
			free(arg[i]);
		i++;
	}
	if (ac == 2)
		free(arg);
}

void	check_for_dups(t_pusw *tridge)
{
	int		i;
	t_node	*j;
	t_node	*k;

	i = -1;
	j = tridge->a->head;
	while (++i < (int)tridge->a->size)
	{
		k = j->next;
		while (j != k)
		{
			if (j->value == k->value)
				error_exit(tridge);
			k = k->next;
		}
		j = j->next;
	}
}

void	least_case_sort(t_pusw *tridge)
{
	if (tridge->a->size == 2
		|| !(((tridge->tmp[0] == tridge->arr[2]) && (tridge->tmp[1] == tridge->arr[0]))
			|| ((tridge->tmp[1] == tridge->arr[2]) && (tridge->tmp[2] == tridge->arr[0]))))
		sx(tridge->a);
	if (tridge->a->size == 2)
		return ;
	tridge->tmp[0] = tridge->a->head->value;
	tridge->tmp[1] = tridge->a->head->next->value;
	tridge->tmp[2] = tridge->a->head->next->next->value;
	if (tridge->a->size != 2
		&& ((tridge->tmp[0] == tridge->arr[2]) && (tridge->tmp[1] == tridge->arr[0])))
		rx(tridge->a);
	else if (tridge->a->size != 2
		&& ((tridge->tmp[1] == tridge->arr[2]) && (tridge->tmp[2] == tridge->arr[0])))
		rrx(tridge->a);
}

t_bool	check_if_sorted(t_stack *stack)
{
	t_node	*current;
	int		tmp;

	current = stack->head;
	if (!current)
		return (true);
	tmp = current->value;
	current = current->next;
	while (current != stack->head)
	{
		if (tmp > current->value)
			return (false);
		tmp = current->value;
		current = current->next;
	}
	return (true);
}
