#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int N = 20;
int q[N];
int cont = 0;
int find(int i, int k)
{
	int j = 1;
	while (j<i)
	{
		if (q[j] == k || abs(j - i) == abs(q[j] - k))
			return 0;
		j++;
	}
	return 1;
}
void print(int *q, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (q[i] == j) cout << "1";
			else cout << "0";
		}
		cout << endl;
	}
	cout << endl;
}
void place(int k, int n)
{
	int j;
	if (k > n) { cont++; print(q, n); }
	else {
		for (j = 1; j <= n; j++)
		{
			if (find(k, j))
			{
				q[k] = j;
				place(k + 1, n);
			}
		}
	}
}

int main(void)
{
	cout << "ÇëÊäÈën£º";
	int n;
	cin >> n;
	place(1, n);
	system("pause");
	return 0;
}