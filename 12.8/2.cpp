#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int data;
	Node *right;
	Node *left;

};
void create(vector<int> &a, Node *&t) {
	t->data = a[0];
	Node *p = t;
	for (int i = 1; i < a.size(); i++) {
		Node *q = new Node;
		q->data = a[i];
		q->left = NULL;
		q->right = NULL;
		p = t;
		while (p != NULL) {
			if (p->data < q->data) {
				if (p->right) p = p->right;
				else {
					p->right = q;
					break;
				}
			}
			else
				if (p->left) p = p->left;
				else {
					p->left = q;
					break;
				}
		}

	}
}
int Height(Node *t) {
	int h = 0;
	if (t != NULL) {
		int left_height = Height(t->left);
		int right_height = Height(t->right);
		h = left_height > right_height ? left_height + 1 : right_height + 1;
	}
	return h;
}

bool ifAVL(Node* t) {
	if (t == NULL) return true;
	int left_height = Height(t->left);
	int right_height = Height(t->right);
	if ((left_height-right_height) > 1 || (left_height-right_height) < -1)
		return false;
	return ifAVL(t->left) && ifAVL(t->right);
}

int main() {
	Node *t = new Node;
	t->left = NULL;
	t->right = NULL;
	vector<int> a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	create(a, t);
	cout << ifAVL(t) << endl;
	return 0;
}
