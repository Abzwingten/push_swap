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

void	rr(t_pusw *ps)
{
	if (ps->a->size >= 2)
		ps->a->head = ps->a->head->next;
	if (ps->b->size >= 2)
		ps->b->head = ps->b->head->next;
	if (!ps->is_chk && (ps->a->size >= 2 || ps->b->size >= 2))
		ft_printf("rr\n");
}

void	rrx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->prev;
	if (x->name)
		ft_printf("rr%c\n", x->name);
}

void	rrr(t_pusw *ps)
{
	if (ps->a->size >= 2)
		ps->a->head = ps->a->head->prev;
	if (ps->b->size >= 2)
		ps->b->head = ps->b->head->prev;
	if (!ps->is_chk && (ps->a->size >= 2 || ps->b->size >= 2))
		ft_printf("rrr\n");
}
