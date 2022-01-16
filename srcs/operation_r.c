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

void	rr(t_pusw *t_b)
{
	if (t_b->a->size >= 2)
		t_b->a->head = t_b->a->head->next;
	if (t_b->b->size >= 2)
		t_b->b->head = t_b->b->head->next;
	if (!t_b->is_checked && (t_b->a->size >= 2 || t_b->b->size >= 2))
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

void	rrr(t_pusw *t_b)
{
	if (t_b->a->size >= 2)
		t_b->a->head = t_b->a->head->prev;
	if (t_b->b->size >= 2)
		t_b->b->head = t_b->b->head->prev;
	if (!t_b->is_checked && (t_b->a->size >= 2 || t_b->b->size >= 2))
		ft_printf("rrr\n");
}
