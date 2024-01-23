#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void show_arr(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insert_sort(int *arr, int size)
{
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j+1] = arr[j];
		
		}

		arr[j + 1] = temp;
	}
}


int main(void)
{
	//1.创建一个数组
	int arr[SIZE] = {0};
	int element;

	int i;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		element = rand() % 30;
		arr[i] = element;
	}

	//2.输出数组中的元素
	show_arr(arr, SIZE);

	//3.实现排序
	insert_sort(arr, SIZE);

	//4.输出排好序的数组
	show_arr(arr, SIZE);
}
