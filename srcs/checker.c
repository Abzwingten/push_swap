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

void	move_checker(t_pusw *ps, int op)
{
	if (op == OPER_SA)
		sx(ps->a);
	else if (op == OPER_SB)
		sx(ps->b);
	else if (op == OPER_SS)
		ss(ps);
	else if (op == OPER_PA)
		pa(ps);
	else if (op == OPER_PB)
		pb(ps);
	else if (op == OPER_RA)
		rx(ps->a);
	else if (op == OPER_RB)
		rx(ps->b);
	else if (op == OPER_RR)
		rr(ps);
	else if (op == OPER_RRA)
		rrx(ps->a);
	else if (op == OPER_RRB)
		rrx(ps->b);
	else if (op == OPER_RRR)
		rrr(ps);
}

void	checker(t_pusw *ps)
{
	char		*line;
	const char	*op[12] = {"sa", "sb", "ss", "pa", "pb", \
							"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	while (get_next_line(0, &line))
	{
		i = 0;
		while (op[i] && ft_strncmp(op[i], line, ft_strlen(op[i]) + 1))
			i++;
		if (i != 11)
			move_checker(ps, i);
		else
		{
			free(line);
			error_exit(ps);
		}
		free(line);
	}
	if (!ps->b->size && check_if_sorted(ps->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	ps->is_chk = 1;
	checker(ps);
	return (free_all(ps));
}
