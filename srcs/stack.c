/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:15:15 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:42:12 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->head)
	{
		node->prev = node;
		node->next = node;
		stack->head = node;
	}
	else
	{
		stack->head->prev->next = node;
		node->prev = stack->head->prev;
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*ret;

	if (!stack || !stack->size)
		return (NULL);
	ret = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = stack->head->next;
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
	}
	ret->prev = NULL;
	ret->next = NULL;
	stack->size--;
	return (ret);
}

void	append(t_pusw *t_b, t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(t_b, value);
	if (!stack)
		return ;
	if (!stack->head)
	{
		node->prev = node;
		node->next = node;
		stack->head = node;
	}
	else
	{
		stack->head->prev->next = node;
		node->prev = stack->head->prev;
		stack->head->prev = node;
		node->next = stack->head;
	}
	stack->size++;
}

t_node	*new_node(t_pusw *t_b, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit(t_b);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
