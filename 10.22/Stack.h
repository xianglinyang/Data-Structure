#pragma once
template<class Type>class Stack {
public:
	Stack() { MAXN = 100; stk = new Type[MAXN]; }
	Stack(int size) { MAXN = size; stk = new Type[MAXN]; }
	~Stack() { delete[]stk; }
	int push(Type x) {
		if (top = MAXN - 1) return 1;
		stk[++top] = x;
		return 0;
	};
	int pop() {
		if (top == -1) return 1;
		top--;
		return 0;
	};
	Type GetTop() {
		if (top == -1) return NULL;
		return stk[top];
	}
	bool isEmpty() const {
		return top == -1;
	};
	bool isFull() const {
		return top == MAXN - 1;
	};
private:
	Type *stk;
	int top = -1;
	int MAXN;
};
