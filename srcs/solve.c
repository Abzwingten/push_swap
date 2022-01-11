/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:11 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:46:50 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_corr(t_pusw *tridge, t_node *a, t_node *b)
{
	if (tridge->size <= 1)
		return (false);
	if (a->value < a->prev->value)
		return (a->value > b->value || a->prev->value < b->value);
	if (a->value > b->value && b->value > a->prev->value)
		return (true);
	return (false);
}

int	calc_min(t_pusw *tridge, t_node *na, t_node *nb, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)tridge->a->size)
	{
		j = -1;
		while (++j < (int)tridge->b->size)
		{
			if (m > ft_max(i, j) + (ft_min(i, j) * !!(tridge->dir % 3))
				&& is_corr(tridge, na, nb))
			{
				m = ft_max(i, j) + (ft_min(i, j) * !!(tridge->dir % 3));
				tridge->move[tridge->dir * 2] = i;
				tridge->move[tridge->dir * 2 + 1] = j;
			}
			nb = nb->next;
			if (tridge->dir % 2)
				nb = nb->prev->prev;
		}
		na = na->prev;
		if (tridge->dir < 2)
			na = na->next->next;
	}
	return (m);
}

void	move(t_pusw *tridge, int dir, t_stack	*s, int m)
{
	int		i;

	while (dir < 4 && tridge->min[dir] != m)
		dir++;
	if (tridge->move[dir * 2] < tridge->move[dir * 2 + 1])
		s = tridge->b;
	i = -1;
	while (dir == 0 && ++i < ft_min(tridge->move[dir * 2], tridge->move[dir * 2 + 1]))
		rr(tridge);
	while (dir == 3 && ++i < ft_min(tridge->move[dir * 2], tridge->move[dir * 2 + 1]))
		rrr(tridge);
	while (dir == 0 && i++ < ft_max(tridge->move[dir * 2], tridge->move[dir * 2 + 1]))
		rx(s);
	while (dir == 3 && i++ < ft_max(tridge->move[dir * 2], tridge->move[dir * 2 + 1]))
		rrx(s);
	while (dir == 1 && ++i < tridge->move[dir * 2])
		rx(tridge->a);
	while (dir == 2 && ++i < tridge->move[dir * 2])
		rrx(tridge->a);
	i = -1;
	while (dir == 1 && ++i < tridge->move[dir * 2 + 1])
		rrx(tridge->b);
	while (dir == 2 && ++i < tridge->move[dir * 2 + 1])
		rx(tridge->b);
	pa(tridge);
}

void	align(t_pusw *tridge, t_node *n)
{
	int	i;

	i = 0;
	while (n->value != tridge->arr[0])
	{
		n = n->next;
		i++;
	}
	while (tridge->a->head->value != tridge->arr[0])
	{
		if (i <= tridge->size / 2)
			rx(tridge->a);
		else
			rrx(tridge->a);
	}
}

void	solve(t_pusw *tridge, t_stack *a, t_stack *b, int *m)
{
	int	i;

	i = -1;
	while (++i < tridge->size && tridge->size > 30)
	{
		if (a->head->value < tridge->arr[tridge->size / 2 - i / 2])
		{
			pb(tridge);
			rx(tridge->b);
		}
		else if (a->head->value > tridge->arr[tridge->size / 3 * 2 - i / 3])
			pb(tridge);
		else
			rx(a);
	}
	while (a->size > 2)
		pb(tridge);
	while (b->size > 0)
	{
		tridge->dir = -1;
		while (++tridge->dir < 4)
			m[tridge->dir] = calc_min(tridge, a->head, b->head, INT_MAX);
		move(tridge, 0, tridge->a, ft_min(m[0], ft_min(m[1], ft_min(m[2], m[3]))));
	}
	align(tridge, tridge->a->head);
}
