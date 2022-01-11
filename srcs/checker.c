/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:14:54 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 20:55:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_checker(t_pusw *tridge, int operation)
{
	if (operation == OPER_SA)
		sx(tridge->a);
	else if (operation == OPER_SB)
		sx(tridge->b);
	else if (operation == OPER_SS)
		ss(tridge);
	else if (operation == OPER_PA)
		pa(tridge);
	else if (operation == OPER_PB)
		pb(tridge);
	else if (operation == OPER_RA)
		rx(tridge->a);
	else if (operation == OPER_RB)
		rx(tridge->b);
	else if (operation == OPER_RR)
		rr(tridge);
	else if (operation == OPER_RRA)
		rrx(tridge->a);
	else if (operation == OPER_RRB)
		rrx(tridge->b);
	else if (operation == OPER_RRR)
		rrr(tridge);
}

void	checker(t_pusw *tridge)
{
	char		*line;
	const char	*operation[12] = {"sa", "sb", "ss", "pa", "pb", \
							"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	while (get_next_line(0, &line))
	{
		i = 0;
		while (operation[i] && ft_strncmp(operation[i], line, ft_strlen(operation[i]) + 1))
			i++;
		if (i != 11)
			move_checker(tridge, i);
		else
		{
			free(line);
			error_exit(tridge);
		}
		free(line);
	}
	if (!tridge->b->size && check_if_sorted(tridge->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	tridge->is_checked = 1;
	checker(tridge);
	return (free_all(tridge));
}
