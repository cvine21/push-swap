/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:54:13 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 16:54:13 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	null(t_ops *ops)
{
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

void	b_moves(t_elem *cur, t_ops *ops, t_elem *tmp)
{
	null(ops);
	tmp = cur->prev;
	while (tmp)
	{
		ops->rb++;
		tmp = tmp->prev;
	}
	tmp = cur;
	while (tmp)
	{
		ops->rrb++;
		tmp = tmp->next;
	}
}

int	is_moves_need(t_stack *stack, t_elem *cur, t_elem *tmp)
{
	if (((tmp->val < tmp->prev->val && cur->val > tmp->prev->val)
			|| (tmp->val > tmp->next->val && cur->val < tmp->prev->val))
		&& is_sorted(stack, tmp))
		return (1);
	return (0);
}

void	a_moves(t_stack *stack, t_elem *cur, t_ops *ops, t_elem *tmp)
{
	size_t	size;

	tmp = stack->a->head;
	size = stack->a->size;
	if (is_moves_need(stack, cur, tmp))
		return ;
	while (((cur->val > tmp->val && size - 1) || (cur->val < tmp->val
				&& cur->val < tmp->prev->val && tmp->val > tmp->prev->val)))
	{
		ops->ra++;
		tmp = tmp->next;
		size--;
		if (is_moves_need(stack, cur, tmp))
			return ;
	}
	tmp = stack->a->tail;
	while (((cur->val < tmp->val && cur->val > tmp->next->val)
			|| (((cur->val > tmp->val && cur->val > tmp->next->val)
					|| (cur->val < tmp->val && cur->val < tmp->next->val))
				&& tmp->val < tmp->next->val))
		&& !is_moves_need(stack, cur, tmp))
	{
		ops->rra++;
		tmp = tmp->prev;
	}
}

void	calc_ops(t_stack *stack, t_elem *cur, t_ops *ops, t_elem *tmp)
{
	b_moves(cur, ops, tmp);
	stack->a->head->prev = stack->a->tail;
	stack->a->tail->next = stack->a->head;
	a_moves(stack, cur, ops, tmp);
	stack->a->head->prev = NULL;
	stack->a->tail->next = NULL;
}
