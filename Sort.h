#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void print(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//冒泡排序
void BuobleSort(int* a, int n);

//推排序
void HeapSort(int* a, int n);

//希尔排序(插入排序的优化)
void ShellSort(int* a, int n);

//快速排序  horer
int GetMidIndex(int* a, int left, int right);
void QuickSort(int* a, int begin, int end);
