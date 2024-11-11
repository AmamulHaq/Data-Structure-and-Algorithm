#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void list1(){
    //list uses all methods that are in vector
    list<int> l(3,7);
    l.push_back(4);
    l.push_front(3);
    for(auto element: l){
        cout<<element;
    }cout<<endl;

    l.pop_front();
    l.pop_front();

    for(auto element: l){
        cout<<element;
    }cout<<endl;


}
int main(){
list1();
}