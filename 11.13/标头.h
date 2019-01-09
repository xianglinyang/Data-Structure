#pragma once
#ifndef BITNODE_INCLUDED_
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode;
class Tree {
private:
	BiTNode root;
public:
	stack<BiTNode*> s;
	void Preorder(BiTNode *root) {
		if (root == NULL) return;
		s.push(root);
		while (!s.empty()) {
			root = s.top();
			s.pop();
			putchar(root->data);
			if (root->rchild != NULL) s.push(root->rchild);
			if (root->lchild != NULL) s.push(root->lchild);
		}
	}
	BiTNode* getLCA(BiTNode*root, char x, char y) {
		if (!root)return NULL;
		if (root->data == x || root->data == y) return root;
		BiTNode* L = getLCA(root->lchild, x, y);
		BiTNode* R = getLCA(root->rchild, x, y);
		if (L&&R) return root;
		else return L ? L : R;
	}
	int max(int i, int j) {
		return i > j ? i : j;
	}
	int MaxDistance(BiTNode* root, int& maxLeft, int& maxRight)
	{
		//maxLeft, 左子树中的节点距离根节点的最远距离
		//maxRight, 右子树中的节点距离根节点的最远距离
		if (root == NULL)
		{
			maxLeft = 0;
			maxRight = 0;
			return 0;
		}
		int maxLL, maxLR, maxRL, maxRR;
		int maxDistLeft, maxDistRight;
		if (root->lchild != NULL)
		{
			maxDistLeft = MaxDistance(root->lchild, maxLL, maxLR);
			maxLeft = max(maxLL, maxLR) + 1;
		}
		else
		{
			maxDistLeft = 0;
			maxLeft = 0;
		}
		if (root->rchild != NULL)
		{
			maxDistRight = MaxDistance(root->rchild, maxRL, maxRR);
			maxRight = max(maxRL, maxRR) + 1;
		}
		else
		{
			maxDistRight = 0;
			maxRight = 0;
		}
		return max(max(maxDistLeft, maxDistRight), maxLeft + maxRight);
	}
};

#endif


