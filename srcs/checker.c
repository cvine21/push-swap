/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:29 by cvine             #+#    #+#             */
/*   Updated: 2022/01/12 15:05:29 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ops(t_stack *stack, char *line)
{
	if (!ft_strncmp("sa", line, 2) && (!line[2] || line[2] == '\n'))
		swap(stack->a, "sa", 0);
	else if (!ft_strncmp("sb", line, 2) && (!line[2] || line[2] == '\n'))
		swap(stack->b, "sb", 0);
	else if (!ft_strncmp("ss", line, 2) && (!line[2] || line[2] == '\n'))
		ss(stack, 0);
	else if (!ft_strncmp("ra", line, 2) && (!line[2] || line[2] == '\n'))
		rotate(stack->a, "ra", 0);
	else if (!ft_strncmp("rb", line, 2) && (!line[2] || line[2] == '\n'))
		rotate(stack->b, "rb", 0);
	else if (!ft_strncmp("rra", line, 3) && (!line[3] || line[3] == '\n'))
		rrotate(stack->a, "rra", 0);
	else if (!ft_strncmp("rrb", line, 3) && (!line[3] || line[3] == '\n'))
		rrotate(stack->b, "rrb", 0);
	else if (!ft_strncmp("rr", line, 2) && (!line[2] || line[2] == '\n'))
		rr(stack, 0);
	else if (!ft_strncmp("rrr", line, 3) && (!line[3] || line[3] == '\n'))
		rrr(stack, 0);
	else if (!ft_strncmp("pa", line, 2) && (!line[2] || line[2] == '\n'))
		push(stack->b, stack->a, "pa", 0);
	else if (!ft_strncmp("pb", line, 2) && (!line[2] || line[2] == '\n'))
		push(stack->a, stack->b, "pb", 0);
	else
		error();
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
	if (is_sorted(stack, stack->a->head) && !stack->b->head)
		ft_putendl_fd(GREEN_OK, 1);
	else
		ft_putendl_fd(RED_KO, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	stack = create_stacks();
	fill_stack_a(stack, argc, argv);
	checker(stack);
	clear(stack, NULL);
	return (0);
}
