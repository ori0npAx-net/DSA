//  QUEUE using static array

#include <iostream>
using namespace std;

int queue[10];
int front=-1;
int rear=-1;

void EnQueue(int value){

    //full queue 
    if ((rear+1)%10==front){
        cout<<"queue OVERFLOW";
        return;
    }

    //for first element
    if (front==-1){
        front=rear=0;
    }
    else{
        rear=(rear+1)% 10;
    }
    queue[rear]=value;

}

void DeQueue(){
    if (front==-1){
        cout << "Queue UNDERFLOW(Empty)\n";
        return;
    }
    cout<<"deleted;"<<queue[front];

    //oly one element
    if (front ==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%10;
    }
}
void display(){
    if (front==-1){
        cout<<"queue is EMPTY";
        return;
    }
    int i=front;
    while (true){
        cout <<queue[i]<<" ";
        if (i==rear){
            break;
        }
        i=(i+1)%10;
    }
    cout<<endl;

}

int main(){
    int sel, flag = 0, val;

    while(flag == 0){
        cout << "\n\nSELECT FROM MENU\n"
             << "1. EnQueue\n"
             << "2. DeQueue\n"
             << "3. Display\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> sel;

        switch(sel){
        case 1:
            cout << "Enter value to EnQueue: ";
            cin >> val;
            EnQueue(val);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            flag = 1;
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
    
}
