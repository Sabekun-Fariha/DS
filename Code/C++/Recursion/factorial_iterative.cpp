#include <bits/stdc++.h>

using namespace std;

int recursiveFactorial(int n){
    int factorial = 1;
    for(int i=1; i<=n; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<recursiveFactorial(n);
    cout<<endl;
}