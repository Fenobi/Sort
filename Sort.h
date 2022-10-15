#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <time.h>


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

//�鲢����
//�ݹ�
void MergeSort(int* a, int n);
//�ǵݹ�
void MergeSortNonR(int* a, int n);

//��������
//�ʺϣ�
//���ݷ�Χ����
//ȱ�㣺
//ֻ�ʺ����������ʺϸ��������ַ�����
void CountSort(int* a, int n);