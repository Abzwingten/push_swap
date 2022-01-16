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

t_bool	is_corr(t_pusw *t_b, t_node *a, t_node *b)
{
	if (t_b->size <= 1)
		return (false);
	if (a->value < a->prev->value)
		return (a->value > b->value || a->prev->value < b->value);
	if (a->value > b->value && b->value > a->prev->value)
		return (true);
	return (false);
}

int	calc_min(t_pusw *t_b, t_node *na, t_node *nb, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)t_b->a->size)
	{
		j = -1;
		while (++j < (int)t_b->b->size)
		{
			if (m > ft_max(i, j) + (ft_min(i, j) * !!(t_b->dir % 3))
				&& is_corr(t_b, na, nb))
			{
				m = ft_max(i, j) + (ft_min(i, j) * !!(t_b->dir % 3));
				t_b->move[t_b->dir * 2] = i;
				t_b->move[t_b->dir * 2 + 1] = j;
			}
			nb = nb->next;
			if (t_b->dir % 2)
				nb = nb->prev->prev;
		}
		na = na->prev;
		if (t_b->dir < 2)
			na = na->next->next;
	}
	return (m);
}

void	move(t_pusw *t_b, int dir, t_stack	*s, int m)
{
	int		i;

	while (dir < 4 && t_b->min[dir] != m)
		dir++;
	if (t_b->move[dir * 2] < t_b->move[dir * 2 + 1])
		s = t_b->b;
	i = -1;
	while (dir == 0 && ++i < ft_min(t_b->move[dir * 2], t_b->move[dir * 2 + 1]))
		rr(t_b);
	while (dir == 3 && ++i < ft_min(t_b->move[dir * 2], t_b->move[dir * 2 + 1]))
		rrr(t_b);
	while (dir == 0 && i++ < ft_max(t_b->move[dir * 2], t_b->move[dir * 2 + 1]))
		rx(s);
	while (dir == 3 && i++ < ft_max(t_b->move[dir * 2], t_b->move[dir * 2 + 1]))
		rrx(s);
	while (dir == 1 && ++i < t_b->move[dir * 2])
		rx(t_b->a);
	while (dir == 2 && ++i < t_b->move[dir * 2])
		rrx(t_b->a);
	i = -1;
	while (dir == 1 && ++i < t_b->move[dir * 2 + 1])
		rrx(t_b->b);
	while (dir == 2 && ++i < t_b->move[dir * 2 + 1])
		rx(t_b->b);
	pa(t_b);
}

void	align(t_pusw *t_b, t_node *node)
{
	int	i;

	i = 0;
	while (node->value != t_b->arr[0])
	{
		node = node->next;
		i++;
	}
	while (t_b->a->head->value != t_b->arr[0])
	{
		if (i <= t_b->size / 2)
			rx(t_b->a);
		else
			rrx(t_b->a);
	}
}

void	solve(t_pusw *t_b, t_stack *a, t_stack *b, int *m)
{
	int	i;

	i = -1;
	while (++i < t_b->size && t_b->size > 30)
	{
		if (a->head->value < t_b->arr[t_b->size / 2 - i / 2])
		{
			pb(t_b);
			rx(t_b->b);
		}
		else if (a->head->value > t_b->arr[t_b->size / 3 * 2 - i / 3])
			pb(t_b);
		else
			rx(a);
	}
	while (a->size > 2)
		pb(t_b);
	while (b->size > 0)
	{
		t_b->dir = -1;
		while (++t_b->dir < 4)
			m[t_b->dir] = calc_min(t_b, a->head, b->head, INT_MAX);
		move(t_b, 0, t_b->a, ft_min(m[0], ft_min(m[1], ft_min(m[2], m[3]))));
	}
	align(t_b, t_b->a->head);
}
