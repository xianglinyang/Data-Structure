#include<iostream>
using namespace std;

template<class T> class List;
template<class T> void test1(List<T>,List<T>,List<T>);
template<class T> class LinkNode{
    friend class List<T>;
    friend void test1<T>(List<T>,List<T>,List<T>);
    public:
    	LinkNode() { link=NULL;}  
    	LinkNode(T a){ data=a;link=NULL;}
    private:
    	T data;
    	LinkNode<T> *link;
};

template<class T> class List{
    public:
    	List(){	head=new LinkNode<T>();}
		~List(){}
		void Create();
		void Output();
		LinkNode<T>* Myhead();
	private:
	    LinkNode<T> *head;
};

template<class T> void List<T>:: Create(){
	LinkNode<T> *p,*q;
	p=head; 
	int x;
	cin>>x;
	while(x>0){
		q=new LinkNode<T>();
		q->data=x;
		p->link=q;
		q->link=NULL;
		p=q;
		cin>>x;
	}
	
}

template<class T> void List<T>::Output(){
	LinkNode<T> *p;
	p=head->link;
	while(p->link!=NULL){
		cout<<p->data<< "  ";
		p=p->link;
	}
	cout<<p->data<<endl;
}

template<class T> LinkNode<T>* List<T>::Myhead(){
	LinkNode<T> *p;
	p=head;
	return p;
}

template<class T> void test1(List<T> s1,List<T> s2,List<T> s){
	LinkNode<T> *l1,*l2,*l,*p;
	l1=s1.Myhead();
	l2=s2.Myhead();
	l=s.Myhead();
	l1=l1->link;
	l2=l2->link;
	l->link=NULL;
	while(l1!=NULL&&l2!=NULL){
		if(l1->data<l2->data){
		   p=l1->link;
		   l1->link=l->link;
		   l->link=l1;
		   l1=p;
		} 
		else{
		   p=l2->link;
		   l2->link=l->link;
		   l->link=l2;
		   l2=p;
		   }
	}
	while(l1){
		p=l1->link;
		l1->link=l->link;
		l->link=l1;
		l1=p;
	}
	while(l2){
		p=l2->link;
		l2->link=l->link;
		l->link=l2;
		l2=p;
	}
	
}

int main(){
	List<int> s1,s2,s;
	s1.Create();
	s2.Create();
	test1(s1,s2,s);
	s.Output();
	return 0;
}

