/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:44:06 by cvine             #+#    #+#             */
/*   Updated: 2021/12/12 11:55:41 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*create_dbl_lst(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		error();
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_stack	*create_stacks(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error();
	new->a = create_dbl_lst();
	new->b = create_dbl_lst();
	new->keep_in_a = 0;
	return (new);
}

void	lstadd_front(t_lst *lst, int val)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (!new)
		error();
	new->val = val;
	new->next = lst->head;
	new->prev = NULL;
	if (lst->head)
		lst->head->prev = new;
	lst->head = new;
	if (!(lst->tail))
		lst->tail = new;
	lst->size++;
}

int	pop(t_lst *lst)
{
	int		pop_val;
	t_elem	*ptr;

	if (!(lst->head))
		error();
	ptr = lst->head;
	lst->head = lst->head->next;
	if (lst->head)
		lst->head->prev = NULL;
	if (lst->tail == ptr)
		lst->tail = NULL;
	pop_val = ptr->val;
	free(ptr);
	lst->size--;
	return (pop_val);
}

void	clear(t_stack *stack, t_ops *ops)
{
	t_elem	*a_ptr;
	t_elem	*b_ptr;

	if (!stack)
		return ;
	a_ptr = stack->a->head;
	b_ptr = stack->b->head;
	while (a_ptr)
	{
		stack->a->head = stack->a->head->next;
		free(a_ptr);
		a_ptr = stack->a->head;
	}
	while (b_ptr)
	{
		stack->b->head = stack->b->head->next;
		free(b_ptr);
		b_ptr = stack->b->head;
	}
	free(stack->a);
	free(stack->b);
	free(stack);
	if (ops)
		free(ops);
}
