#pragma once
#include<iostream>
using namespace std;
typedef struct BiThrNode{
	char data;
	struct BiThrNode *lchild,*rchild;
	int ltag, rtag;
}BiThrNode;
class BiThrTree {
private:
	BiThrNode *root;
public:
	BiThrNode *PreOrderFindNext(BiThrTree T, BiThrNode *node) {
		if (node->ltag == 0) return node->lchild;//���������ͷ���
		else return node->rchild;//����������û������������������������������Ϊ��
	}
};

