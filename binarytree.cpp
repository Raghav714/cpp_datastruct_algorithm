#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left_child;
	Node* right_child;
};

Node* loc = NULL;
int Inorder(Node* root){
	if(!root)
		return 0;
	Inorder(root->left_child);
	cout<< root->data <<"----";
	Inorder(root->right_child);
	return 0;
}
int Preorder(Node* root){
	if(!root)
		return 0;
	cout<<root->data<<"----";
	Preorder(root->left_child);
	Preorder(root->right_child);
	return 0;
}
int Postorder(Node* root){
	if(!root)
		return 0;
	Postorder(root->left_child);
	Postorder(root->right_child);
	cout<< root->data <<"----";
	return 0;
}
int degree(Node* n){
	if(n->left_child == NULL and n->right_child == NULL)
		return 0;
	else if(n->left_child == NULL or n->right_child == NULL)
		return 1;
	else
		return 2;
}
int Insert(Node* root, int key){
	if(!root)
		return 0;
	Insert(root->left_child, key);
	if(degree(root)==1){
		cout<<"\ndegree data "<<root->data<<"is " <<degree(root);
		Node* New = NULL;
		New = new Node();
		New->data = key;
		if(root->right_child==NULL)
		root->right_child = New;
		else
		root->left_child = New;
		return 0;
	}
	Insert(root->right_child,key);
	return 0;
}
int hight(Node* root){
	if(!root)
		return 0;
	int lhight = hight(root->left_child);
	int rhight = hight(root->right_child);
	if(lhight>rhight)
		return (lhight+1);
	else
		return (rhight+1);
}
int find(Node* root,int key){
	if(!root)
		return 0;
	if (key==root->data){
		loc = root;}
	else{
		find(root->left_child, key);
		find(root->right_child, key);
	}	
}
int deletenode(Node* root, int key){
	int x;
	Node* point = root;
	//cout<<"point data"<<point->data;
	find(root, key);
	cout<<"\nloc "<<loc;
	while(point->right_child){
		if(degree(point->right_child)==0){
			x = point->right_child->data;
			point->right_child = NULL;
		}
		else
			point = point->right_child;
	}
	loc->data = x;
	return 0;
}
int main(){
	Node* root = NULL;
	//Node* first = NULL;
	Node* second = NULL;
	root = new Node();
	//first = new Node();
	second = new Node();
	root->data = 3;
	//first->data = 5;
	second->data = 7;
	//root->left_child = first;
	root->right_child = second;
	Insert(root,5);
	cout<<"\nHight "<<hight(root);
	find(root,7);
	cout<<"\n data "<<loc->data;
	deletenode(root,5);
	//cout<<"degree of 1:- " << degree(root);
	//cout<<"degree of 2:- " << degree(first);
	//cout<<"degree of 3:- " << degree(second);		
	cout<<"\nInorder";
	Inorder(root);
	cout<<"\nPreorder";
	Preorder(root);
	cout<<"\nPostorder";
	Postorder(root);
	return 0;
}
