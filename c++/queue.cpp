#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
//front view
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;

//back view
    cout<<q.back()<<endl;
    q.emplace(9);
    cout<<q.back()<<endl;



}