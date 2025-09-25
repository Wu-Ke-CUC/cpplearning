#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//√∞≈›≈≈–Ú
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
//—°‘Ò≈≈–Ú
void selectSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
//≤Â»Î≈≈–Ú
void insertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				for (int k = i; k > j; k--)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = temp;
				break;
			}
		}
	}
}
void insertSort2(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				for (int k = i; k > j; k--)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = temp;
				break;
			}
		}
	}
}
//œ£∂˚≈≈–Ú
void shellInsert(int* arr, int start, int gap, int n)
{
	for (int i = start + gap; i < n; i += gap)
	{
		for (int j = start; j < i; j += gap)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				for (int k = i; k > j; k -= gap)
				{
					arr[k] = arr[k - gap];
				}
				arr[j] = temp;
				break;
			}
		}
	}
}
void shellSort(int* arr, int n)
{
	for (int gap = n / 2; gap >= 1; gap /= 2)
	{
		for (int i = 0; i < gap; i++)
		{
			shellInsert(arr, i, gap, n);
		}
	}
}
//º∆ ˝≈≈–Ú
void countSort(int* arr, int n)
{
	int maxVal = *max_element(arr, arr + n - 1);
	int* tempArr = new int[maxVal + 1]();
	for (int i = 0; i < n; i++)
	{
		tempArr[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i <= maxVal; i++)
	{
		while (tempArr[i] > 0)
		{
			arr[index++] = i;
			tempArr[i]--;
		}
	}
	delete[] tempArr;
}
//Õ∞≈≈–Ú
void bucketSort(vector<int> vec)
{
	int maxVal = *max_element(vec.begin(),vec.end());
	int minVal = *min_element(vec.begin(), vec.end());
	int bucketNum = (maxVal - minVal + 1) / vec.size();
	vector<vector<int>> buckets(bucketNum);
	for (int i = 0; i < vec.size(); i++)
	{
		int index = (vec[i] - minVal + 1) / vec.size();
		buckets[index].push_back(vec[i]);
	}
	for (int i = 0; i < buckets.size(); i++)
	{
		sort(buckets[i].begin(), buckets[i].end());
	}
	for (int i = 0; i < buckets.size(); i++)
	{
		for (int j = 0; j < buckets[i].size(); j++)
		{
			vec.push_back(buckets[i][j]);
		}
	}
}
//∂—≈≈–Ú
void maxHead(vector<int>& vec, int start, int end)
{
	int cur = start;
	for (int l = 2 * cur + 1; l <= end; cur = l, l = 2 * cur + 1)
	{
		if (l < end && vec[l] < vec[l + 1])
		{
			l++;
		}
		if (vec[cur] < vec[l])
		{
			swap(vec[cur], vec[l]);
		}
		else
		{
			break;
		}
	}
}
void headSort(vector<int>& vec)
{
	for (int i = vec.size() / 2 - 1; i >= 0; i--)
	{
		maxHead(vec, i, vec.size() - 1);
	}
	for (int i = vec.size() - 1; i > 0; i--)
	{
		swap(vec[0], vec[i]);
		maxHead(vec, 0, i - 1);
	}
}
//øÏÀŸ≈≈–Ú
void quickSort(vector<int>& vec, int l, int r)
{
	if (l >= r)return;
	int base = vec[l];
	int i = l, j = r;
	while (i != j)
	{
		while (i < j && vec[j] >= base) j--;
		if (i < j)vec[i++] = vec[j];
		while (i < j && vec[i] <= base) i++;
		if (i < j)vec[j--] = vec[i];
	}
	vec[i] = base;
	quickSort(vec, l, i - 1);
	quickSort(vec, i + 1, r);
}
//πÈ≤¢≈≈–Ú
void mergeSort(vector<int>& vec, int l, int mid, int r)
{
	vector<int> temp(r - l + 1);
	int i = l, j = mid + 1, index = 0;
	while (i <= mid && j <= r)
	{
		if (vec[i] <= vec[j])
		{
			temp[index++] = vec[i++];
		}
		else
		{
			temp[index++] = vec[j++];
		}
	}
	while (i <= mid)
	{
		temp[index++] = vec[i++];
	}
	while (j <= r)
	{
		temp[index++] = vec[j++];
	}
	for (int k = 0; k < index; k++)
	{
		vec[l + k] = temp[k];
	}
}
void mergeUoDown(vector<int>& vec, int l, int r)
{
	if (l >= r)return;
	int mid = (l + r) / 2;
	mergeUoDown(vec, l, mid);
	mergeUoDown(vec, mid + 1, r);
	mergeSort(vec, l, mid, r);
}

int main()
{
	int arr[] = { 20,40,0,30,10,60,50,70 };
	int n = sizeof(arr) / sizeof(int);
	vector<int> vec(arr, arr + n);
	//bubbleSort(arr, n);
	//selectSort(arr,n);
	//insertSort(arr, n);
	//shellSort(arr, n);
	//countSort(arr, n);
	//bucketSort(arr, n);
	/*for (int i = 0; i < n ; i++)
	{
		cout << arr[i] << " ";
	}*/
	//insertSort2(vec);
	//headSort(vec);
	//quickSort(vec, 0, vec.size() - 1);
	mergeUoDown(vec, 0, vec.size() - 1);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	return 0;
}