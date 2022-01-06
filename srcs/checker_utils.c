/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:52:50 by cvine             #+#    #+#             */
/*   Updated: 2022/01/05 16:24:33 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(int *array)
{
	ft_putendl_fd("Error", 2);
	free(array);
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	int		flag;
	int		prev;
	int		next;
	int		size;
	t_elem	*tmp;

	flag = 1;
	tmp = stack->a->head;
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

void	check_for_int(long rep, int minus, int *array)
{
	if (rep * minus < -2147483648 || rep * minus > 2147483647)
		error(array);
}

void	check_for_digit(char arg, int *array)
{
	if (!ft_isdigit(arg) && arg)
		error(array);
}

void	check_for_dup(int argc, int *array)
{
	size_t	i;

	i = 0;
	while (--argc)
	{
		if (array[i] == array[i + 1])
			error(array);
		i++;
	}
}
