#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<"is: "<<factorial(n);
    cout<<endl;
}