#include<iostream> 
using namespace std;
#define MAXN 100
typedef struct node {
	char data;
	struct node *lchild; 
	struct node *rchild;
}NODE;
char a[MAXN];  //初始时各结点的值
int w[2 * MAXN - 1];   //初始时前n个元素保存了n个结点的权重
NODE *create_huffman_tree(char a[], int w[], int n) {
	NODE *addr[2 * MAXN - 1];  
	int n1, n2, i, j; 
	int u, v, min1, min2;
	for (i = 0; i<n; i++) {
		addr[i] = new NODE(); 
		addr[i]->data = a[i];
		addr[i]->lchild = NULL;
		addr[i]->rchild = NULL; 
		w[i] = -w[i];
	}
	for (i = n; i<2 * n - 1; i++) {
		n1 = -1;  
		min1 = 9999; 
		n2 = -1;    
		min2 = 9999;
		for (j = 0; j<i; j++) {
			v = w[j];    
			u = -v;
			if (u>0)
				if (u<min1) {
					min2 = min1;  
					n2 = n1;   
					min1 = u;  
					n1 = j;
				}
				else if (u < min2) {
					min2 = u;   
					n2 = j; 
				}  // min2是次小
		}
		addr[i] = new HNODE();    
		addr[i]->data = '*';
		addr[i]->lchild = addr[n1];    
		addr[i]->rchild = addr[n2];
		w[i] = w[n1] + w[n2];         
		w[n1] = -w[n1];   
		w[n2] = -w[n2];
	}
	w[2 * n - 2] = -w[2 * n - 2];    
	return addr[2 * n - 2];
}
void create_array(char a[]) {
	cout << "请输入字符：";
	char ch;
	int i=0,j=0;
	while (getchar(ch)) a[i++] = ch;
	cout << "请输入频率：";
	while (cin >> i) w[j++] = i;
}
int print_code(NODE *p,char x) {
	if (p->lchild->data == x) {
		cout << "0";
		return 1;
	}
	else if (p->rchild->data == x) {
		cout << "1";
		return 1;
	}
	else return 0;


}
