/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:10:18 by marvin            #+#    #+#             */
/*   Updated: 2022/01/02 17:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ops(t_stack *stack, char *line)
{
	if (!ft_strncmp("sa", line, 2))
		swap(stack->a, "sa", 0);
	else if (!ft_strncmp("sb", line, 2))
		swap(stack->b, "sb", 0);
	else if (!ft_strncmp("ss", line, 2))
		ss(stack, 0);
	else if (!ft_strncmp("ra", line, 2))
		rotate(stack->a, "ra", 0);
	else if (!ft_strncmp("rb", line, 2))
		rotate(stack->b, "rb", 0);
	else if (!ft_strncmp("rra", line, 3))
		rrotate(stack->a, "rra", 0);
	else if (!ft_strncmp("rrb", line, 3))
		rrotate(stack->b, "rrb", 0);
	else if (!ft_strncmp("rr", line, 2))
		rr(stack, 0);
	else if (!ft_strncmp("rrr", line, 3))
		rrr(stack, 0);
	else if (!ft_strncmp("pa", line, 2))
		push(stack->b, stack->a, "pa", 0);
	else if (!ft_strncmp("pb", line, 2))
		push(stack->a, stack->b, "pb", 0);
}

void	checker(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ops(stack, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack) && !stack->b->head)
		ft_putendl_fd(GREEN_OK, 1);
	else
		ft_putendl_fd(RED_KO, 1);
}

int main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	stack = create_stacks();
	fill_stack_a(stack, argc, argv);
	checker(stack);
	stclear(stack);
	return (0);
}

// int		num;
// t_elem	*tmp_a;
// t_elem	*tmp_b;
// num = argc;
// tmp_a = stack->a->head;
// tmp_b = stack->b->head;
// while(--num)
// {
// 	if (tmp_a)
// 	{
// 		printf("%d | ", tmp_a->val);
// 		tmp_a = tmp_a->next;
// 	}
// 	else
// 		printf("     | ");
// 	if (tmp_b)
// 	{
// 		printf("%d\n", tmp_b->val);
// 		tmp_b = tmp_b->next;
// 	}
// 	else
// 		printf("\n");
// }
// printf("----- -----\n  a     b\n");