#define _CRT_SECURE_NO_WARNINGS 

#include "Sort.h"

int main()
{
	int arr[] = { 5,4,9,8,1,6,2,3,7,0,-1,-2,-2,-5,1,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, n);
	//SelectSort(arr, n);
	//BuobleSort(arr, n);
	//ShellSort(arr, n);
	//HeapSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//QuickSortNonR(arr, 0, n - 1);
	//MergeSort(arr, n);
	//MergeSortNonR(arr, n);
	//CountSort(arr, n);
	print(arr, n);
	return 0;
}