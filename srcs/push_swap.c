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

void	push_swap(t_pusw *t_b)
{
	int		i;
	t_node	*current;

	if (check_if_sorted(t_b->a))
		return ;
	t_b->arr = (int *)malloc(sizeof(int) * t_b->a->size);
	t_b->tmp = (int *)malloc(sizeof(int) * t_b->a->size);
	if (!t_b->arr || !t_b->tmp)
		error_exit(t_b);
	current = t_b->a->head;
	i = -1;
	while (++i < (int)t_b->a->size)
	{
		t_b->tmp[i] = current->value;
		t_b->arr[i] = current->value;
		current = current->next;
	}
	quick_sort(t_b->arr, 0, t_b->a->size - 1);
	if (t_b->size <= 3)
		least_case_sort(t_b);
	else
		solve(t_b, t_b->a, t_b->b, t_b->min);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_pusw	*t_b;
	char	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	t_b = (t_pusw *)ft_calloc(1, sizeof(t_pusw));
	a->name = 'a';
	b->name = 'b';
	t_b->a = a;
	t_b->b = b;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_args(t_b, args, argc);
	}
	else if (argc > 2)
		parse_args(t_b, argv, argc);
	check_for_dups(t_b);
	t_b->size = a->size;
	push_swap(t_b);
	return (free_all(t_b));
}
