//---MERGE SORT---//

#include <iostream>
using namespace std;


int arr[10]={32,55,12,1,89,44,34,90,12,56};

void merge(int arr[], int left, int mid, int right)
{
    int i = left;      // left half start
    int j = mid + 1;   // right half start
    int k = 0;
    int temp[15];    
    while (i <= mid && j <= right){ //compare
        if (arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int x = 0; x < k; x++){
        arr[left + x] = temp[x];
    }
}
   
void MergeSort(int L, int R){
    if (L< R){
    int mid=(L+R)/2;
    MergeSort(L,mid);    //left half
    MergeSort(mid+1,R);    //right half
    merge(arr,L,mid,R);
    }
}
int main(){

    MergeSort(0,9);

    for (int i=0;i<10;i++){
        cout<<arr[i]<<"->";
    }

}