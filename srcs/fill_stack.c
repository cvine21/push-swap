/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:08 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 16:36:52 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_lst	*lst, int *array, int num)
{
	t_elem	*el;
	ssize_t	i;

	i = 0;
	el = lst->head;
	quicksort_array(array, 0, num - 2);
	check_for_dup(num - 1, array);
	while (el)
	{
		if (el->val == array[i])
		{
			el->index = i;
			el = el->next;
			i = -1;
		}
		i++;
	}
}

int	ps_atoi(char *arg)
{
	long	rep;
	int		minus;

	rep = 0;
	minus = 1;
	if (!*arg)
		error();
	while ((9 <= *arg && *arg <= 13) || *arg == 32)
		arg++;
	if (*arg == '-')
		minus = -1;
	if (*arg == '-' || *arg == '+')
		arg++;
	if (ft_isdigit(*arg))
	{
		while (ft_isdigit(*arg))
		{
			rep = rep * 10 + (*arg - 48);
			check_for_int(rep, minus);
			arg++;
		}
	}
	if (*arg != '\0' || (!*arg && !ft_isdigit(*(--arg))))
		error();
	return (rep * minus);
}

int	*get_array(int *array, char **argv, int argc)
{
	int	i;

	i = 0;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		error();
	while (--argc)
	{
		array[i] = ps_atoi(argv[i + 1]);
		i++;
	}
	return (array);
}

void	fill_stack_a(t_stack *stack, int argc, char **argv)
{
	int		*array;
	int		num;

	array = NULL;
	num = argc;
	array = get_array(array, argv, argc);
	while (--argc)
		lstadd_front(stack->a, array[argc - 1]);
	assign_index(stack->a, array, num);
	free(array);
}
