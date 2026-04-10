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
    temp-> data =value; // temp-> next =NULL; 
    if(list==NULL){ 
        list=temp; 
        temp->next=list; //points to itself agar sirf aik element hai list mein return; 
    }
    llnode *curr=list; 
    while (curr->next!=list){ 
        curr=curr->next; 
    } 
    curr->next=temp; 
    temp->next=list; 
}

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

void search(int value) {
    if (list == NULL) {
        cout << "the list is empty\n";
        return;
    }

    llnode* curr = list;
    do {
        if (curr->data == value) {
            cout << "Value found in the list.\n";
            return;
        }
        curr = curr->next;
    } while (curr != list);

    cout << "Value not found in the list.\n";
}
void del(int value) {
    if (list==NULL){
        cout << "the list is empty\n";
        return;
    }

    llnode* curr = list->next;
    llnode* prev = list;

    if(list->data == value && list->next == list) {
        free(list);
        list = NULL;
        cout<<"value deleted successfully\n";
        return;
    }
    if (list->data == value) {
        while (curr->next != list) {    //last node dhond rahy
            curr = curr->next;
        }
        curr->next = list->next;    //link create kiya, list ka next jo ke second value thi usko save karwa diya in curr ke next mein., inshort link torr kar new link create kardiya
        llnode* temp = list;        //old head ko temp mein save karliya
        list = list->next;          //head ko update kar diya         
        free (temp);                //then temp ko delete kar diya
        cout << "Node deleted\n";
        return;
    }
    prev=list;              //first node
    curr=list->next;    //second node

    while (curr != list) {
        if(curr->data == value){
            prev->next=curr->next;  //link create,torr kar
            free(curr);
            cout<<"value deleted successfully\n";
            return;
        }
        prev = curr;        //aagey bhar gae
        curr = curr->next;  
    }
    
}


int main(){ 
    insert(5); 
    insert(9); 
    insert(10);
    insert(90);
    insert(1000); 
    display();
    search(9);
    search(150);
    del(5); 
    display();
    del(90);
    display();
    del(1000);
    display();
    search(5);
}
