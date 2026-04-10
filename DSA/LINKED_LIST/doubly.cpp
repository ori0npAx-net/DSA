//DOUBLE LINKED LIST//
#include <iostream>
using namespace std;

struct llnode {
    int data;
    llnode* next;   
    llnode* prev;   //prev waly ka pointer
};
llnode* list = NULL;

//insert function
void insert(int value) {
    llnode* temp; 
    temp=(llnode*)malloc(sizeof(llnode)); 
   // llnode* temp = new llnode;
    temp->data = value;

    if (list == NULL) {
        temp->next = temp;
        temp->prev = temp;
        list = temp;
        return;
    }
    llnode* last = list->prev;
    temp->next = list;
    temp->prev = last;
    last->next = temp;
    list->prev = temp;
}

//display function
void display() {
    if (list == NULL) {
        cout<<"List is empty\n";
        return;
    }
    llnode* curr = list;
    do {
        cout<< curr->data<<" <-> ";
        curr = curr->next;
    } while (curr != list);

    cout<<"(back to head)\n";
}
//search function
void search(int key) {
    if (list == NULL) {
        cout << "List is empty\n";
        return;
    }
    llnode* curr = list;
    do {
        if (curr->data == key) {
            cout<<key<<"found in list\n";
            return;
        }
        curr = curr->next;
    } while (curr != list);

    cout<<key<<"not found\n";
}

//delete function
void del(int value) {
    if (list == NULL) {
        cout<<"List is empty\n";
        return;
    }
    llnode* curr = list;
        if (curr->data == value && curr->next == curr) {        //single node
        delete curr;
        list = NULL;
        cout<<"Value deleted\n";
        return;
    }

    do {
        if (curr->data == value) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if (curr == list)
                list = curr->next;
            delete curr;
            cout<<"Value deleted\n";
            return;
        }
        curr=curr->next;
    } while (curr != list);

    cout<<"value not found\n";
}


int main() {
    insert(5);
    insert(9);
    insert(10);
    display();
    search(9);
    del(5);
    display();
}
