/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:52:50 by cvine             #+#    #+#             */
/*   Updated: 2022/01/15 11:07:40 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack, t_elem *head)
{
	int		flag;
	int		prev;
	int		next;
	int		size;
	t_elem	*tmp;

	flag = 1;
	tmp = head;
	prev = tmp->val;
	size = stack->a->size;
	while (size && flag)
	{
		next = tmp->val;
		if (next < prev)
			flag = 0;
		prev = next;
		tmp = tmp->next;
		size--;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	check_for_int(long rep, int minus)
{
	if (rep * minus < -2147483648 || rep * minus > 2147483647)
		error();
}

void	check_for_dup(int argc, int *array)
{
	size_t	i;

	i = 0;
	while (--argc)
	{
		if (array[i] == array[i + 1])
			error();
		i++;
	}
}
