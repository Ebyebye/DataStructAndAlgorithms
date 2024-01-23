#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10

void show_arr(int *arr_name, int arr_len)
{
	int index;
	for (index = 0; index < arr_len; ++index)
	{
		printf("%d ", arr_name[index]);
	}
	printf("\n");
}


// 数组元素初始化
void init_arr(int *arr_name, int arr_len)
{
	int index;
	
	srand(time(NULL));

	for (index = 0; index < arr_len; ++index)
	{
		arr_name[index] = rand() % 30;
	};
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


// 冒泡排序
void bubbling_sort(int *arr_name, int arr_len)
{
	int pass;
	// 外层循环：逐趟扫描
	// pass > 1是因为只有一个元素的数组是有序的
	for (pass = arr_len; pass > 1; --pass)
	{
		int swapped = 0;
		// 内层循环：比较相邻元素的大小
		for (int compare = 1; compare < pass; ++compare)
		{
			if (arr_name[compare - 1] > arr_name[compare])
			{
				swap(&arr_name[compare - 1], &arr_name[compare]);
				swapped = 1;
			}
		}
		if (!swapped) break; // 若没有发生交换，结束
	}	
}
int main(void)
{
	int arr[ARR_SIZE] = {0};

	init_arr(arr, ARR_SIZE);
	show_arr(arr, ARR_SIZE);

	bubbling_sort(arr, ARR_SIZE);
	show_arr(arr, ARR_SIZE);

	return 0;
}
