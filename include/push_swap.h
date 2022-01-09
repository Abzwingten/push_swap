/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:07:44 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 18:07:59 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <limits.h>
# include <stdint.h>

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
	char	name;
}	t_stack;

typedef struct s_pusw
{
	int		*tmp;
	int		*arr;
	int		size;
	int		dir;
	int		is_chk;
	int		min[4];
	int		move[8];
	t_stack	*a;
	t_stack	*b;
}	t_pusw;

void	push_swap(t_pusw *ps);
void	move_checker(t_pusw *ps, int op);
void	checker(t_pusw *ps);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	append(t_pusw *ps, t_stack *stack, int val);
t_node	*new_node(t_pusw *ps, int val);
t_bool	is_corr(t_pusw *ps, t_node *a, t_node *b);
int		calc_min(t_pusw *ps, t_node *na, t_node *nb, int m);
void	move(t_pusw *ps, int dir, t_stack	*s, int m);
void	align(t_pusw *ps, t_node *n);
void	solve(t_pusw *ps, t_stack *a, t_stack *b, int *min);
void	parse_arg(t_pusw *ps, char **arg, int ac);
void	check_dup(t_pusw *ps);
void	least_case_sort(t_pusw *ps);
t_bool	check_sorted(t_stack *st);
void	arr_qsort(int *arr, int l, int r);
int		free_all(t_pusw *ps);
void	error_exit(t_pusw *ps);
int		get_int(t_pusw *ps, const char *str);
void	test(t_pusw *ps);

void	pa(t_pusw *ps);
void	pb(t_pusw *ps);
void	sx(t_stack *x);
void	ss(t_pusw *ps);
void	rx(t_stack *x);
void	rr(t_pusw *ps);
void	rrx(t_stack *x);
void	rrr(t_pusw *ps);

/*
**	sa: swap a - swap the first 2 elements at the top of stack a.
**		Do nothing if there is only one or no elements). -> sx(t_stack *x)
**	sb: swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there is only one or no elements). -> sx(t_stack *x)
**	ss : sa and sb at the same time. -> ss(t_pusw *ps)
**
**	pa: push a - take the first element at the top of b
**		and put it at the top of a. Do nothing if b is empty. -> pa(t_pusw *ps)
**	pb: push b - take the first element at the top of a
**		and put it at the top of b. Do nothing if a is empty. -> pb(t_pusw *ps)
**
**	ra: rotate a - shift up all elements of stack a by 1.
**		The first element becomes the last one. -> rx(t_stack *x)
**	rb: rotate b - shift up all elements of stack b by 1.
**		The first element becomes the last one. -> rx(t_stack *x)
**	rr: ra and rb at the same time. -> rr(t_pusw *ps)
**
**	rra: reverse rotate a - shift down all elements of stack a by 1.
**		 The last element becomes the first one. -> rrx(t_stack *x)
**	rrb: reverse rotate b - shift down all elements of stack b by 1.
**		 The last element becomes the first one. -> rrx(t_stack *x)
**	rrr: rra and rrb at the same time. -> rrr(t_pusw *ps)
*/

#endif
