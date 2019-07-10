#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* rlink;
	Node* llink;
};

int show(Node* x){
	while(x!=NULL){
		cout<<x->data<<"-------"<<endl;
		x = x->rlink;
	}
	return 0;
}

int main(){
	int ch, item;
	Node* head = NULL;
	Node* flag = NULL;
	Node* New = NULL;
	while(1){
		cout<<"1. Create a Linked List\n2. Insert\n3. Delete at first\n4. Delete at last\n5. Show\n6. EXIT"<<endl;
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter the Data"<<endl;
			head = new Node();
			cin>>head->data;
			head->rlink = NULL;
			head->llink = NULL;
			flag = head;
		break;
		case 2:
			cout<<"Enter the Data"<<endl;			
			New = new Node();
			cin>> New->data;
			New->llink=flag;
			flag->rlink=New;
			New->rlink = NULL;
			flag = New;
		break;
		case 3:
			head = head->rlink;
		break;
		case 4:
			flag->llink->rlink = NULL;
			flag->llink=NULL;
		break;
		case 5:
			show(head);
		break;
		default:
			cout<<"Thank You!";
		}	
		if(ch ==6 )
			break;
	}
}
