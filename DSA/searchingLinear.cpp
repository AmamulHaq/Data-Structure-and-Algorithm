#include <iostream>
using namespace std;
int main() {
    int n,s;
    cout<<"Enter no of elements: ";
    cin>>n;
    int array[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"Element to search: ";
    cin>>s;
    for(int i=0; i<n; i++){
        if(array[i]==s){
            cout<<"Element: "<<s<<" found at "<<i<<endl;
            continue;
        }
    }
    return 0;
}