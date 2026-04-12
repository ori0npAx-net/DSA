//LINEAR SEARCH
#include <iostream>
using namespace std;

int main() {//main ka function, sab kaam main ke function mein hota hai, kuch bhi globally nahi hota
int space[15]={12,10,78,56,4,55,44,2,1,36,98,5,88,75,16};
int number;
cout<<"enter element: ";
cin>>number;

for (int i=0;i<15;i++){
	if (number==space[i]){
		cout<<"number found at index: "<<i;
		return 0;
	}
}
	cout<<"element not found in space";
}