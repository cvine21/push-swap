/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:23:32 by marvin            #+#    #+#             */
/*   Updated: 2021/12/22 17:23:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ops	*create_t_ops(void)
{
	t_ops	*new;

	new = (t_ops *)malloc(sizeof(t_ops));
	if (!new)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	return (new);
}

void	replace(t_ops *ops)
{
	while (ops->ra > 0 && ops->rb > 0)
	{
		ops->ra--;
		ops->rb--;
		ops->rr++;
	}
	while (ops->rra > 0 && ops->rrb > 0)
	{
		ops->rra--;
		ops->rrb--;
		ops->rrr++;
	}
}

void	same_time_ops(t_ops *ops, int *least_amount)
{
	int	sum_1;
	int	sum_2;

	if (!ops->ra && ops->rra)
	{
		sum_1 = ops->rra + ops->rb;
		replace(ops);
		sum_2 = ops->rra + ops->rrb + ops->rrr;
	}
	else if (ops->ra && !ops->rra)
	{
		sum_1 = ops->ra + ops->rrb;
		replace(ops);
		sum_2 = ops->ra + ops->rb + ops->rr;
	}
	if (sum_1 < sum_2)
		*least_amount = sum_1;
	else
		*least_amount = sum_2;
}

int	find_opt_comb(t_stack *stack, t_elem *current, t_ops *ops, t_elem *tmp)
{
	int	least_amount;
	int	sum_1;
	int	sum_2;

	least_amount = 0;
	calc_ops(stack, current, ops, tmp);
	if ((!ops->ra && ops->rra) || (ops->ra && !ops->rra))
		same_time_ops(ops, &least_amount);
	else if ((!ops->ra && !ops->rra) || (ops->ra && ops->rra))
	{
		sum_1 = ops->rb + ops->rra;
		sum_2 = ops->ra + ops->rrb;
		if (sum_1 < sum_2)
			least_amount = sum_1;
		else
			least_amount = sum_2;
		replace(ops);
		sum_1 = ops->rb + ops->ra + ops->rr;
		sum_2 = ops->rrb + ops->rra + ops->rrr;
		if (sum_1 < sum_2 && sum_1 <= least_amount)
			least_amount = sum_1;
		else if (sum_2 < sum_1 && sum_2 <= least_amount)
			least_amount = sum_2;
	}
	return (least_amount);
}

t_elem	*find_opt_el(t_stack *stack, t_ops *ops)
{
	t_elem	*current;
	t_elem	*tmp;
	int		least_amount;
	int		amount;

	tmp = NULL;
	current = stack->b->head;
	least_amount = find_opt_comb(stack, current, ops, tmp);
	ops->opt_elem = current;
	ops->least_amount = least_amount;
	current = current->next;
	while (current)
	{
		amount = find_opt_comb(stack, current, ops, tmp);
		if (amount < least_amount)
		{
			least_amount = amount;
			ops->opt_elem = current;
			ops->least_amount = least_amount;
		}
		current = current->next;
	}
	return (ops->opt_elem);
}
