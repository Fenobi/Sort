#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS 

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void InsertSort(int* a, int n)
{
	// [0,end]插入end+1 [0，end+1]有序
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int i = 1;
	while (n > i)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		i++;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = end;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void BuobleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}


int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


int PartSort(int* a, int left, int right)
{
	//三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;
	while (left < right)
	{
		//找小
		while (a[keyi] <= a[right] && left < right)
		{
			right--;
		}
		//找大
		while (a[keyi] >= a[left] && left < right)
		{
			left++;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}
//挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (a[right] >= key && left < right)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (a[left] <= key && left < right)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return left;
}
//前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int prev = left, cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	if (end - begin <= 8)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	//插入数表示区间
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
{
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

if (left >= right)
{
	continue;
}

int keyi = PartSort3(a, left, right);
if (keyi + 1 < right)
{
	StackPush(&st, keyi + 1);
	StackPush(&st, right);
}
if (left < right - 1)
{
	StackPush(&st, left);
	StackPush(&st, keyi - 1);
}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;

	//递归范围[begin,mid] [mid+1,end]
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	//归并 取小的尾插
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int j = 0; j < n; j += gap * 2)
		{
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + 2 * gap - 1;

			//第一组越界
			if (end1 >= n)
			{
				break;
			}

			//第二组全部越界
			if (begin2 >= n)
			{
				break;
			}

			//第二组部分越界
			if (end2 >= n)
			{
				//修正end2，继续归并
				end2 = n - 1;
			}

			int i = j;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}

			memcpy(a + j, tmp + j, sizeof(int)*(end2 - j + 1));
		}

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* countA = (int*)calloc(range, sizeof(int));
	if (countA == NULL)
	{
		perror("calloc fail");
		exit(-1);
	}

	for (int i = 0; i < n; i++)
	{
		countA[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(countA);
	countA = NULL;
}

