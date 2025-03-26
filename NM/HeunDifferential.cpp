#include <bits/stdc++.h>
using namespace std;
#define f(x,y) (x+y)

int main(){
    float x0,y0,p,x,y,h,k1,k2;
    cout<<"Give f(x,y)=x+y and y(0)=1, find y(0.3)=? with h=0.1"<<endl;
    cout << "Enter x0 and y0: " << endl;
    cin >> x0 >> y0;

    cout << "Enter prediction p and interval h: " << endl;
    cin >> p >> h;
    for(int i=0;i<3;i++){
        k1=f(x0,y0);
        k2=f(x0+h,y0+k1*h);
        y=y0+(k1+k2)*h/2;
        cout << "Prediction in step "<<i<<" : " << y << endl;
        x0=x0+h;
        y0=y;
    }
    cout << "Prediction of " << p << " : " << y << endl;
}