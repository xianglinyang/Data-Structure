#include<iostream>
#include<vector>
#include"��ͷ.h"
using namespace std;
int main() {
	BinTree tree;
	tree.CreateTree(cin);
	tree.createInThread();
	tree.midorder();
}
