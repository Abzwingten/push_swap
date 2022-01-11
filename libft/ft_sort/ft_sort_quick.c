#include "libft.h"

int find_pivot(int arr[], int low, int high)
{
    int x = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= x) {
            i++;
            ft_intswap(&arr[i], &arr[j]);
        }
    }
    ft_intswap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    int aux_arr[high - low + 1];
	int top;
	
	top = -1;
    aux_arr[++top] = low;
    aux_arr[++top] = high;
    while (top >= 0) 
	{
        high = aux_arr[top--];
        low = aux_arr[top--];
        int p = find_pivot(arr, low, high);
        if (p - 1 > low)
		{
            aux_arr[++top] = low;
            aux_arr[++top] = p - 1;
        }
        if (p + 1 < high)
		{
            aux_arr[++top] = p + 1;
            aux_arr[++top] = high;
        }
    }
}