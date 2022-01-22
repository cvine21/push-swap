/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:52:53 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:40:29 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_ops	*ops;

	stack = NULL;
	ops = NULL;
	if (argc == 1)
		return (0);
	stack = create_stacks();
	fill_stack_a(stack, argc, argv);
	if (argc > 4)
	{
		markup(stack);
		ops = create_t_ops();
		distribute_a(stack);
		distribute_b(stack, ops);
		sort(stack);
	}
	else
		minisort(stack);
	clear(stack, ops);
	return (0);
}
