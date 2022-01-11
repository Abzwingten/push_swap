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

void	push_swap(t_pusw *tridge)
{
	int		i;
	t_node	*current;

	if (check_if_sorted(tridge->a))
		return ;
	tridge->arr = (int *)malloc(sizeof(int) * tridge->a->size);
	tridge->tmp = (int *)malloc(sizeof(int) * tridge->a->size);
	if (!tridge->arr || !tridge->tmp)
		error_exit(tridge);
	current = tridge->a->head;
	i = -1;
	while (++i < (int)tridge->a->size)
	{
		tridge->tmp[i] = current->value;
		tridge->arr[i] = current->value;
		current = current->next;
	}
	quick_sort(tridge->arr, 0, tridge->a->size - 1);
	if (tridge->size <= 3)
		least_case_sort(tridge);
	else
		solve(tridge, tridge->a, tridge->b, tridge->min);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_pusw	*tridge;
	char	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	tridge = (t_pusw *)ft_calloc(1, sizeof(t_pusw));
	a->name = 'a';
	b->name = 'b';
	tridge->a = a;
	tridge->b = b;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_args(tridge, args, argc);
	}
	else if (argc > 2)
		parse_args(tridge, argv, argc);
	check_for_dups(tridge);
	tridge->size = a->size;
	push_swap(tridge);
	return (free_all(tridge));
}
