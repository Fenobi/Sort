#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <time.h>


void print(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//冒泡排序
void BuobleSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//希尔排序(插入排序的优化)
void ShellSort(int* a, int n);

//快速排序  
//递归
void QuickSort(int* a, int begin, int end);
//非递归
void QuickSortNonR(int* a, int begin, int end);

//归并排序
//递归
void MergeSort(int* a, int n);
//非递归
void MergeSortNonR(int* a, int n);

//计数排序
//适合：
//数据范围集中
//缺点：
//只适合整数，不适合浮点数、字符串等
void CountSort(int* a, int n);