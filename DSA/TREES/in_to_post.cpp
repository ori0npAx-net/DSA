// infix expression to postfix //

#include<iostream>
using namespace std;

//---stack---//
char arr[10];
int top= -1;
char postfix[15];

void push(char value){
    if(top==10-1){
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

//---checks precedence of operator---//
int precedence(char op){
    switch(op){
        case '*':
        case '/':
        case '%':
            return 5;

        case '+':
        case '-':
            return 4;

        case '<':
        case '>':
            return 3;

        case '!':
        case '=':
            return 2;

        case '&':
            return 1;
        
        case '|':
            return 0;
        
        default:
            cout<<"invalid operator";
    }
}
char alpha_check(char op){
    switch(op){
        case 'a':
            return 'a';
        case 'b':
            return 'b';
        case 'c':
            return 'c';
        case 'd':
            return 'd';
        default:
            return -1;
    }
}
char operato(char op){
    // int returned=precedence(op);
    // if (returned==5){
        if(arr==NULL){      //stack is empty tou direct push
            push(op);
        }
        
        if(precedence(op)>=precedence(arr[top])){   //stack ke top mein jobhi hai uski precedence check karenge with that of op
                push(op);
            }

        else{
            for(int i=0;i<10;i++){
                if(precedence(op)<=precedence(arr[top])){
                    postfix[i]=arr[top];
                    pop;
                    }
                break;
            }

        }
        return;
    }
int i=0;
char operand(char op){
    postfix[i]= op;
    i++;
    return;
}

char in_to_post(char op){      //differentiate bw operand and operator then us hisaab se call hoga function
    if(alpha_check(op)!= -1){
        operand(op);
    break;
    }
    else{
        operato(op);
    }
    return;
}
int main(){
    char infix[]={'a','+','b','/','c','+','d','\0'};    //array of characters
    for (int i=0; i<7-1; i++){
        char ch=infix[i];
        in_to_post(ch);
    }
}
