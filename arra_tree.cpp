#include<iostream>
using namespace std;
char tree[10];
int root(char key){
	if(tree[0]!='\0')
		cout<<"Tree already had root";
	else
		tree[0]=key;
	return 0;
}
int insert_left(char key, int parent){
	if(tree[parent]=='\0')
		cout<<"\nCan't set child at"<<(parent*2)+1<<" , no parent found";
	else
		tree[(parent*2)+1] = key;
	return 0;
}
int insert_right(char key, int parent){
	if(tree[parent]=='\0')
		cout<<"\nCan't set child at"<<(parent*2)+2<<" , no parent found";
	else
		tree[(parent*2)+2] = key;
	return 0;
}
int print_tree(){
	cout<<"\n";
	for(int i = 0; i<10;i++){
		if(tree[i]!='\0')
			cout<<tree[i];
		else
			cout<<"-";
	}
	return 0;
}
int main(){
	root('A');
	//insert_left('B',0);
	insert_right('C',0);
	insert_left('D',1);
	insert_right('E',1);
	insert_right('F',2);
	print_tree();
	return 0;
}
