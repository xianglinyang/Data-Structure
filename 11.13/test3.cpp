/*3.�����ı������ڱ�ǰ����ʾ���ĸ���㣬�������Ǹ�������������
ÿ���������������ö��Ÿ�����������������û�������������Ų���ʡ�ԡ�
������������ʾ����Ľ�β����һ��������š�#������ʾ���������
���磺A(B(D, E(G, )), C(, F))#*/

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
	BinNode<T> *first;//���ڵ�ָ��
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
			if (count != 0) {//�ұ�û�����ݣ�����������Ϊ��
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
			if (count == 0) {//˵����������
				p->lchild = q;
				t = p;
				p = q;
				count++;
			}
			else {//������
				p = t;
				p->rchild = q;
				p = q;
				count = 0;
			}
		}
		else if (ch == ',') {
			if (count == 0) {//˵�����û�����ݣ�����������Ϊ��
				p->lchild = NULL;
				t = p;
			}
			count++;//�������Ѵ���,����������

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