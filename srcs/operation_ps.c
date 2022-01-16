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

void	pa(t_pusw *t_b)
{
	if (t_b->b->size < 1)
		return ;
	push(t_b->a, pop(t_b->b));
	if (!t_b->is_checked)
		ft_printf("pa\n");
}

void	pb(t_pusw *t_b)
{
	if (t_b->a->size < 1)
		return ;
	push(t_b->b, pop(t_b->a));
	if (!t_b->is_checked)
		ft_printf("pb\n");
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
