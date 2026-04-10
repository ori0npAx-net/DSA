#include<iostream>
using namespace std;

int main() {
    int arr[] = {5,2,4,6,1,67,34,12,90};
    //int n = sizeof(arr)/sizeof(arr[0]);
	int n=9;
    for (int i = 1; i < n; i++) {
        int hold = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < hold) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hold;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
