#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* link;
};
int show(Node* point){
	while(point!=NULL){
		cout<<point->data<<endl;
		point= point->link;
	}
	return 0;
}
Node* pop(Node* point){
	int item = point->data;
	point = point->link;
	cout<<item<<endl;
	return point;
}
Node* push(Node* point){
	int item;
	cout<<"Enter the data to push\n";
	cin>>item;
	Node * New = NULL;
	New = new Node();
	New->data = item;
	New->link = point;
	return New;
}
int main(){
	int ch;
	Node* head = NULL;
	do{
		cout<<"Enter Your choice\n1. push\n2. Pop\n3. show\n4. Exit"<<endl;
		cin>>ch;
		cout<<"--------------------\n";
		switch(ch){
		case 1:
			head = push(head);
		break;
		case 2:
			head = pop(head);
		break;
		case 3:
			show(head);
		break;
		default:
			cout<<"\nThank You!!";
		}
	}while(ch!=4);
	return 0;
}
