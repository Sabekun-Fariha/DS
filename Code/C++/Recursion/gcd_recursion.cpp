#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else if(a==0){
        return b;
    }

    return gcd(b, a%b);
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<"GCD: "<<gcd(a, b);

    return 0;
}