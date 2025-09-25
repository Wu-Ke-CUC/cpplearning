//#include<iostream>
//#include<string>
//using namespace std;
//void stringToIntArray(string s, int des[])
//{
//	for (int i = 0; i < s.length(); i++)
//	{
//		des[s.length() - i] = s[i] - '0';
//	}
//}
//void add(string s1,string s2,int ret[],int* lret)
//{
//	int a[101] = { 0 }, b[101] = { 0 };
//	stringToIntArray(s1, a);
//	stringToIntArray(s2, b);
//
//	*lret = max(s1.length(), s2.length()) + 1;
//
//	for (int i = 1; i <= *lret; i++)
//	{
//		ret[i] = a[i] + b[i] + ret[i];
//		ret[i + 1] = ret[i] / 10;
//		ret[i] %= 10;
//	}
//	while (ret[*lret] == 0 && *lret > 1)
//	{
//		(*lret)--;
//	}
//}
//void sub(string s1, string s2, int ret[], int* lret)
//{
//	int a[101] = { 0 }, b[101] = { 0 };
//	stringToIntArray(s1, a);
//	stringToIntArray(s2, b);
//
//	*lret = max(s1.length(), s2.length()) + 1;
//	if (s1.length()<s2.length()||(s1.length()==s2.length()&&s1<s2))
//	{
//		cout << '-';
//		return sub(s2, s1, ret, lret);
//	}
//	for (int i = 1; i <= *lret; i++)
//	{
//		ret[i] = a[i] - b[i] + ret[i];
//		if (ret[i] < 0)
//		{
//			ret[i] += 10;
//			ret[i + 1]--;
//		}
//	}
//	while (ret[*lret] == 0 && *lret > 1)
//	{
//		(*lret)--;
//	}
//}
//void mul(string s1, string s2, int ret[], int* lret)
//{
//	int a[101] = { 0 }, b[101] = { 0 };
//	stringToIntArray(s1, a);
//	stringToIntArray(s2, b);
//	*lret = s1.length() + s2.length();
//	for (int i = 1; i <= s1.length(); i++)
//	{
//		for (int j = 1; j <= s2.length(); j++)
//		{
//			ret[i + j - 1] += a[i] * b[j];
//			ret[i + j] += ret[i + j - 1] / 10;
//			ret[i + j - 1] %= 10;
//		}
//	}
//	while (ret[*lret] == 0 && *lret > 1)
//	{
//		(*lret)--;
//	}
//}
//void div(string s1, int n, int ret[], int* lret)
//{
//	int a[101] = { 0 };
//	stringToIntArray(s1, a);
//	*lret = s1.length();
//
//	for (int i = *lret; i >= 1; i--)
//	{
//		ret[i] = a[i] / n;
//		a[i - 1] += (a[i] % n) * 10;
//	}
//	//cout << a[0]/10 << endl;
//	while (ret[*lret] == 0 && *lret > 1)
//	{
//		(*lret)--;
//	}
//}
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int c[101] = { 0 };
//	int lc = 0;
//	//add(s1, s2, c, &lc);
//	//sub(s1, s2, c, &lc);
//	//mul(s1, s2, c, &lc);
//	//div(s1, 11, c, &lc);
//	for (int i = lc; i >= 1; i--)
//	{
//		cout << c[i];
//	}
//	return 0;
//}
// 
//倍增法求快速幂
#include<iostream>
using namespace std;
typedef long long ll;
ll Quick_Pow(ll a,ll b)
{
	ll ret = 1;
	while (b)
	{
		if ((b & 1) == 1)
		{
			ret *= a;
		}
		//a *= a;
		a = pow(a, 2);
		b >>= 1;
	}
	return ret;
}
int main()
{
	ll a, b;
	cin >> a >> b;
	cout << Quick_Pow(a, b);
	return 0;
}