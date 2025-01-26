#include<bits/stdc++.h>
using namespace std;

void pairs(){
    pair<string,string> p[]={{"binod","gaurab"},{"shrastha","aayusha"},{"rabin","ritushwar"}};

}
void pair0_2() {
    vector<pair<int, pair<string, string>>> p = {
        {0, {"binod", "gaurab"}},
        {2, {"ankush", "arpan"}}
    };

    p.insert(p.begin() + 1, {1, {"ammaul", "786"}});
    p.pop_back();

    p.erase(p.begin());

    for (auto &x : p) {
        cout << x.first << " -> " << x.second.first << " & " << x.second.second << endl;
    }
}
void pair2_2() {
    pair<pair<int, pair<string, string>>, pair<string, string>> p[] = {
        {{0, {"binod", "gaurab"}}, {"ammaul", "786"}},
        {{2, {"ankush", "arpan"}}, {"ritesh", "raman"}}
    };}

int main(){
    pair0_2();
}