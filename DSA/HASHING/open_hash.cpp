// OPEN HASHING
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node hashtab[10];

void insert(int value){
    int index=value%10;     //hashfunction
    if (hashtab[index].data==-1){   //first element static hai and empty hai
        hashtab[index].data=value;
        hashtab[index].next=NULL;
    }
    else                  //first element hai list ka 
    {
        Node* temp=new Node;        //jo user ne di hongi
        temp->data=value;
        temp->next=NULL;

        if(hashtab[index].next==NULL){
            hashtab[index].next = temp;
        }
        else                //traverse cuz list bhi hai first element bhi hai we might have multiple elements
        {
            Node* curr=hashtab[index].next;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=temp;
        }
    }

}
void display()
{
    cout << "Hash Table:" <<endl;
    for(int i = 0; i < 10; i++)
    {
        if(hashtab[i].data == -1)
        {
            cout <<i<< ": -1"<<endl;
        }
        else
        {
            cout <<i<< " : " <<hashtab[i].data;
            Node*curr = hashtab[i].next;
            while(curr != NULL)
            {
                cout << "->" <<curr->data;
                curr = curr -> next;
            } 
            cout<<endl;
        }
    }   
}

void search(int value){
    int position=1;
    int index=value%10;
    if (hashtab[index].data==-1){

            cout<<"\nvalue not found";
            return;
        }
        else{
            if (hashtab[index].data==value){
                cout<<"value found at index: "<<index;
            }
            else{
                Node* curr= hashtab[index].next;
                while(curr->data!=value){
                    curr=curr->next;
                    position++;
                    if(curr->data==value){
                        cout<<"\nvalue found at index:"<<index<<"position:"<< position;
                        return;
                    }
                }
                //cout<<"\nvalue not found2";
                // if(curr->data==value){
                //     cout<<"\nvalue found at index: "<<index<<"and position: "<<position;
                // 
                // curr=curr->next;
                // position++;
            }
        }
    }



int main (){
    for (int i=0;i<10;i++){     //now all the hashtab.data are -1
    hashtab[i].data=-1;
    hashtab[i].next=NULL;
}
    insert(10);
    insert(53);
    insert(89);
    insert(33);
    insert(43);
    display();
    search(10);
    search(43);
    search(77);
}
