#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct AVLTreeNode
{
	int data;
	int height;
	AVLTreeNode* lchild;
	AVLTreeNode* rchild;
};

class AVLTree {
public:
	AVLTree() {
		root = new AVLTreeNode;
		root->lchild = NULL;
		root->rchild = NULL;
		root->height = 1;
		root->data = 0;
	}
	AVLTreeNode* insert(AVLTreeNode *&p, int &a);
	void create(vector<int> &a) {
		int i=1;
		root->data = a[0];
		AVLTreeNode *p = root;
		for (; i < a.size(); i++) {
			insert(root, a[i]);
		}
	}
	int find(int &a);
	void output() {
		return midorder(root);
	}
private:
	AVLTreeNode *root;
	int Height(AVLTreeNode *t) {
		int h = 0;
		if (t != NULL) {
			int left_height = Height(t->lchild);
			int right_height = Height(t->rchild);
			h = left_height > right_height ? left_height + 1 : right_height + 1;
		}
		return h;
	}
	void midorder(AVLTreeNode *p);
	AVLTreeNode *left(AVLTreeNode *p){
		AVLTreeNode* pr = p->rchild;
		p->rchild = pr->lchild;
		pr->lchild = p;
		p->height = Height(p);
		pr->height = Height(pr);
		return pr;
	}
	AVLTreeNode *right(AVLTreeNode *p){
		AVLTreeNode* pl = p->lchild;
		p->lchild = pl->rchild;
		pl->rchild = p;
		p->height = Height(p);
		pl->height = Height(pl);
		return pl;
	}
	AVLTreeNode *rightleft(AVLTreeNode *p){
		p->rchild = right(p->rchild);
		return left(p);
	}
	AVLTreeNode *leftright(AVLTreeNode *p){
		p->lchild = left(p->lchild);
		return right(p);
	}
};
AVLTreeNode* AVLTree::insert(AVLTreeNode *&p, int &x) {

	if (p == NULL) {
		AVLTreeNode *q = new AVLTreeNode;
		q->data = x;
		q->height = 1;
		q->lchild = NULL;
		q->rchild = NULL;
		return q;
	}
	else if (x > p->data) {
		
		p->rchild = insert(p->rchild, x);
		if (Height(p->rchild) - Height(p->lchild) == 2) {
			if (x > p->rchild->data) { //插入右子树的右孩子,左旋
				p = left(p);
			}
			else if (x < p->rchild->data) {//插入右子树的左孩子，先右再左
				p = rightleft(p);
			}
		}
	}
	else if (x < p->data) {
		p->lchild = insert(p->lchild, x);
		if (Height(p->lchild) - Height(p->rchild) == 2) {
			if (x < p->lchild->data) {//插入左子树的左孩子，右旋
				p = right(p);
			}
			else if (x > p->lchild->data) {//插入左子树的右孩子，先左后右
				p = leftright(p);
			}
		}
	}
	p->height = Height(p);
	return p;
}

int AVLTree::find(int &k) {
	stack<AVLTreeNode*> s;
	AVLTreeNode *p = root;
	int i = 0;
	while (s.size() != 0 || p != NULL) {
		while (p != NULL) {
			s.push(p);
			p = p->lchild;
		}
		if (s.size()!= 0){
		p = s.top();
		s.pop();
		i++;
		if (i == k)
			return p->data;
		p = p->rchild;
        }
	}
	return -1;
}

void AVLTree::midorder(AVLTreeNode *p) {
	if (p == NULL) return;
	midorder(p->lchild);
	cout << p->data << " ";
	midorder(p->rchild);
}

int main() {
	AVLTree tree;
	vector<int> a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	tree.create(a);
	cin.clear();
	tree.output();
	int k;
	cin >> k;
	cout << tree.find(k) << endl;
	return 0;
}
