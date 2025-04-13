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
    //int n = 8;
    //int array[n]={25,57,48,37,12,92,86,33};
    cout<<"Element to search: ";
    cin>>s;
    for(int i=0; i<n; i++){
        if(array[i]==s){
            cout<<"Element: "<<s<<" found at "<<i<<endl;
            continue;
        }
        else{cout<<"Element not found";}
    }
    return 0;
}