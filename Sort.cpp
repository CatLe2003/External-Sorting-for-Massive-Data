#include "Sort.h"

void quickSort(Book* arr, int left, int right)
{
	Book pivot = arr[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while (arr[i].id < pivot.id) ++i;
		while (arr[j].id > pivot.id) --j;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}
