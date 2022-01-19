/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:14:58 by rantario          #+#    #+#             */
/*   Updated: 2022/01/19 12:10:12 by rantario         ###   ########.fr       */
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
