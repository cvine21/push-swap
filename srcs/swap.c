/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:55:15 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 16:55:18 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst *lst, char *oper, int fd)
{
	t_elem	*ptr;

	if (!lst || !(lst->head) || !(lst->head->next))
		return ;
	ptr = lst->head;
	lst->head = lst->head->next;
	ptr->next = lst->head->next;
	ptr->prev = lst->head;
	lst->head->next = ptr;
	lst->head->prev = NULL;
	if (lst->size > 2)
		ptr->next->prev = ptr;
	if (oper[1] != 's' && fd)
		ft_putendl_fd(oper, fd);
}

void	ss(t_stack *stack, int fd)
{
	swap(stack->a, "ss", fd);
	swap(stack->b, "ss", fd);
	if (fd)
		ft_putendl_fd("ss", fd);
}
