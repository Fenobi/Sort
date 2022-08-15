#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

void print(int* a, int n);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

//√∞≈›≈≈–Ú
void BuobleSort(int* a, int n);

//Õ∆≈≈–Ú
void HeapSort(int* a, int n);

//œ£∂˚≈≈–Ú(≤Â»Î≈≈–Úµƒ”≈ªØ)
void ShellSort(int* a, int n);

//øÏÀŸ≈≈–Ú  
//µ›πÈ
void QuickSort(int* a, int begin, int end);
//∑«µ›πÈ
void QuickSortNonR(int* a, int begin, int end);