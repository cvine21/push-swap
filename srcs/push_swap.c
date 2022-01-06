/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:52:53 by cvine             #+#    #+#             */
/*   Updated: 2022/01/06 11:32:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_ops	*ops;
	
	// return (0);
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
	// printf("%d\n", stack->markup_start->val);
	// while(--argc)
	// {
	// 	if (stack->a->head)
	// 	{
	// 		printf("%d(%d) | ", stack->a->head->val, stack->a->head->flag);
	// 		stack->a->head = stack->a->head->next;
	// 	}
	// 	else
	// 		printf("     | ");
	// 	if (stack->b->head)
	// 	{
	// 		printf("%d\n", stack->b->head->val);
	// 		stack->b->head = stack->b->head->next;
	// 	}
	// 	else
	// 		printf("\n");
	// }
	// printf("----- -----\n  a     b\n");
	stclear(stack);
	return (0);
}
