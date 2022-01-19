/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:10:23 by rantario          #+#    #+#             */
/*   Updated: 2022/01/19 12:10:24 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ss(t_pusw *t_b)
{
	t_node	*pop_a1;
	t_node	*pop_a2;
	t_node	*pop_b1;
	t_node	*pop_b2;

	if (t_b->a->size >= 2)
	{
		pop_a1 = pop(t_b->a);
		pop_a2 = pop(t_b->a);
		push(t_b->a, pop_a1);
		push(t_b->a, pop_a2);
	}
	if (t_b->b->size >= 2)
	{
		pop_b1 = pop(t_b->b);
		pop_b2 = pop(t_b->b);
		push(t_b->b, pop_b1);
		push(t_b->b, pop_b2);
	}
	if (!t_b->is_checked && (t_b->a->size >= 2 || t_b->b->size >= 2))
		pt_printf("ss\n");
}
