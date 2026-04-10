//stack using array
#include<iostream>
using namespace std;

int arr[7];
int top= -1;

void push(int value){
    if(top==7-1){
        cout<<" Stack Overflow. Cannot PUSH value";
        return;
    }
    else{
        top++;
        arr[top]=value;
    }
}

void pop(){
    if (top==-1){
        cout<<"Stack Underflow";
        return;
    }
    top--;
}

void Display(){
    if(top==-1){
        cout<<"Stack is empty.....";
        return;
    }
    cout<<"Stack is: \n";
    for (int i=-1; i>=0; i++){
        cout<<arr[i]<<"\n";
    }
}