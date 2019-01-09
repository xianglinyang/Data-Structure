#pragma once
template <class Type> class GenList;
template <class Type> class GenListNode {  //广义表结点类定义
	friend class Genlist;
private:
	int utype;       //=0/1/2
	GenListNode <Type> *tlink;     //指向同一层下一结点的指针
	union {      //联合
		int ref;    
		Type value;   //utype=0，存放引用计数，=1，存放数值
		GenListNode <Type> *hlink;     //utype=2，存放指向子表的指针
	} info;
public:
	GenListNode() : utype(0), tlink(NULL), info.ref(0) { }
	GenListNode(GenListNode <Type> &RL) {
		utype = RL.utype;  
		tlink = Rl.tlink;  
		info = RL.info;
	}
	GenListNode <Type> &   Info();
	void  SetInfo(GenListNode <Type> *elem, GenListNode <Type> &x)
};
template <class Type> GenListNode & GenListNode  <Type> ::Info() {  //返回表元素的值
	GenListNode *pitem = new GenListNode;
	pitem->utype = utype;        
	pitem->info.value = info.value;
	return *pitem;
}

template <class Type> void  GenListNode <Type> ::SetInfo(GenListNode <Type> *elem, GenListNode <Type> &x) {   //修改表元素的值为x
	elem->utype = x.utype;
	elem->info.value = x.info.value;
}
template <class Type> class GenList {  //广义表类定义     
private:
	GenListNode <Type> *first;  //广义表头指针
	GenListNode <Type> * Copy(GenListNode <Type> *ls);
	//复制一个ls指示的无共享非递归表
	int Depth(GenListNode <Type> *ls);
	//计算由ls指示的非递归表的深度
	int Length(GenListNode <Type> *ls);
	//计算由ls指示的非递归表的长度
	bool Equal(GenListNode <Type> *s, GenListNode <Type> *t);
	//比较以s和t为表头的两个表是否相等
	void Remove(GenListNode <Type> *ls);
	//释放以ls为表头结点的广义表
	void CreateList(istream &in, GenListNode <Type> *&ls);
	//从输入流对象输入广义表的字符串描述
	//建立一个带附加头结点的广义表结构
public:
	Genlist();  //构造函数
	~GenList();  //析构函数 
	bool Head(GenListNode<Type> &x);  //返回表头元素
	bool Tail(GenList <Type> &lt);	 //返回表尾
	GenListNode <Type> * First();  //返回第一个元素
	GenListNode <Type> * Next(GenListNode <Type> *elem);
	//返回表元素elem的直接后继元素
	void Copy(const GenList <Type> &R);
	//复制广义表
	int Length();  //计算广义表的长度
	int Depth();   //计算广义表的深度
	void DelValue(GenListNode <Type> *ls, Type x)
		bool Equal(GenListNode <Type> *s, GenListNode <Type> *t);

		friend istream & operator >> (istream &in, GenList <type> &L);
}; //一些简单成员函数的实现见本页备注
template <class Type> Genlist <Type> ::GenList() {  //构造函数
	GenListNode *first = new GenListNode;
	assert(first != NULL);
	first->utype = 0;
	first->info.ref = 1;
	first->tlink = NULL;
}

template <class Type> bool GenList <Type> : Head(GenListNode <Type> &x) {
	//若广义表非空，则返回其第一个元素的值
	//否则函数没有定义
	if (first->tlink == NULL)  return false;
	else {  //非空表
		x.utype = frist->tlink->utype;
		x.info = frist->tlink->info;
		return true;  //返回类型及值
	}
}

template <class Type> GenListNode * GenList <Type> ::First() {
	//返回广义表的第一个元素，若表空，则返回NULL
	if (first->tlink == NULL)  return NULL;
	else return first->tlink;
}

template <class Type> GenListNode * GenList <Type> ::Next(GenListNode <Type> *elem) {
	//返回表元素elem的直接后继元素
	if (elem->tlink == NULL)  return NULL;
	else return elem->tlink;
}
template <class Type> bool GenList <Type> ::
Tail(GenList <Type> &lt) {
	//若广义表非空，则返回广义表除第一个元
	//素外其它元素组成的表，否则函数没有定义
	if (first->tlink == NULL)  return false;
	else {
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
	}
	return true;
}
//公有函数
template <class Type> void GenList <Type> ::
Copy(const GenList <Type> &R) { first = Copy(R.first); }
template <class Type> GenListNode * GenList <Type> ::
Copy(GenListNode <Type> *ls) {  //私有函数 
	GenListNode <Type> *q = NULL;
	if (ls != NULL) {
		q = new GenListNode <Type>;         q->utype = ls->utype;
		switch (ls->utype) {
		case 0: q->info.ref = ls->info.ref;  break;
		case 1: q->info.value = ls->info.value;  break;
		case 2: q->info.hlink = Copy(ls->info.hlink);  break;
		}
		q->tlink = Copy(ls->tlink);
	}
	return q;
}
//公有函数
template <class Type> int GenList <Type> ::Length() {
	return Length(first);
}

//私有函数
template <class Type> int GenList <Type> ::
Length(GenListNode <Type> *ls) {
	if (ls != NULL)  return 1 + Length(ls->tlink);
	else return 0;
}
template <class Type> int GenList <Type> ::Depth() {
	return Depth(first);
}
template<class Type>
inline bool GenList<Type>::Equal(GenListNode<Type>* s, GenListNode<Type>* t)
{
	return false;
}
template <class Type> int GenList <Type> ::
Depth(GenListNode <Type> *ls) {
	if (ls->tlink == NULL)  return 1;  //空表
	GenListNode <Type> *temp = ls->tlink;  int m = 0, n;
	while (temp != NULL) {  //在表顶层横扫
		if (temp->utype == 2) {  //结点为表结点
			n = Depth(temp->info.hlink); if (m<n)  m = n;  //m记最大深度 
		}
		temp = temp->tlink;
	}
	return m + 1;
}
template <class Type> void GenList <Type> ::
DelValue(GenListNode <Type> *ls, Type x)
{  //在广义表中删除所有含x的结点
	if (ls->tlink != NULL) {  //非空表 
		GenListNode <Type> *p = ls->tlink;
		while (p != NULL && ((p->utype == 1 && p->info.value == x)) {
			ls->tlink = p->tlink;  delete p;     p = ls->tlink; //删除
		} //删除连续出现的x
		if (p != NULL) {
			if (p->utype == 2) DelValue(p->info.hlink, x); //子表中删除
			DelValue(p, x);  //在后续链表中删除  
		}
	}
}
template <class Type> GenList <Type> :: ~GenList() { Remove(first); }
template <class Type> void GenList <Type> ::
Remove(GenListNode <type> *ls) {
	ls->info.ref--;  //引用计数减一
	if (ls->info.ref <= 0) {  //引用计数减至0才能删除         
		GenListNode <Type> *q;
		while (ls->tlink != NULL) {  //横扫链表
			q = ls->tlink;
			if (q->utype == 2) {  //遇到子表
				Remove(q->info.hlink);  //递归删除子表
				if (q->info.hlink->info.ref <= 0)     delete q->info.hlink;
				//删除子表表头，因为Remove中没有删除
			}
			ls->tlink = q->tlink;  
			delete q;   //q可能是原子结点或者子表结点

		}
	}
}
template <class Type> bool GenList <Type> ::Equal(GenListNode <Type> *s, GenListNode <Type> *t) {
	if (s.info!=t.info) return false;
	else if (s == t) return true;
	else return Equal(s->tlink, t->tlink);
}

