//BINARY SEARCH//

#include <iostream>
using namespace std;

int main(){
int space[15]={12,10,78,56,4,55,44,2,1,36,98,5,88,75,16};
int number;
int left=0;
int right=15;
int mid=0;
cout<<"enter element: ";
cin>>number;

while(left<right){
	mid =(left+right)/2;
	if (number==space[mid]){
		cout<<"number found at "<<mid;
		return 0;
	}
	if (number<space[mid]){
			right=mid-1;
			break;
		}
		else{
			left=mid+1;
		}
	}
	
	
}

