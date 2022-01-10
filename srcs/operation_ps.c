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

void	pa(t_pusw *ps)
{
	if (ps->b->size < 1)
		return ;
	push(ps->a, pop(ps->b));
	if (!ps->is_chk)
		ft_printf("pa\n");
}

void	pb(t_pusw *ps)
{
	if (ps->a->size < 1)
		return ;
	push(ps->b, pop(ps->a));
	if (!ps->is_chk)
		ft_printf("pb\n");
}

void	sx(t_stack *x)
{
	t_node	*pOPER_x1;
	t_node	*pOPER_x2;

	if (x->size < 2)
		return ;
	pOPER_x1 = pop(x);
	pOPER_x2 = pop(x);
	push(x, pOPER_x1);
	push(x, pOPER_x2);
	if (x->name)
		ft_printf("s%c\n", x->name);
}

void	ss(t_pusw *ps)
{
	t_node	*pOPER_a1;
	t_node	*pOPER_a2;
	t_node	*pOPER_b1;
	t_node	*pOPER_b2;

	if (ps->a->size >= 2)
	{
		pOPER_a1 = pop(ps->a);
		pOPER_a2 = pop(ps->a);
		push(ps->a, pOPER_a1);
		push(ps->a, pOPER_a2);
	}
	if (ps->b->size >= 2)
	{
		pOPER_b1 = pop(ps->b);
		pOPER_b2 = pop(ps->b);
		push(ps->b, pOPER_b1);
		push(ps->b, pOPER_b2);
	}
	if (!ps->is_chk && (ps->a->size >= 2 || ps->b->size >= 2))
		ft_printf("ss\n");
}
