#pragma once
template <class Type> class GenList;
template <class Type> class GenListNode {  //��������ඨ��
	friend class Genlist;
private:
	int utype;       //=0/1/2
	GenListNode <Type> *tlink;     //ָ��ͬһ����һ����ָ��
	union {      //����
		int ref;    
		Type value;   //utype=0��������ü�����=1�������ֵ
		GenListNode <Type> *hlink;     //utype=2�����ָ���ӱ��ָ��
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
template <class Type> GenListNode & GenListNode  <Type> ::Info() {  //���ر�Ԫ�ص�ֵ
	GenListNode *pitem = new GenListNode;
	pitem->utype = utype;        
	pitem->info.value = info.value;
	return *pitem;
}

template <class Type> void  GenListNode <Type> ::SetInfo(GenListNode <Type> *elem, GenListNode <Type> &x) {   //�޸ı�Ԫ�ص�ֵΪx
	elem->utype = x.utype;
	elem->info.value = x.info.value;
}
template <class Type> class GenList {  //������ඨ��     
private:
	GenListNode <Type> *first;  //�����ͷָ��
	GenListNode <Type> * Copy(GenListNode <Type> *ls);
	//����һ��lsָʾ���޹���ǵݹ��
	int Depth(GenListNode <Type> *ls);
	//������lsָʾ�ķǵݹ������
	int Length(GenListNode <Type> *ls);
	//������lsָʾ�ķǵݹ��ĳ���
	bool Equal(GenListNode <Type> *s, GenListNode <Type> *t);
	//�Ƚ���s��tΪ��ͷ���������Ƿ����
	void Remove(GenListNode <Type> *ls);
	//�ͷ���lsΪ��ͷ���Ĺ����
	void CreateList(istream &in, GenListNode <Type> *&ls);
	//����������������������ַ�������
	//����һ��������ͷ���Ĺ����ṹ
public:
	Genlist();  //���캯��
	~GenList();  //�������� 
	bool Head(GenListNode<Type> &x);  //���ر�ͷԪ��
	bool Tail(GenList <Type> &lt);	 //���ر�β
	GenListNode <Type> * First();  //���ص�һ��Ԫ��
	GenListNode <Type> * Next(GenListNode <Type> *elem);
	//���ر�Ԫ��elem��ֱ�Ӻ��Ԫ��
	void Copy(const GenList <Type> &R);
	//���ƹ����
	int Length();  //��������ĳ���
	int Depth();   //������������
	void DelValue(GenListNode <Type> *ls, Type x)
		bool Equal(GenListNode <Type> *s, GenListNode <Type> *t);

		friend istream & operator >> (istream &in, GenList <type> &L);
}; //һЩ�򵥳�Ա������ʵ�ּ���ҳ��ע
template <class Type> Genlist <Type> ::GenList() {  //���캯��
	GenListNode *first = new GenListNode;
	assert(first != NULL);
	first->utype = 0;
	first->info.ref = 1;
	first->tlink = NULL;
}

template <class Type> bool GenList <Type> : Head(GenListNode <Type> &x) {
	//�������ǿգ��򷵻����һ��Ԫ�ص�ֵ
	//������û�ж���
	if (first->tlink == NULL)  return false;
	else {  //�ǿձ�
		x.utype = frist->tlink->utype;
		x.info = frist->tlink->info;
		return true;  //�������ͼ�ֵ
	}
}

template <class Type> GenListNode * GenList <Type> ::First() {
	//���ع����ĵ�һ��Ԫ�أ�����գ��򷵻�NULL
	if (first->tlink == NULL)  return NULL;
	else return first->tlink;
}

template <class Type> GenListNode * GenList <Type> ::Next(GenListNode <Type> *elem) {
	//���ر�Ԫ��elem��ֱ�Ӻ��Ԫ��
	if (elem->tlink == NULL)  return NULL;
	else return elem->tlink;
}
template <class Type> bool GenList <Type> ::
Tail(GenList <Type> &lt) {
	//�������ǿգ��򷵻ع�������һ��Ԫ
	//��������Ԫ����ɵı�������û�ж���
	if (first->tlink == NULL)  return false;
	else {
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
	}
	return true;
}
//���к���
template <class Type> void GenList <Type> ::
Copy(const GenList <Type> &R) { first = Copy(R.first); }
template <class Type> GenListNode * GenList <Type> ::
Copy(GenListNode <Type> *ls) {  //˽�к��� 
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
//���к���
template <class Type> int GenList <Type> ::Length() {
	return Length(first);
}

//˽�к���
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
	if (ls->tlink == NULL)  return 1;  //�ձ�
	GenListNode <Type> *temp = ls->tlink;  int m = 0, n;
	while (temp != NULL) {  //�ڱ����ɨ
		if (temp->utype == 2) {  //���Ϊ����
			n = Depth(temp->info.hlink); if (m<n)  m = n;  //m�������� 
		}
		temp = temp->tlink;
	}
	return m + 1;
}
template <class Type> void GenList <Type> ::
DelValue(GenListNode <Type> *ls, Type x)
{  //�ڹ������ɾ�����к�x�Ľ��
	if (ls->tlink != NULL) {  //�ǿձ� 
		GenListNode <Type> *p = ls->tlink;
		while (p != NULL && ((p->utype == 1 && p->info.value == x)) {
			ls->tlink = p->tlink;  delete p;     p = ls->tlink; //ɾ��
		} //ɾ���������ֵ�x
		if (p != NULL) {
			if (p->utype == 2) DelValue(p->info.hlink, x); //�ӱ���ɾ��
			DelValue(p, x);  //�ں���������ɾ��  
		}
	}
}
template <class Type> GenList <Type> :: ~GenList() { Remove(first); }
template <class Type> void GenList <Type> ::
Remove(GenListNode <type> *ls) {
	ls->info.ref--;  //���ü�����һ
	if (ls->info.ref <= 0) {  //���ü�������0����ɾ��         
		GenListNode <Type> *q;
		while (ls->tlink != NULL) {  //��ɨ����
			q = ls->tlink;
			if (q->utype == 2) {  //�����ӱ�
				Remove(q->info.hlink);  //�ݹ�ɾ���ӱ�
				if (q->info.hlink->info.ref <= 0)     delete q->info.hlink;
				//ɾ���ӱ��ͷ����ΪRemove��û��ɾ��
			}
			ls->tlink = q->tlink;  
			delete q;   //q������ԭ�ӽ������ӱ���

		}
	}
}
template <class Type> bool GenList <Type> ::Equal(GenListNode <Type> *s, GenListNode <Type> *t) {
	if (s.info!=t.info) return false;
	else if (s == t) return true;
	else return Equal(s->tlink, t->tlink);
}

