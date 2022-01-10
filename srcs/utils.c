/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:20 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 20:55:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_pusw *ps, char **arg, int ac)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (arg[i])
	{
		append(ps, ps->a, get_int(ps, arg[i]));
		if (ac == 2)
			free(arg[i]);
		i++;
	}
	if (ac == 2)
		free(arg);
}

void	check_for_dups(t_pusw *ps)
{
	int		i;
	t_node	*j;
	t_node	*k;

	i = -1;
	j = ps->a->head;
	while (++i < (int)ps->a->size)
	{
		k = j->next;
		while (j != k)
		{
			if (j->val == k->val)
				error_exit(ps);
			k = k->next;
		}
		j = j->next;
	}
}

void	least_case_sort(t_pusw *ps)
{
	if (ps->a->size == 2
		|| !(((ps->tmp[0] == ps->arr[2]) && (ps->tmp[1] == ps->arr[0]))
			|| ((ps->tmp[1] == ps->arr[2]) && (ps->tmp[2] == ps->arr[0]))))
		sx(ps->a);
	if (ps->a->size == 2)
		return ;
	ps->tmp[0] = ps->a->head->val;
	ps->tmp[1] = ps->a->head->next->val;
	ps->tmp[2] = ps->a->head->next->next->val;
	if (ps->a->size != 2
		&& ((ps->tmp[0] == ps->arr[2]) && (ps->tmp[1] == ps->arr[0])))
		rx(ps->a);
	else if (ps->a->size != 2
		&& ((ps->tmp[1] == ps->arr[2]) && (ps->tmp[2] == ps->arr[0])))
		rrx(ps->a);
}

t_bool	check_if_sorted(t_stack *st)
{
	t_node	*n;
	int		tmp;

	n = st->head;
	if (!n)
		return (true);
	tmp = n->val;
	n = n->next;
	while (n != st->head)
	{
		if (tmp > n->val)
			return (false);
		tmp = n->val;
		n = n->next;
	}
	return (true);
}

void	array_qsort(int *arr, int l, int r)
{
	int	i;
	int	j;
	int	pvt;
	int	tmp;

	i = l;
	j = r;
	pvt = arr[(l + r) / 2];
	while (i <= j)
	{
		while (arr[i] < pvt)
			i++;
		while (arr[j] > pvt)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	}
	if (l < j)
		array_qsort(arr, l, j);
	if (i < r)
		array_qsort(arr, i, r);
}
