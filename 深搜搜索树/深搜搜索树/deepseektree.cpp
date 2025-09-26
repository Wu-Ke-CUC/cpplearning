#include<iostream>
using namespace std;
int n = 3, K = 2, S = 6;
bool flag = false;
void dfs(int* arr,int k = 0,int sum = 0,int dep = 1)
{
	if (k == K)
	{
		if (sum == S)flag = true;
		return;
	}
	if (sum >= S)return;
	if (dep == n + 1)return;
	dfs(arr, k + 1, sum + arr[dep], dep + 1);
	if (flag == true)return;
	dfs(arr, k, sum, dep + 1);
}
void dfs1()
{

}
int main()
{
	int* a = new int[n + 1];
	for (int i = 1; i <= n; i++)cin >> a[i];
	dfs(a);
	cout << (flag ? "Yes" : "No");
	return 0;
}