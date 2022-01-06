/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:44:09 by cvine             #+#    #+#             */
/*   Updated: 2022/01/05 15:30:12 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define GREEN_OK "\x1b[32mOK"
# define RED_KO "\x1b[31mKO"
# define RED_ERROR "\x1b[31mError"

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct s_elem
{
	int				val;
	ssize_t			index;
	int				flag;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

typedef struct s_lst
{
	size_t	size;
	t_elem	*head;
	t_elem	*tail;
}	t_lst;

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
	size_t	keep_in_a;
	t_elem	*markup_start;
}	t_stack;

typedef struct s_ops
{
	t_elem	*opt_elem;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		least_amount;
}	t_ops;

int		is_sorted(t_stack *stack);
void	calc_ops(t_stack *stack, t_elem *current, t_ops *ops, t_elem *tmp);
void	sort(t_stack *stack);
void	minisort(t_stack *stack);
void	distribute_b(t_stack *stack, t_ops *ops);
t_elem	*find_opt_el(t_stack *stack, t_ops *ops);
int		find_opt_comb(t_stack *stack, t_elem *current, t_ops *ops, t_elem *tmp);
t_ops	*create_t_ops(void);
void	markup(t_stack *stack);
void	distribute_a(t_stack *stack);

t_stack	*create_stacks(void);
void	lstadd_front(t_lst *lst, int val);
int		pop(t_lst *lst);
void	stclear(t_stack *stack);

void	error(int *array);
void	check_for_digit(char arg, int *array);
void	check_for_int(long rep, int minus, int *array);
void	check_for_dup(int argc, int *array);

void	fill_stack_a(t_stack	*stack, int argc, char **argv);
void	quicksort(int *array, int left, int right);

void	swap(t_lst *lst, char *oper, int fd);
void	ss(t_stack *stack, int fd);
void	rotate(t_lst *lst, char *oper, int fd);
void	rr(t_stack *stack, int fd);
void	rrotate(t_lst *lst, char *oper, int fd);
void	rrr(t_stack *stack, int fd);
void	push(t_lst *from, t_lst *to, char *oper, int fd);

#endif
