

#include <bits/stdc++.h>
using namespace std;

int movecount = 0;

void pm(int start, int end){
    cout<<start<<"->"<<end<<endl;
    movecount++;
    return;
}

void th(int n, int start, int end){
    if(n==1){
        pm(start, end);
        return;
    }
    else{
        int other;
        other = 6 - (start+end);
        th(n-1, start, other);
        pm(start, end);
        th(n-1, other, end);
    }
}


int main() {

    int disc;
    cout<<"Enter number of discs: ";
    cin>>disc;
    th(disc, 1, 3);
    cout<<"Number of Move: "<<movecount;
    return 0;
}
