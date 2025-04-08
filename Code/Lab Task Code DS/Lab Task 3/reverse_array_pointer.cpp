#include <bits/stdc++.h>

using namespace std;

void reverse_array(int *arr, int size){

    int *start = arr;
    int *end = arr+size-1;

    while(start<end){
        swap(*start, *end);
        start++;
        end--;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>*(arr+i);
    }

    reverse_array(arr, n);

    for(int i=0; i<n; i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<"\n";

    return 0;
}