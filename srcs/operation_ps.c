/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:14:58 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 16:33:41 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pusw *tridge)
{
	if (tridge->b->size < 1)
		return ;
	push(tridge->a, pop(tridge->b));
	if (!tridge->is_checked)
		ft_printf("pa\n");
}

void	pb(t_pusw *tridge)
{
	if (tridge->a->size < 1)
		return ;
	push(tridge->b, pop(tridge->a));
	if (!tridge->is_checked)
		write(1, "pb\n", 3);
}

void	sx(t_stack *x)
{
	t_node	*pop_x1;
	t_node	*pop_x2;

	if (x->size < 2)
		return ;
	pop_x1 = pop(x);
	pop_x2 = pop(x);
	push(x, pop_x1);
	push(x, pop_x2);
	if (x->name)
		ft_printf("s%c\n", x->name);
}

void	ss(t_pusw *tridge)
{
	t_node	*pop_a1;
	t_node	*pop_a2;
	t_node	*pop_b1;
	t_node	*pop_b2;

	if (tridge->a->size >= 2)
	{
		pop_a1 = pop(tridge->a);
		pop_a2 = pop(tridge->a);
		push(tridge->a, pop_a1);
		push(tridge->a, pop_a2);
	}
	if (tridge->b->size >= 2)
	{
		pop_b1 = pop(tridge->b);
		pop_b2 = pop(tridge->b);
		push(tridge->b, pop_b1);
		push(tridge->b, pop_b2);
	}
	if (!tridge->is_checked && (tridge->a->size >= 2 || tridge->b->size >= 2))
		write(1, "ss\n", 3);
}
