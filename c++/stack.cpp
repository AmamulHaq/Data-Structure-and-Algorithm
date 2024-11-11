#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    s.push(7);
    s.push(8);
    s.push(6);
    s.push(9);
    s.pop();

    stack<int>s1,s2;
    s1.swap(s2);
    cout<<s.top();
    cout<<s.size();
    cout<<s.empty();

}