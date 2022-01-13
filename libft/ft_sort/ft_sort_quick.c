/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:40:26 by rantario          #+#    #+#             */
/*   Updated: 2022/01/13 20:07:43 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_pivot(int arr[], int low, int high)
{
	int	x;
	int	i;
	int	j;

	x = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= x)
		{
			i++;
			ft_intswap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_intswap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	free_arr(int *aux_arr)
{
	if (!aux_arr)
	{
		free(aux_arr);
		exit(1);
	}
}

void	quick_sort(int *arr, int low, int high)
{
	int	*aux_arr;
	int	top;
	int	pivot;

	aux_arr = malloc(high - low + 1);
	free_arr(aux_arr);
	top = -1;
	aux_arr[++top] = low;
	aux_arr[++top] = high;
	while (top >= 0)
	{
		high = aux_arr[top--];
		low = aux_arr[top--];
		pivot = find_pivot(arr, low, high);
		if (pivot - 1 > low)
		{
			aux_arr[++top] = low;
			aux_arr[++top] = pivot - 1;
		}
		if (pivot + 1 < high)
		{
			aux_arr[++top] = pivot + 1;
			aux_arr[++top] = high;
		}
	}
}
