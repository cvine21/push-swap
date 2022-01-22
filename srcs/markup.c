/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:54:58 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 16:54:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	val_markup(t_lst *stack_a, t_elem *markup_start)
{
	ssize_t	index;
	size_t	keep;
	t_elem	*tmp;

	keep = 1;
	if (stack_a && markup_start)
	{
		index = markup_start->index;
		markup_start->flag = 0;
		tmp = markup_start->next;
		while (tmp != markup_start)
		{
			if (tmp->index > index)
			{
				index = tmp->index;
				tmp->flag = 0;
				keep++;
			}
			else
				tmp->flag = 1;
			tmp = tmp->next;
		}
	}
	return (keep);
}

size_t	index_markup(t_lst *stack_a, t_elem *markup_start)
{
	ssize_t	index;
	size_t	keep;
	t_elem	*tmp;

	keep = 1;
	if (stack_a && markup_start)
	{
		index = markup_start->index;
		markup_start->flag = 0;
		tmp = markup_start->next;
		while (tmp != markup_start)
		{
			if (tmp->index == index + 1)
			{
				tmp->flag = 0;
				index++;
				keep++;
			}
			else
				tmp->flag = 1;
			tmp = tmp->next;
		}
	}
	return (keep);
}

void	compare(t_stack *stack, t_elem *markup_start, size_t *current)
{
	size_t	vm_res;
	size_t	im_res;

	vm_res = val_markup(stack->a, markup_start);
	if (vm_res >= stack->keep_in_a)
		stack->keep_in_a = vm_res;
	im_res = index_markup(stack->a, markup_start);
	if (im_res > vm_res || im_res > stack->keep_in_a)
		stack->keep_in_a = im_res;
	else
		stack->keep_in_a = val_markup(stack->a, markup_start);
	if (stack->keep_in_a >= *current)
	{
		*current = stack->keep_in_a;
		stack->markup_start = markup_start;
	}
}

void	markup(t_stack *stack)
{
	t_elem	*tmp;
	size_t	size;
	size_t	current;

	if (!stack || !stack->a || !stack->a->head)
		return ;
	stack->a->head->prev = stack->a->tail;
	stack->a->tail->next = stack->a->head;
	size = stack->a->size;
	tmp = stack->a->head;
	current = stack->keep_in_a;
	while (size--)
	{
		compare(stack, tmp, &current);
		tmp = tmp->next;
	}
	compare(stack, stack->markup_start, &current);
	stack->a->head->prev = NULL;
	stack->a->tail->next = NULL;
}
