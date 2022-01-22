/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:45:31 by cvine             #+#    #+#             */
/*   Updated: 2022/01/11 18:50:23 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_lst *lst, char *oper, int fd)
{
	if (!lst || !(lst->head) || !(lst->head->next))
		return ;
	lst->tail->next = lst->head;
	lst->head->prev = lst->tail;
	lst->tail = lst->tail->next;
	lst->head = lst->head->next;
	lst->head->prev = NULL;
	lst->tail->next = NULL;
	if (oper[1] != 'r' && fd)
		ft_putendl_fd(oper, fd);
}

void	rrotate(t_lst *lst, char *oper, int fd)
{
	if (!lst || !(lst->head) || !(lst->head->next))
		return ;
	lst->tail->next = lst->head;
	lst->head->prev = lst->tail;
	lst->tail = lst->tail->prev;
	lst->head = lst->head->prev;
	lst->head->prev = NULL;
	lst->tail->next = NULL;
	if (oper[2] != 'r' && fd)
		ft_putendl_fd(oper, fd);
}

void	rr(t_stack *stack, int fd)
{
	rotate(stack->a, "rr", fd);
	rotate(stack->b, "rr", fd);
	if (fd)
		ft_putendl_fd("rr", fd);
}

void	rrr(t_stack *stack, int fd)
{
	rrotate(stack->a, "rrr", fd);
	rrotate(stack->b, "rrr", fd);
	if (fd)
		ft_putendl_fd("rrr", fd);
}
