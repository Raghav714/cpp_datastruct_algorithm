#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* link;
};
int show(Node* point){
	while(point!=NULL){
		cout<<point->data<<"---";
		point= point->link;
	}
	return 0;
}
int main(){
	Node* head = NULL;
	Node* tail = NULL;
	Node* New = NULL;
	int item, ch;
	do{
		cout<<"Enter the Choice:\n1. Insert\n2. Delete\n3. Show\n4. Exit";
		cin>>ch;
		cout<<"------------\n";
		switch(ch){
			case 1:
				cout<<"Enter the Data\n";
				cin>>item;				
				if(head == NULL){
					head = new Node();
					head->data = item;
					tail = head;
				}
				else{
					New = new Node();
					New->data = item;
					tail->link = New;
					tail = New;
				}
			break;
			case 2:
				cout<<head->data<<endl;
				head= head->link;
			break;
			case 3:
				show(head);
			break;
			default:
				cout<<"Thank You";
		}
	}while(ch!=4);
	return 0;
}
			
				
