#include<iostream>
#include"Stack.h"
using namespace std;
bool IsTrue(int a[], int b[]) {
	int i = 0, j = 0;
	Stack<int> temp;
	for (i = 0; i < 6 && j < 6;) {
		temp.push(a[j]);
		if (temp.GetTop() == b[i]) {
			temp.pop();
			i++;
		}
		j++;
	}
	if (temp.isEmpty()) return true;
	else return false;
}
void GetSeq(int a[6]) {
	for (int i = 0; i < 6; i++) cin >> a[i];
}
void PrintSeq(int a[]) {
	for (int i = 0; i < 6; i++) cout << a[i] << " ";
	cout << endl;
}
int main() {
	int a[6], b[6];
	GetSeq(a);
	GetSeq(b);
	if (IsTrue(a, b)) cout << "True" << endl;
	else cout << "False" << endl;
	return 0;


}
