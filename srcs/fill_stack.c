/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:08 by cvine             #+#    #+#             */
/*   Updated: 2022/01/06 11:01:46 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_lst	*lst, int *array, int num)
{
	t_elem	*el;
	ssize_t	i;

	i = 0;
	el = lst->head;
	quicksort(array, 0, num - 2);
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

int	ps_atoi(char *arg, int *array)
{
	long	rep;
	int		minus;

	rep = 0;
	minus = 1;
	if (!*arg)
		exit(0);
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
			check_for_int(rep, minus, array);
			arg++;
		}
	}
	else
		error(array);
	if (!ft_isdigit(*arg) && *arg != '\0')
		error(array);
	return (rep * minus);
}

int	*get_array(int *array, char **argv, int argc)
{
	int	i;

	i = 0;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	while (--argc)
	{
		array[i] = ps_atoi(argv[i + 1], array);
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
