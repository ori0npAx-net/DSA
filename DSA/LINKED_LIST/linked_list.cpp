
#include <iostream>	//to use cout and cin
#include <stdlib.h>	//to use malloc
using namespace std;


//structure
struct llnode{		
	int data;
	llnode* next;	
};
llnode *list=NULL;	//declaring a list of type llnode which is null and asterick shows address inshort, list is a pointer variable

//insert function
void insert(int value){
	//memory allocate + address hold
	llnode *temp;
	temp=(llnode*)malloc(sizeof(llnode));	//typecasting (llnode*) kiunke woh direct without any type ke memory allocate kareyga we have to type cast it into the one we are using
	//write/save value on allocated memory
	temp-> data =value;
	temp-> next =NULL;
	if(list==NULL){
		list=temp;
		return;
	}
	llnode *curr=list;
	while (curr->next!=NULL){	//staying in the loop till we get a node(curr->next) which is null
		curr=curr->next;	
	}
	curr->next=temp;
//	cout<<"enter next number to add in list:";
}
void search(int value){
	
		llnode *curr=list;
		while(curr!=NULL){
			if (curr->data==value){
				cout<<"number has been found/n";
				return;
			}
			curr=curr->next;
		}
		cout<<"number does not exist in the list/n";
}
void delet(int value){
	if (list==NULL){
		cout<<"list is empty";
		return;	
	}
	llnode *curr=list;
	// if (value==list->data){	//handled below
	// 	list=list->next;
	// 	free(curr);
	// 	cout<<"value deleted\n";
	// 	return;
	// }
	llnode *prev=NULL;		//holds address of the list as the previous one kiunke first wala tou match nahi kiya so now we need two variables i.e;prev and curr
	while (curr!=NULL){
		if (value==curr->data){
			if(prev==NULL){		//deletes first node
				list=curr->next;	//head update-link create
			}
			else{
				prev->next=curr->next;	//link banadiya agar na banaty tou data lost hojata list break hojata
			}
			free (curr);
			cout<<"value has been deleted\n";			
			return;	
		}
		prev=curr;
		curr=curr->next;
		
	}
	cout<<"number not found";
	}

//------SIMPLE DISPLAY------//

// void display(){
// 	cout<<"the final list is\n";
// 	if (list==NULL){
// 		cout<<"EMPTY\n";
// 	}
// 	else{
// 		llnode *curr=list;
// 		while(curr!= NULL){
// 			cout<<curr->data<<" ->";
// 			curr=curr->next;
// 		}
// 	}
// }

void recursion(llnode*curr){	//recursive function actual kaam yahin horaha hai
	
	if (curr==NULL){
		return;
	}
	cout<<curr->data<<" ->";
	curr=curr->next;
	recursion(curr);
}

void display(){			//wrapper function
	cout<<"the final list is:\n";
	if (list==NULL){
		cout<<"EMPTY\n";
		return;
	}	
	recursion(list);
}

void reverse_recursion(llnode* curr){		//for reverse display 
	if (curr ==NULL){
		return;
	}
	//curr=curr->next;
	reverse_recursion(curr->next);
	cout<<curr->data<<"->";
	
}
void Reversedisplay(){
	cout<<"the reversed list is:\n";
	if(list==NULL){
		cout<<"EMPTY\n";
		return;
	}
	reverse_recursion(list);

}



int main(){
//	insert(4);
//	insert(5);
//	display();
	//cout<<list;
	while (true){
	cout<<"Press any number from 1-6 to perform the respective action\n";
	cout<<"1-insertion\n2-search\n3-delete\n4-display\n5-Reversedisplay\n6-exit";
		int choice;
	cin>>choice;
	if (choice==1){
		int num;
		cout<<"enter a number to insert in the list: ";
		cin>>num;
		insert(num);
	}
	if (choice==2){
		int num;
		cout<<"enter a number to search: ";
		cin>>num;
		search(num);
	}
	if(choice==3){
		int num;
		cout<<"enter a number to delete from the list; ";
		cin>>num;
		delet(num);
	}
	if (choice==4){
		display();
	}
	if (choice==5){
		Reversedisplay();
	}
	if (choice==6){
		cout<<"program ended";
		break;
	}
	
}

}




//int main(){
	//ask user for choice
	//usr press 1 -->insertion
	//user press 2 -->serach
	//user press 3-->delete
	//user press 4-->display
	//user press 5-->exit
//}
