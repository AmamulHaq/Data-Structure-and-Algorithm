#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> m;
    m.insert({3,"binod"});
    m.insert({1,"raksh"});
    m.insert({2,"amamul"});
    m.insert({6,"bbsa"});
    //to erase of key
    m.erase(3);
    //to display keys and coressponding value
    for(auto element: m){
        cout<<element.first<<" "<<element.second<<endl;
    }cout<<endl;
    //specific value
    cout<<m[2]<<endl;
    //keys value are
    for(auto element: m){
        cout<<element.first<<"\t";
    }
    

}