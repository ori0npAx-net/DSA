#include <iostream>
using namespace std;


int linear_recursion(int index, int space_size, int space[],int number){
    if(index < space_size){
        if(number == space[index]){
            cout<<"element found at index: "<<index;
            return 0;
        }
        else{    
            return linear_recursion(index+1, space_size, space, number);
        }
        return -1;
    }
    return -1;
}
   
int main(){
    int space[15]={12,10,78,56,4,55,44,2,1,36,98,5,88,75,16};
    int tofind;
    cout<<"enter an element to find through linear recurison: ";
    cin>>tofind;
    int result=linear_recursion(0,15,space,tofind);
    if (result == -1){
        cout<<"element not found";
    }
}