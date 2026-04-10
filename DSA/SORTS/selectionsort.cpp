// SELECTION SORT//

#include <iostream>
using namespace std;
int main(){
	int arr[]={7,4,2,9,1};
	int n=5;
	for (int i=0;i<n-1;i++){
		int mini=i;
		for (int j=i+1;j<n;j++){
			if (arr[j]<arr[mini]){
				mini=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[mini];
		arr[mini]=temp;
	}
	cout<<"selection sort\n";
	for (int i=0;i<5;i++){
		cout<<arr[i];
	}
}