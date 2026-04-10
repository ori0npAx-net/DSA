//CIRCULAR LINKED LIST//
#include <iostream>	
#include <stdlib.h>	
using namespace std;

//structure
struct llnode{		
	int data;
	llnode* next;	
};
llnode *list=NULL;	

//insert function
void insert(int value){
	
	llnode *temp;
	temp=(llnode*)malloc(sizeof(llnode));	
	temp-> data =value;
//	temp-> next =NULL;
	if(list==NULL){
		list=temp;
		temp->next=list;	//points to itself agar sirf aik element hai list mein
		return;
	}
	llnode *curr=list;
	while (curr->next!=list){	
		curr=curr->next;	
	}
	curr->next=temp;
	temp->next=list;
}

//
//void display(){
//	cout<<"the final list is: \n";
//	if (list==NULL){
//		cout<<"the list is empty\n";
//	}
//	else{
//		llnode *curr=list;
//		while (curr!=list){
//			cout<<curr->data<<"->";
//			curr=curr->next;
//			
//		}



	
	void display() {
    if (list == NULL) {
        cout << "the list is empty\n";
        return;
    }

    llnode* curr = list;
    do {
        cout << curr->data << "->";
        curr = curr->next;
    } while (curr != list);

    cout << "(back to head)\n";
}


int main(){
	insert(5);
	insert(9);
	insert(10);
	display();
}
