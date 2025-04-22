#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size-1;
    while(low <= high){
        int mid = low + ((high-low)/2);
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main() {

    int arr[] = {5, 1, 3, 6, 2, 8, 7, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 2;

    sort(arr, arr+size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
         cout << arr[i] << " ";
    }
    cout<<endl;

    int index = binarySearch(arr, size, key);

    if(index == -1){
        cout<<"Not Found."<<endl;
    }
    else{
        cout<<"Found at "<<index<<endl;
    }

    return 0;
}
