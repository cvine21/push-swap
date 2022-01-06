/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:45:13 by cvine             #+#    #+#             */
/*   Updated: 2022/01/03 22:36:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_lst *from, t_lst *to, char *oper, int fd)
{
	if (from->head)
		lstadd_front(to, pop(from));
	if (fd)
		ft_putendl_fd(oper, 1);
}
