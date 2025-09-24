#include<iostream>
using namespace std;
int climbFloor(int n)
{
	/*if (n <= 0)return 0;
	else if (n <= 2 && n > 0)return n;
	else return climbFloor(n - 1) + climbFloor(n - 2);*/
	int* ways = new int[n + 1] {0};
	if (n == 1)
	{
		ways[1] = 1;
	}
	else
	{
		ways[1] = 1;
		ways[2] = 2;
	}
	for (int i = 3; i <= n; i++)
	{
		ways[i] = ways[i - 1] + ways[i - 2];
	}
	return ways[n];
}
int countPlane(int n)
{
	if (n < 0)return NULL;
	else if (n == 0)return 1;
	else return countPlane(n - 1) + n;
}
int YangHui_Triangle(int n, int m)
{
	if (m > n)return 0;
	if (m == 1 || m == n)return 1;
	return YangHui_Triangle(n - 1, m) + YangHui_Triangle(n - 1, m - 1);
}
int main()
{
	/*int ways[101] = { 0 };
	int n;
	cin >> n;
	cout << climbFloor(n);*/
	//int plane = countPlane(n);
	//cout << plane;
	/*ways[2] = 1;
	for (int i = 3; i <=  n; i++)
	{
		ways[i] = (i - 1) * (ways[i - 1] + ways[i - 2]);
	}
	cout << ways[n];*/
	cout << YangHui_Triangle(5, 3);
}