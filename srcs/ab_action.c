/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:30:29 by cvine             #+#    #+#             */
/*   Updated: 2022/01/05 18:33:14 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	same_time(t_stack *stack, t_ops *ops)
{
	if (ops->least_amount == ops->rb + ops->ra + ops->rr)
	{
		while (ops->rr-- > 0)
			rr(stack, 1);
		while (ops->rb-- > 0)
			rotate(stack->b, "rb", 1);
		while (ops->ra-- > 0)
			rotate(stack->a, "ra", 1);
	}
	else if (ops->least_amount == ops->rrb + ops->rra + ops->rrr)
	{
		while (ops->rrr-- > 0)
			rrr(stack, 1);
		while (ops->rrb-- > 0)
			rrotate(stack->b, "rrb", 1);
		while (ops->rra-- > 0)
			rrotate(stack->a, "rra", 1);
	}
	push(stack->b, stack->a, "pa", 1);
}

void	apart(t_stack *stack, t_ops *ops)
{
	while (ops->rr-- > 0)
	{
		ops->ra++;
		ops->rb++;
	}
	while (ops->rrr-- > 0)
	{
		ops->rra++;
		ops->rrb++;
	}
	if (ops->least_amount == ops->rb + ops->rra)
	{
		while (ops->rb-- > 0)
			rotate(stack->b, "rb", 1);
		while (ops->rra-- > 0)
			rrotate(stack->a, "rra", 1);
	}
	else if (ops->least_amount == ops->ra + ops->rrb)
	{
		while (ops->ra-- > 0)
			rotate(stack->a, "ra", 1);
		while (ops->rrb-- > 0)
			rrotate(stack->b, "rrb", 1);
	}
	push(stack->b, stack->a, "pa", 1);
}

void	distribute_b(t_stack *stack, t_ops *ops)
{
	t_elem	*tmp;

	tmp = NULL;
	while (stack->b->size)
	{
		find_opt_comb(stack, find_opt_el(stack, ops), ops, tmp);
		if (ops->rr + ops->ra + ops->rb == ops->least_amount
			|| ops->rrr + ops->rra + ops->rrb == ops->least_amount)
			same_time(stack, ops);
		else
			apart(stack, ops);
	}
}

void	distribute_a(t_stack *stack)
{
	t_elem	*tmp;
	size_t	pb;

	if (!stack || !stack->a || !stack->b)
		return ;
	tmp = stack->a->head;
	pb = stack->a->size - stack->keep_in_a;
	while (tmp && pb)
	{
		if (tmp->flag)
		{
			tmp = tmp->next;
			push(stack->a, stack->b, "pb", 1);
			pb--;
		}
		else
		{
			rotate(stack->a, "ra", 1);
			tmp = stack->a->head;
		}
	}
}
