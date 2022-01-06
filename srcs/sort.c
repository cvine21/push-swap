/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:42:37 by cvine             #+#    #+#             */
/*   Updated: 2022/01/03 22:33:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	opt_direction(t_stack *stack)
{
	t_elem	*top;
	t_elem	*bottom;
	int		rot;
	int		rrot;

	rot = 0;
	rrot = 0;
	top = stack->a->head;
	bottom = stack->a->tail;
	while (top && top->val > bottom->val)
	{
		top = top->next;
		rot++;
	}
	top = stack->a->head;
	while (bottom && top->val > bottom->val)
	{
		bottom = bottom->prev;
		rrot++;
	}
	if (rot < rrot)
		return (0);
	else
		return (1);
}

void	sort(t_stack *stack)
{
	if (opt_direction(stack))
	{
		while (stack->a->head->val > stack->a->tail->val)
			rrotate(stack->a, "rra", 1);
	}
	else
	{
		while (stack->a->head->val > stack->a->tail->val)
			rotate(stack->a, "ra", 1);
	}
}

void	minisort(t_stack *stack)
{
	if (stack->a->size == 3)
	{
		if (stack->a->head->val < stack->a->head->next->val
			&& stack->a->tail->val < stack->a->head->next->val
			&& stack->a->tail->val > stack->a->head->val)
		{
			rrotate(stack->a, "rra", 1);
			swap(stack->a, "sa", 1);
		}
		if ((stack->a->head->val > stack->a->head->next->val
				&& stack->a->tail->val > stack->a->head->val)
			|| (stack->a->head->val > stack->a->head->next->val
				&& stack->a->tail->val < stack->a->head->next->val))
			swap(stack->a, "sa", 1);
	}
	sort(stack);
}
