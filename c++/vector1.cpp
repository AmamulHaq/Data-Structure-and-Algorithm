#include<bits/stdc++.h>
using namespace std;
void vec(){
    vector<int>v(5,20);//[20,20,20,20,20]
    v.push_back(6);    //[20,20,20,20,20,6]
    v.push_back(7);    //[20,20,20,20,20,6,7]

    //to access any element
    vector<int>::iterator it = v.begin();
    //it+=5;
    //cout<<*it;

    //to print that vector
    vector<int>::iterator all = v.end();
    
    while(*it!=*all){
    cout<<*it;
    it++;
    }

}
void vet(){
    vector<string> v (3,"amamul");//[amamul,amamul,amamul]
    v.push_back("khan");
    v.push_back("786");

    //to access any name;
    vector<string>::iterator it = v.begin();
    //it+=1;
    //cout<<*it;

    //to print that vector
    auto all = v.end();
    
    while(*it!=*all){
    cout<<*it;
    it++;
    }
    cout<<endl;

    //alternative to print all vector
    for(auto element: v){
        cout<<element;
    }


}

int main(){
    //vec();
    vet();
    return 0;
}