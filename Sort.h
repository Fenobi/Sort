#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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

//��������  horer
int GetMidIndex(int* a, int left, int right);
void QuickSort(int* a, int begin, int end);
