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

void	move_checker(t_pusw *t_b, int operation)
{
	if (operation == OPER_SA)
		sx(t_b->a);
	else if (operation == OPER_SB)
		sx(t_b->b);
	else if (operation == OPER_SS)
		ss(t_b);
	else if (operation == OPER_PA)
		pa(t_b);
	else if (operation == OPER_PB)
		pb(t_b);
	else if (operation == OPER_RA)
		rx(t_b->a);
	else if (operation == OPER_RB)
		rx(t_b->b);
	else if (operation == OPER_RR)
		rr(t_b);
	else if (operation == OPER_RRA)
		rrx(t_b->a);
	else if (operation == OPER_RRB)
		rrx(t_b->b);
	else if (operation == OPER_RRR)
		rrr(t_b);
}

void	checker(t_pusw *t_b)
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
			move_checker(t_b, i);
		else
		{
			free(line);
			error_exit(t_b);
		}
		free(line);
	}
	if (!t_b->b->size && check_if_sorted(t_b->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	t_b->is_checked = 1;
	checker(t_b);
	return (free_all(t_b));
}
