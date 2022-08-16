#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

void print(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ð������
void BuobleSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//ϣ������(����������Ż�)
void ShellSort(int* a, int n);

//��������  
//�ݹ�
void QuickSort(int* a, int begin, int end);
//�ǵݹ�
void QuickSortNonR(int* a, int begin, int end);