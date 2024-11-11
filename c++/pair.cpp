#include<bits/stdc++.h>
using namespace std;
void pair1(){
    pair<int,int> p[]={{1,2},{3,4}};
    cout<<p[0].first<<" "<<p[1].second<<endl;

}
void pair2(){
    pair<int,char> p[]={{1,'a'},{3,'b'}};
    cout<<p[0].second<<" "<<p[1].second<<endl;

}
void pair3(){
    pair<int,pair<int,char>> p[]={{5,{1,'a'}},{6,{3,'b'}}};
    cout<<p[0].second.second<<" "<<p[1].second.second<<endl;

}
int main(){
    pair1();
    pair2();
    pair3();
    return 0;
}