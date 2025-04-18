#include <bits/stdc++.h>
using namespace std;
#define f(x,y) (x+y)

int main(){
    float x0,y0,p,y,h,k1,k2,k3,k4;
    cout<<"Give f(x,y)=x+y and y(0)=1, find y(0.3)=? with h=0.1"<<endl;
    cout << "Enter x0 and y0: " << endl;
    cin >> x0 >> y0;
    
    cout << "Enter prediction p and interval h: " << endl;
    cin >> p >> h;
    int n = (p-x0)/h;
    for(int i=0;i<n;i++){
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        y=y0+(k1+2*k2+2*k3+k4)/6;
        cout << "Prediction in step "<<i<<" : " << y << endl;
        x0=x0+h;
        y0=y;
    }
    cout << "Prediction of " << p << " : " << y << endl;
}