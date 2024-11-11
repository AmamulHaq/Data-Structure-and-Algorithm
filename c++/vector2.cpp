#include<bits/stdc++.h>
using namespace std;
void vec(){
    vector<int>v(5,20);//[20,20,20,20,20]
    v.push_back(6);    //[20,20,20,20,20,6] to add 6 back ward
    v.push_back(7);    //[20,20,20,20,20,6,7] to add 7 back ward

    //to erase last element
    v.erase(v.end()-1);//[20,20,20,20,20,6]

    //to add elements in the middle of vector
    //vector( that position, no of element, value of element)
    v.insert(v.begin()+1,3,2);//[20,2,2,2,20,20,20,20,6]
    for(auto element: v){
        cout<<element;
    }cout<<endl;

    //to erase middle elemets
    //vector(that position, up to that position)
    v.erase(v.begin()+2,v.begin()+6);//[20,2,20,20,6 ]

    //alternative to print all vector
    for(auto element: v){
        cout<<element;
    }cout<<endl;

    //for total no of elements in vector
    cout<<v.size()<<endl;


    //to pop last element from vector
    v.pop_back();
    for(auto element: v){
        cout<<element;
    }cout<<endl;
    
    //to clear entire vector
    v.clear();
    cout<<bool(v.empty());

}
int main(){
    vec();
    return 0;
}