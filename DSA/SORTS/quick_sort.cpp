#include <iostream>
using namespace std;


int arr[10]={23,56,11,78,34,90,22,98,12,33};       //global array

int set_pivot(int L , int R){
    int pivot_index = (L+R)/2;
while(L<R){
    //---right most comparision---//
    while(R!=pivot_index){
        if(arr[pivot_index]>arr[R]){

        //swap and change index//
            int temp=arr[pivot_index];
            arr[pivot_index]=arr[R];
            arr[R]=temp;
            pivot_index=R;
            break;
        }else{
        // if(R==pivot_index){
        //     return;
        // }
            R--;
    }
}

    //---leftmost comparision---//
    while(L!=pivot_index){
        if(arr[pivot_index]<arr[L]){
            int temp=arr[pivot_index];
            arr[pivot_index]=arr[L];
            arr[L]=temp;
            pivot_index=L;
            break;
        }else{
            L++;
        }
        
    }
}
   // cout<<pivot_index;
    return pivot_index;
}


void Quicksort(int L, int R ){
    if (L<R){
        int pivot_index=set_pivot(L,R);
        Quicksort(L,pivot_index-1);
        Quicksort(pivot_index+1,R);
    }

}

int main(){
    //cout<<pivot_index;
    Quicksort(0,9);

    for (int i=0;i<10;i++){
        cout<<arr[i]<<"->";
    }

}








