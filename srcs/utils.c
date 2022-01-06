/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:52:56 by cvine             #+#    #+#             */
/*   Updated: 2022/01/05 15:29:49 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *array, int left, int right)
{
	int	pivot;
	int	lower;
	int	greater;

	if (left < right)
	{
		lower = left;
		greater = right;
		pivot = left;
		while (lower < greater)
		{
			while (array[lower] <= array[pivot] && lower < right)
				lower++;
			while (array[greater] > array[pivot])
				greater--;
			if (lower < greater)
				ft_swap(&array[lower], &array[greater]);
		}
		ft_swap(&array[pivot], &array[greater]);
		quicksort(array, left, greater - 1);
		quicksort(array, greater + 1, right);
	}
}
