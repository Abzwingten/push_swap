/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:20 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 20:55:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_dups(t_pusw *t_b)
{
	int		i;
	t_node	*j;
	t_node	*k;

	i = -1;
	j = t_b->a->head;
	while (++i < (int)t_b->a->size)
	{
		k = j->next;
		while (j != k)
		{
			if (j->value == k->value)
			{
				error_exit(t_b);
				ft_printf("Dups!");
			}
			k = k->next;
		}
		j = j->next;
	}
}

void	least_case_sort(t_pusw *t_b)
{
	if (t_b->a->size == 2
		|| !(((t_b->tmp[0] == t_b->arr[2]) && (t_b->tmp[1] == t_b->arr[0]))
			|| ((t_b->tmp[1] == t_b->arr[2]) && (t_b->tmp[2] == t_b->arr[0]))))
		sx(t_b->a);
	if (t_b->a->size == 2)
		return ;
	t_b->tmp[0] = t_b->a->head->value;
	t_b->tmp[1] = t_b->a->head->next->value;
	t_b->tmp[2] = t_b->a->head->next->next->value;
	if (t_b->a->size != 2
		&& ((t_b->tmp[0] == t_b->arr[2]) && (t_b->tmp[1] == t_b->arr[0])))
		rx(t_b->a);
	else if (t_b->a->size != 2
		&& ((t_b->tmp[1] == t_b->arr[2]) && (t_b->tmp[2] == t_b->arr[0])))
		rrx(t_b->a);
}

t_bool	check_if_sorted(t_stack *stack)
{
	t_node	*current;
	int		tmp;

	current = stack->head;
	if (!current)
		return (true);
	tmp = current->value;
	current = current->next;
	while (current != stack->head)
	{
		if (tmp > current->value)
			return (false);
		tmp = current->value;
		current = current->next;
	}
	return (true);
}
