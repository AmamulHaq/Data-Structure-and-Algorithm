#include<bits/stdc++.h>
using namespace std;

void counter(int n){
    if(n==0) return;
    cout<<n<<" ";
    counter(n-1);
}
void backtrack(int n){
    if(n==0) return;
    backtrack(n-1);
    cout<<n<<" ";

}
int sumN(int n){
    if(n==0) return 0;
    return n+sumN(n-1);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int n;
    cout<<"enter no of terms: ";
    cin>>n;
    cout<<endl;
    counter(n);
    cout<<endl;
    backtrack(n);\
    cout<<endl;
    int s = sumN(n);
    cout<<s;

    return 0;
}