#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include <stdio.h>
#include <string.h>
using namespace std;
template<class T>
class DLLNode{
public:
	DLLNode() {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode<T> *next, *prev;
};
template<class T>
class	MyBigInt{
public:
	MyBigInt(){
		head=tail=0;
	}
	void createBigInt(char *arr);
	void updateBigInt(MyBigInt<int> A);
	void freeBigInt();
	void multiplyBigInt();
	T deleteFromDLLHead();
	void printBigInt();
	void addBigInt(MyBigInt<int> A,MyBigInt<int> B);
	void addToDLLHead(const T&);
	 T deleteFromDLLTail();
	void addToDLLTail(const T& el);
	void multiplyBigInt(MyBigInt<int> A,MyBigInt<int> B);
	void userupdateBigInt(string arr);
	void usercreateBigInt(string arr);
	void userAddBigInt(string arr1,string arr2);
	void userMultiplyBigInt(string arr1,string arr2);
private:
	DLLNode<T> *head,*tail;
};
template<class T>
T MyBigInt<T>::deleteFromDLLHead() {
    int el=head->info;
    if (head == tail) { 
         delete head;
         head = tail = 0;
    }
    else {             
         head = head->next;
         delete head->prev;
         head->prev = 0;
    }
    return el;
}
template<class T>
void MyBigInt<T>::addToDLLTail(const T& el) {
    if (tail != 0) {
	DLLNode<T> *temp=new DLLNode<T>(el);
	tail->next=temp;
	temp->prev=tail;
	temp->next=NULL;
	tail=tail->next;
	
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void MyBigInt<T>::addToDLLHead(const T& el)
{
	if(head!=0)
	{
		DLLNode<T> *temp=new DLLNode<T> (el);
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=head->prev;
	}
	else
		head=tail=new DLLNode<T>(el);	
}
template<class T>
T MyBigInt<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { 
         delete head;
         head = tail = 0;
    }
    else {             
         tail = tail->prev;
         delete tail->next;
         tail->next = 0;
    }
    return el;
}
template<class T>
void MyBigInt<T>::createBigInt(char *arr)
{
	int j=0;
	while(arr[j]!='\0')
	{
		char c=arr[j];
		int number;
		number=c-'0';
		DLLNode<T> *temp=new DLLNode<T>(number);
		if(head==0)
		{
			head=tail=temp;
		}
		else
		{
			temp->prev=tail;
			temp->next=NULL;
			tail->next=temp;
			tail=tail->next;
		}
		j++;
	}
}
template<class T>
void MyBigInt<T>::printBigInt()
{
	DLLNode<T> *temp=head;
	if(head==0)
		return;
	else
	{
		while(temp!=0)
		{
			cout<<temp->info;
			temp=temp->next;
		}
	}
}
template<class T>
void MyBigInt<T>::freeBigInt()
{
	DLLNode<T> *count=head;
	while(count!=0)
	{
		if(head!=tail)
		{
			DLLNode<T> *temp=head;
			head=head->next;
			count=count->next;
			head->prev=NULL;
			temp->next=NULL;
			delete temp;				
		}
		else
		{
			count=count->next;	
			delete head;
			head=tail=0;
		}
	}
}
template<class T>
void MyBigInt<T>::usercreateBigInt(string arr)
{
	int j=0;
	while(arr[j]!='\0')
	{
		char c=arr[j];
		int number;
		number=c-'0';
		DLLNode<T> *temp=new DLLNode<T>(number);
		if(head==0)
		{
			head=tail=temp;
		}
		else
		{
			temp->prev=tail;
			temp->next=NULL;
			tail->next=temp;
			tail=tail->next;
		}
		j++;
	}
}
template<class T>
void MyBigInt<T>::userupdateBigInt(string arr)
{
	DLLNode<T> *count=head;
	while(count!=0)
	{
		if(head!=tail)
		{
			DLLNode<T> *temp=head;
			head=head->next;
			count=count->next;
			head->prev=NULL;
			temp->next=NULL;
			delete temp;				
		}
		else
		{
			count=count->next;	
			delete head;
			head=tail=0;
		}
	}
	int counter=0;
	int i=0;
	while(arr[counter]!='\0')
	{
		counter++;
	}
	MyBigInt<int> A;
	A.usercreateBigInt(arr);
	while(counter!=0)
	{
		int c=A.deleteFromDLLTail();
		A.addToDLLHead(c);
		if(head!=0)
		{
		DLLNode<T> *temp=new DLLNode<T> (c);
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=head->prev;
		}
		else
		{
		head=tail=new DLLNode<T>(c);	
		}
		counter--;
	}
}
template<class T>
void MyBigInt<T>::updateBigInt(MyBigInt<int>A)
{
	DLLNode<T> *count=head;
	while(count!=0)
	{
		if(head!=tail)
		{
			DLLNode<T> *temp=head;
			head=head->next;
			count=count->next;
			head->prev=NULL;
			temp->next=NULL;
			delete temp;				
		}
		else
		{	
			count=count->next;
			delete head;
			head=tail=0;
		}
	}
	A.addToDLLHead(44);
	int x=44;
	int y=0;
	while(y!=x)
	{
		y=A.deleteFromDLLTail();
		A.addToDLLHead(y);
		DLLNode<T> *temp=new DLLNode<T>(y);
		if(head==0)
		{
			head=tail=temp;
		}
		else
		{
			temp->next=head;
			head->prev=temp;
			temp->prev=NULL;
			head=head->prev;
		}
	
	}
	DLLNode<T> *temp=head;
	head=head->next;
	temp->next=NULL;
	head->prev=NULL;
	delete temp;
	A.deleteFromDLLHead();
}
template<class T>
void MyBigInt<T>::addBigInt(MyBigInt<int> A,MyBigInt<int> B)
{
	int count1=0;
	int count2=0;
	MyBigInt<int> Q,R;
	Q.updateBigInt(A);
	R.updateBigInt(B);
	MyBigInt<int>Ax,Bx;
	Ax.updateBigInt(A);
	Bx.updateBigInt(B);
	int w=0;
	Q.addToDLLHead(44);
	while(w!=44)
	{
		w=Q.deleteFromDLLTail();
		count1++;
	}
	count1--;
	R.addToDLLHead(44);
	w=0;
	while(w!=44)
	{
		w=R.deleteFromDLLTail();
		count2++;
	}
	count2--;
	if(count1>count2)
	{
		int flag=0;
		while(count2!=0)
		{
			int x=Ax.deleteFromDLLTail();
			int y=Bx.deleteFromDLLTail();
			int m=x+y;
			if(m>=10)
			{
				m=m-10;
				int h=Ax.deleteFromDLLTail();
				h++;
				Ax.addToDLLTail(h);
				DLLNode<T> *temp=new DLLNode<T> (m);
				if(head==0)
				{
					head=tail=temp;
				}
				else
				{
					temp->next=head;
					head->prev=temp;
					temp->prev=NULL;
					head=head->prev;
				}	
			}
			else
			{
				DLLNode<T> *temp=new DLLNode<T> (m);
				if(head==0)
					head=tail=temp;
				else
				{
					temp->next=head;
					head->prev=temp;
					temp->prev=NULL;
					head=head->prev;
				}
			}	
			count2--;
			count1--;
		}
		while(count1!=0)
		{
			int x=Ax.deleteFromDLLTail();
			if(x>=10)
			{
				if(count1==1)
				{
					flag=1;
				}
				else
				{
					int h=Ax.deleteFromDLLTail();
					h++;
					Ax.addToDLLTail(h);
				}
				x=x-10;
				DLLNode<T> *temp=new DLLNode<T> (x);
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
			else
			{
				DLLNode<T> *temp=new DLLNode<T>(x);
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
			count1--;
		}
		if(flag==1)
		{
			DLLNode<T> *temp=new DLLNode<T> (1);
			temp->next=head;
			head->prev=temp;
			temp->prev=NULL;
			head=head->prev;
		}
		
	}
	if(count2>count1)
	{
		int flag=0;
		while(count1!=0)
		{
		int x=Ax.deleteFromDLLTail();
		int y=Bx.deleteFromDLLTail();
		int m=x+y;		
		if(m>=10)
		{
			m=m-10;
			int h=Bx.deleteFromDLLTail();
			h++;
			Bx.addToDLLTail(h);
			DLLNode<T> *temp=new DLLNode<T> (m);
			if(head==0)
			{
				head=tail=temp;
			}
			else
			{
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
		}
		else
		{
			DLLNode<T> *temp=new DLLNode<T> (m);	
			if(head==0)
			{
				head=tail=temp;
			}
			else
			{

				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
		}
		count2--;
		count1--;
		}	
		while(count2!=0)
		{
			int x=Bx.deleteFromDLLTail();
			if(x>=10)
			{
				if(count2==1)
				{
					flag=1;
				}
				else
				{
					int h=Bx.deleteFromDLLTail();
					h++;
					Bx.addToDLLTail(h);
				}
				x=x-10;
				DLLNode<T> *temp=new DLLNode<T> (x);
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
			else
			{
				DLLNode<T> *temp=new DLLNode<T>(x);
				temp->next=head;
				head->prev=temp;
				temp->prev=NULL;
				head=head->prev;
			}
			count2--;
		}
		if(flag==1)
		{
			DLLNode<T> *temp=new DLLNode<T>(1);
			temp->next=head;
			head->prev=temp;
			temp->prev=NULL;
			head=head->prev;
		}
	}
	if(count1==count2)
	{
		int flag=0;
		while(count1!=0)
		{
		int x=Ax.deleteFromDLLTail();
		int y=Bx.deleteFromDLLTail();
		int m=x+y;
		if(m>=10)
		{
			if(count1==1)
			{
				flag=1;
			}
			else
			{
			int h=Ax.deleteFromDLLTail();
			h++;
			Ax.addToDLLTail(h);
			}
			m=m-10;
			DLLNode<T> *temp=new DLLNode<T>(m);
			if(head==0)
			{
				head=tail=temp;
			}
			else
			{
					temp->next=head;
					head->prev=temp;
					temp->prev=NULL;
					head=head->prev;
			}
		}
		else
			{
				DLLNode<T> *temp=new DLLNode<T> (m);
				if(head==0)
				{
					head=tail=temp;
				}
				else
				{
					temp->next=head;
					head->prev=temp;
					temp->prev=NULL;
					head=head->prev;
				}
			}
		count1--;		
		}
		if(flag==1)
		{
			DLLNode<T> *temp=new DLLNode<T>(1);
			temp->next=head;
			head->prev=temp;
			temp->prev=NULL;
			head=head->prev;
		}
	}
}
template<class T>
void MyBigInt<T>::multiplyBigInt(MyBigInt<int> A,MyBigInt<int> B)
{
	MyBigInt<int> Ax;
	Ax.updateBigInt(A);
	MyBigInt<int> Bx;
	Bx.updateBigInt(B);
	int count1=0;
	int count2=0;
	MyBigInt<int> M,R,Z,P,Q,G,H;
	MyBigInt<int> S,K;
	S.updateBigInt(A);
	K.updateBigInt(B);
	S.addToDLLHead(44);
	int w=0;
	while(w!=44)
	{
		w=S.deleteFromDLLTail();
		count1++;
	}
	count1--;
	K.addToDLLHead(44);
	w=0;
	while(w!=44)
	{
		w=K.deleteFromDLLTail();
		count2++;
	}
	count2--;
	if(count1>=count2)
	{
		int counti=0;
		int i=0;
		int j=0;
		while(i!=count2)
		{
			R.freeBigInt();
			H.freeBigInt();
			j=0;
			int x=Bx.deleteFromDLLTail();
			while(j!=count1) 
			{
				int y=Ax.deleteFromDLLTail();
				int m=x*y;
				DLLNode<T> *temp=new DLLNode<T>(m);			
					if(head==0)
					{
						head=tail=temp;
					}
					else
					{
						temp->next=head;
						head->prev=temp;
						temp->prev=NULL;
						head=head->prev;
					}
				j++;	
			}
			Ax.updateBigInt(A);
			DLLNode<T> *tmp=tail;
			while(tmp!=NULL)
			{
				int fil=tmp->info;
				if(fil>=10)
				{
					int kalan=fil%10;
					int elde=(fil-kalan)/10;
					tmp->info=kalan;
					if(tmp==head)
					{
						DLLNode<T> *backup=new DLLNode<T>;
						backup->next=head;
						head->prev=backup;
						backup->prev=NULL;
						head=head->prev;
						backup->info=elde;
					}
					else
					{
						tmp=tmp->prev;
						int fil2=tmp->info;
						fil2=fil2+elde;
						tmp->info=fil2;
						tmp=tmp->next;
					}
					
				}
			tmp=tmp->prev;
			}
			tmp=tail;
			while(tmp!=NULL)
			{
				R.addToDLLHead(tmp->info);
				tmp=tmp->prev;
			}
			tmp=head;
			while(tmp!=NULL)
			{
				tmp=head;
				if(head==tail)
				{
					delete tmp;
					head=tail=0;
				}
				else
				{
				head=head->next;
				tmp->next=NULL;
				tmp->prev=NULL;
				head->prev=NULL;
				delete tmp;
				}		
			}
			counti=i;
			while(counti!=0)
			{
				R.addToDLLTail(0);
				counti--;
			}
			if(i==0)
			{
				Q.updateBigInt(R);
				Z.updateBigInt(R);
			}
			else
			{
				if(i==1)
				{
					
					M.addBigInt(Q,R);
					Z.updateBigInt(M);
				}
				else
				{
					G.updateBigInt(Z);
					H.addBigInt(G,R);
					Z.updateBigInt(H);
				}
			}
			i++;
		}
		Z.addToDLLHead(44);
		int o=0;
		while(o!=44)
		{
			o=Z.deleteFromDLLTail();
			DLLNode<T> *remp=new DLLNode<T>(o);
			if(head==0)
			{
				head=tail=remp;
			}
			else
			{
					remp->next=head;
					head->prev=remp;
					remp->prev=NULL;
					head=head->prev;
			}
		}

		 if (head == tail) { 
        	 delete head;
         	head = tail = 0;
    		}
   		 else {             
        		 head = head->next;
       			  delete head->prev;
       			  head->prev = 0;
   			 }	
	}
	if(count2>count1)
	{
		int counti=0;
		int i=0;
		int j=0;
		while(i!=count1)
		{
			R.freeBigInt();
			H.freeBigInt();
			j=0;
			int x=Ax.deleteFromDLLTail();
			while(j!=count2)
			{
				int y=Bx.deleteFromDLLTail();
				int m=x*y;
				DLLNode<T> *temp=new DLLNode<T>(m);
				if(head==0)
				{
					head=tail=temp;
				}
				else
				{
					temp->next=head;
					head->prev=temp;
					temp->prev=NULL;
					head=head->prev;
				}
			j++;
		}
		Bx.updateBigInt(B);
		DLLNode<T> *tmp=tail;
		while(tmp!=NULL)
		{
			int fil=tmp->info;
			if(fil>=10)
			{
				int kalan=fil%10;
				int elde=(fil-kalan)/10;
				tmp->info=kalan;
				if(tmp==head)
				{
					DLLNode<T> *backup=new DLLNode<T>;
					backup->next=head;
					head->prev=backup;
					head=head->prev;
					backup->info=elde;
				}
				else
				{
					tmp=tmp->prev;
					int fil2=tmp->info;
					fil2=fil2+elde;
					tmp->info=fil2;
					tmp=tmp->next;
				}
			}
		tmp=tmp->prev;
		}
		tmp=tail;
		while(tmp!=NULL)
		{
			R.addToDLLHead(tmp->info);
			tmp=tmp->prev;
		}	
		tmp=head;
		while(tmp!=NULL)
		{
			tmp=head;
			if(head==tail)
			{
				delete tmp;
				head=tail=0;
			}
			else
			{
				head=head->next;
				tmp->next=NULL;
				tmp->prev=NULL;
				head->prev=NULL;
				delete tmp;
			}
		}
		counti=i;
		while(counti!=0)
		{
			R.addToDLLTail(0);
			counti--;
		}
		if(i==0)
		{
			Q.updateBigInt(R);
			Z.updateBigInt(R);
		}
		else
		{
			if(i==1)
			{
				M.addBigInt(Q,R);
				Z.updateBigInt(M);
			}
			else
			{
				G.updateBigInt(Z);
				H.addBigInt(G,R);
				Z.updateBigInt(H);
			}
		}
		i++;
	}
		Z.addToDLLHead(44);
		int o=0;
		while(o!=44)
		{
			o=Z.deleteFromDLLTail();
			DLLNode<T> *remp=new DLLNode<T>(o);
			if(head==0)
			{
				head=tail=remp;
			}
			else
			{
				remp->next=head;
				head->prev=remp;
				remp->prev=NULL;
				head=head->prev;
			}
		}
			if(head==tail)
		{
			delete head;
			head=tail=0;
		}
		else
		{
			head=head->next;
			delete head->prev;
			head->prev=0;
		}
	}
}
template<class T>
void MyBigInt<T>::userAddBigInt(string arr1,string arr2)
{
	MyBigInt<int>A,B,Result,Result2;
	A.usercreateBigInt(arr1);
	B.usercreateBigInt(arr2);
	Result.addBigInt(A,B);
	Result2.updateBigInt(Result);
	int i=0;
	Result2.addToDLLHead(44);
	while(i!=44)
	{
		i=Result2.deleteFromDLLTail();
		DLLNode<T> *temp=new DLLNode<T> (i);
		if(head!=0)
		{
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=head->prev;
		}
		else
		{
		head=tail=temp;
		}
	}
		if(head==tail)
		{
			delete head;
			head=tail=0;
		}
		else
		{
			head=head->next;
			delete head->prev;
			head->prev=0;
		}
}
template<class T>
void MyBigInt<T>::userMultiplyBigInt(string arr1,string arr2)
{
	MyBigInt<int>A,B,Result,Result2;
	A.usercreateBigInt(arr1);
	B.usercreateBigInt(arr2);
	Result.multiplyBigInt(A,B);
	Result2.updateBigInt(Result);
	int i=0;
	Result2.addToDLLHead(44);
	while(i!=44)
	{
		i=Result2.deleteFromDLLTail();
		DLLNode<T> *temp=new DLLNode<T> (i);
		if(head!=0)
		{
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=head->prev;
		}
		else
		{
		head=tail=temp;
		}
	}
		if(head==tail)
		{
			delete head;
			head=tail=0;
		}
		else
		{
			head=head->next;
			delete head->prev;
			head->prev=0;
		}
}
#endif
