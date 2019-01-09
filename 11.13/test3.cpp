/*3.广义表的表名放在表前，表示树的根结点，括号中是根的左、右子树。
每个结点的左、右子树用逗号隔开。若仅有右子树没有左子树，逗号不能省略。
在整个广义表表示输入的结尾加上一个特殊符号“#”，表示输入结束。
例如：A(B(D, E(G, )), C(, F))#*/

#include<iostream>
#include<istream>
#include<string>
using namespace std;
template<class T> class GenTree;
template <class T> struct BinNode {
	friend class GenTree<T>;
	T data;
	BinNode <T> *lchild;
	BinNode <T> *rchild;
};


template<class T> class GenTree {
	friend istream& operator>>(istream &in, GenTree<T> t);
private:
	BinNode<T> *first;//根节点指针
	void CreateBinTree(istream &in, BinNode <char> *&BT);
	void preOrder(BinNode<char> *root) {
		if (root == NULL) return;
		cout << root->data;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
public:
	GenTree();
	~GenTree() { }
	void preorder() {
		preOrder(first);
	}

};



template<class T> GenTree<T> ::GenTree() {
	first = new BinNode<T>;
	first->data = 0;
	first->lchild = NULL;
	first->rchild = NULL;
}

template<class T> void GenTree<T>::CreateBinTree(istream &in, BinNode <char> *&BT) {
	char ch;
	if (first->data == 0) {
		in >> ch;
		first->data = ch;
	}
	BinNode<char> *p = BT;
	BinNode<char> *t = p;
	int count = 0;
	while (in >> ch) {
		if (ch == '(') {
			CreateBinTree(in, p);
		}
		else if (ch == ')') {
			if (count != 0) {//右边没有数据，所以右子树为空
				p->rchild = NULL;
				count = 0;
			}

			return;
		}
		else if ((ch >= 'A'&& ch <= 'Z') || (ch >= 'a' &&ch <= 'z')) {
			BinNode<char> *q;
			q = new BinNode<char>;
			q->data = ch;
			q->lchild = NULL;
			q->rchild = NULL;
			if (count == 0) {//说明是左子树
				p->lchild = q;
				t = p;
				p = q;
				count++;
			}
			else {//右子树
				p = t;
				p->rchild = q;
				p = q;
				count = 0;
			}
		}
		else if (ch == ',') {
			if (count == 0) {//说明左边没有数据，所以左子树为空
				p->lchild = NULL;
				t = p;
			}
			count++;//左子树已处理,进入右子树

		}
		else if (ch == '#')
			return;
	}
}

istream& operator>>(istream &in, GenTree<char> t) {
	t.CreateBinTree(in, t.first);
	return in;
}



int main() {
	GenTree<char> tree;
	cin >> tree;
	tree.preorder();
	return 0;
}