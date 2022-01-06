/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:01:35 by marvin            #+#    #+#             */
/*   Updated: 2022/01/02 16:01:35 by marvin           ###   ########.fr       */
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

void	a_moves(t_stack *stack, t_elem *cur, t_ops *ops, t_elem *tmp)
{
	size_t	size;

	tmp = stack->a->head;
	size = stack->a->size;
	if (is_sorted(stack) && ((cur->val > tmp->val && cur->val > tmp->prev->val)
			|| (cur->val < tmp->val && cur->val < tmp->prev->val)))
		return ;
	while (((cur->val > tmp->val && size - 1)
			|| (cur->val < tmp->val && cur->val < tmp->prev->val
				&& tmp->val > tmp->prev->val)))
	{
		ops->ra++;
		tmp = tmp->next;
		size--;
	}
	tmp = stack->a->tail;
	while ((cur->val < tmp->val && cur->val > tmp->next->val)
		|| (((cur->val > tmp->val && cur->val > tmp->next->val)
				|| (cur->val < tmp->val && cur->val < tmp->next->val))
			&& tmp->val < tmp->next->val))
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
