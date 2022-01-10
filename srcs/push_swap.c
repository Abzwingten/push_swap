/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:08 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 20:55:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pusw *ps)
{
	int		i;
	t_node	*n;

	if (check_if_sorted(ps->a))
		return ;
	ps->arr = (int *)malloc(sizeof(int) * ps->a->size);
	ps->tmp = (int *)malloc(sizeof(int) * ps->a->size);
	if (!ps->arr || !ps->tmp)
		error_exit(ps);
	n = ps->a->head;
	i = -1;
	while (++i < (int)ps->a->size)
	{
		ps->tmp[i] = n->val;
		ps->arr[i] = n->val;
		n = n->next;
	}
	array_qsort(ps->arr, 0, ps->a->size - 1);
	if (ps->size <= 3)
		least_case_sort(ps);
	else
		solve(ps, ps->a, ps->b, ps->min);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_pusw	*ps;
	char	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	ps = (t_pusw *)ft_calloc(1, sizeof(t_pusw));
	a->name = 'a';
	b->name = 'b';
	ps->a = a;
	ps->b = b;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_args(ps, args, argc);
	}
	else if (argc > 2)
		parse_args(ps, argv, argc);
	check_for_dups(ps);
	ps->size = a->size;
	push_swap(ps);
	return (free_all(ps));
}
