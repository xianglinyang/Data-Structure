#include<iostream>
using namespace std;

template<class T> class List;
template<class T> class LinkNode{
    friend class List<T>;
    public:
    	LinkNode() { link=NULL;}
    	LinkNode(T a){ data=a;link=NULL;}
    private:
    	T data;
    	LinkNode<T> *link;
};

template<class T> class List{
    public:
    	List(){	tail=head=new LinkNode<T>();}
		~List(){}
		void Create_List();
		void Output_List();
		bool ifcircle();
		void circle(int);
		int find();
	private:
	    LinkNode<T> *head,*tail;
};

template<class T> void List<T>:: Create_List(){
	LinkNode<T> *p,*q;
	p=head; 
	int x;
	while(cin>>x){
		q=new LinkNode<T>();
		q->data=x;
		p->link=q;
		q->link=NULL;
		p=q;
	}
	
}

template<class T> void List<T>:: circle(int n){
	LinkNode<T> *p,*q;
	for(q=head->link;q->link!=NULL;q=q->link);
	for(p=head->link;p->link!=NULL && n>1 ;n--) p=p->link;
	if(p->link!=NULL) q->link=p;
}
template<class T> void List<T>::Output_List(){
	LinkNode<T> *p;
	p=head->link;
	while(p->link!=NULL){
		cout<<p->data<< "  ";
		p=p->link;
	}
	cout<<p->data<<endl;
}



template<class T> bool List<T>::ifcircle(){
	LinkNode<T> *fast,*slow;
	fast=head->link;
	slow=head->link;
	while(fast && fast->link!=NULL){
		fast=fast->link->link;
		slow=slow->link;
		if(fast==slow) return 1;
	}
	return 0;
}

template<class T> int List<T>::find(){
	LinkNode<T> *p,*q,*fast,*slow;
	fast=head->link->link;
	slow=head->link;
	while(fast!=slow){
		fast=fast->link->link;
		slow=slow->link;
    }
    p=slow;
    q=head;
    while(p!=q){
    	p=p->link;
    	q=q->link;
	}
	return p->data;
}

int main(){
	List<int> s;
	LinkNode<int> *o;
	int n,a;
	s.Create_List();
    cout << "输入成环的位置：" <<endl;
	cin >> n;
	s.circle(n);
	if(s.ifcircle()) {
		a=s.find();
		cout <<"有环，该指针对应的数字是" << a;
	}
	else cout << "并没有环。"<< endl;
	return 0;
}

