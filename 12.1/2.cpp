#include<iostream>
#include<vector>
using namespace std;
void create(istream& in, vector<int> &a, int &i) {
	int data;
	while (in >> data) {
		a.push_back(data);
		i++;
	}
	i--;
}
int find_mid(vector<int> &a, vector<int> &b, int i, int j) {
	int a_mid, b_mid;
	int a_low = 0, a_high = i, b_low = 0, b_high = j;
	while (1) {
		a_mid = (a_low + a_high) / 2;
		b_mid = (b_low + b_high) / 2;
		if (a[a_mid] < b[b_mid]) {
			a_low = a_mid;
			b_high = b_mid;
		}
		else {
			a_high = a_mid;
			b_low = b_mid;
		}
		if (a_low == a_high&&b_low == b_high)
			return a[a_low] <= b[b_low] ? a[a_low] : b[b_low];
		if (a_low + 1 == a_high&&b_low + 1 == b_high) {
			if (a[a_low] < b[b_low]) a_low++;
			else b_low++;
			return a[a_low] < b[b_low] ? a[a_low] : b[b_low];
		}
	}
}
int main() {
	vector<int> a, b;
	int i = 0, j = 0, x;
	int Mid;
	create(cin, a, i);
	cin.clear();
	create(cin, b, j);
	Mid = find_mid(a, b, i, j);
	cout << "中位数为：" << Mid << endl;
	return 0;
}
