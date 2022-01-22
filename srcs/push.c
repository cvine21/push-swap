/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:45:13 by cvine             #+#    #+#             */
/*   Updated: 2022/01/12 16:32:01 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_lst *from, t_lst *to, char *oper, int fd)
{
	if (from->head)
		lstadd_front(to, pop(from));
	if (fd)
		ft_putendl_fd(oper, fd);
}
