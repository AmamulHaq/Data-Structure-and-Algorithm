#include <bits/stdc++.h>
using namespace std;
#define f(x,y) (x+y)

int main(){
    float x0,y0,p,y,h;
    cout<<"Give f(x,y)=x+y and y(0)=1, find y(0.3)=? with h=0.1"<<endl;
    cout << "Enter x0 and y0: " << endl;
    cin >> x0 >> y0;
    
    cout << "Enter prediction p and interval h: " << endl;
    cin >> p >> h;
    int n = (p-x0)/h;

    for(int i=0;i<n;i++){
        y=y0+h*f(x0,y0);
        cout << "Prediction in step "<<i<<" : " << y << endl;
        x0=x0+h;
        y0=y;
    }
    cout << "Prediction of " << p << " : " << y << endl;
}