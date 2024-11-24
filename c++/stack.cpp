#include<bits/stdc++.h>
using namespace std;





int main(){
    stack<int>s;
    s.push(7);
    s.push(8);
    s.push(6);
    s.push(9);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

    //to print stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}