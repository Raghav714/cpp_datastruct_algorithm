#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* left_child;
	Node* right_child;
};

int insert(Node* root, int key){
	Node* New = NULL;
	New = new Node();
	Node* pos = NULL;
	New->data = key;
	while(root){
		pos = root;
		if((root->data) <= key)			
			root = root->right_child;
		else
			root = root->left_child;
	}
	if(pos->left_child ==NULL)
		pos->left_child = New;
	else
		pos->right_child = New;
	return 0;
}

int Inorder(Node* root){
	if(!root)
		return 0;
	Inorder(root->left_child);
	cout<<root->data<<"  ";
	Inorder(root->right_child);
	return 0;
}
int main(){
	Node* root = NULL;
	int ch, item;
	do{
		cout<<"\nEnter the Choice:-\n 1. Insert\n 2. Show\n 5. Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter the Data to Enter\n";
				cin>>item;
				if(root == NULL){
					root = new Node();
					root->data = item;
				}
				else
					insert(root,item);				
			break;
			case 2:
				Inorder(root);
			break;
			default:
			cout<<"\nThank You!!";
			}
	}while(ch!=5);
	return 0;
}
