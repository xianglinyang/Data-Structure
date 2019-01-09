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
		if (node->ltag == 0) return node->lchild;//有左子树就返回
		else return node->rchild;//有线索或者没有左子树但是有右子树或者右子树为空
	}
};

