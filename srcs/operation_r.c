/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:04 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:42:12 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->next;
	if (x->name)
		ft_printf("r%c\n", x->name);
}

void	rr(t_pusw *tridge)
{
	if (tridge->a->size >= 2)
		tridge->a->head = tridge->a->head->next;
	if (tridge->b->size >= 2)
		tridge->b->head = tridge->b->head->next;
	if (!tridge->is_checked && (tridge->a->size >= 2 || tridge->b->size >= 2))
		write(1, "rr\n", 3);
}

void	rrx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->prev;
	if (x->name)
		ft_printf("rr%c\n", x->name);
}

void	rrr(t_pusw *tridge)
{
	if (tridge->a->size >= 2)
		tridge->a->head = tridge->a->head->prev;
	if (tridge->b->size >= 2)
		tridge->b->head = tridge->b->head->prev;
	if (!tridge->is_checked && (tridge->a->size >= 2 || tridge->b->size >= 2))
		write(1, "rrr\n", 3);
}
