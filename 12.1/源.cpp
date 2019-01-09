#include<iostream>
#include<vector>
#include"БъЭЗ.h"
using namespace std;
int main() {
	BinTree tree;
	tree.CreateTree(cin);
	tree.createInThread();
	tree.midorder();
}
