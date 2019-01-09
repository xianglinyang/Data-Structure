#pragma once
#include<iostream>
using namespace std;
class BinTree;
class Node {
	friend class BinTree;
private:
	int data,ltag,rtag;
	Node *lchild, *rchild;
public:
	Node() {
		lchild = NULL;
		rchild = NULL;
		ltag = 0;
		rtag = 0;
	}
	~Node(){}
};
class BinTree {
private:
	Node *root;
public:
	BinTree() {
		root = new Node;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	~BinTree(){}
	void CreateTree(istream& in) {
		int temp;
		in >> temp;
		root->data = temp;
		Node *head,*q;
		head = root;
		while (in >> temp) {
			Node *p = new Node();
			p->data = temp;
			q = head;
			while (1) {
				if (p->data < q->data) {
					if (q->lchild) q = q->lchild;
					else break;
				}
				else {
					if (q->rchild) q = q->rchild;
					else break;
				}
			}
			if (p->data < q->data) q->lchild = p;
			else q->rchild = p;
		}
	}
	void CreateInThread(Node *t,Node *& pre) {     //tΪ��
		if (t == NULL) return;
		CreateInThread(t->lchild, pre); //������������
		if (t->lchild == NULL) {
			t->lchild = pre;     if (pre != NULL) t->ltag = 1;
		}   //������ǰ����ǰ������	
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = t;     pre->rtag = 1;
		}   //����ǰ�����ĺ������
		pre = t;	//ǰ�����ϵ�ǰָ��
		CreateInThread(t->rchild, pre);  //������������
	}
	void createInThread() {
		Node *pre = NULL;
		CreateInThread(root, pre);
	}
	Node *succ(Node *t) {
		if (t->rtag == 1 || t->rchild == NULL) return t->rchild;
		t = t->rchild;
		while (t->ltag == 0) t = t->lchild;
		return t;
	}
	void midorder() {
		while (root != NULL) {
			cout << root->data << " ";
			root = succ(root);
		}
	}
};