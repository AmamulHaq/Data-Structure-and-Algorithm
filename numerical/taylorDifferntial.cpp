#include <bits/stdc++.h>
using namespace std;
//define function d1 as asked in question
float d1(float x, float y) { return x + y; }
float d2(float x, float y) { return 1 + d1(x, y); }
float d3(float x, float y) { return d2(x, y); }

int main() {
    float x0, y0, X, Y, h, p;
    cout<<"Give f(x,y)=x+y and y(0)=1, find y(0.3)=? with h=0.1"<<endl;
    cout << "Enter x0 and y0: " << endl;
    cin >> x0 >> y0;
    
    cout << "Enter prediction p and interval h: " << endl;
    cin >> p >> h;
    
    X = x0 + h;
    int n = (p-x0)/h;
    for (int i = 0; i < n; i++) {
        float y1 = d1(x0, y0);
        float y2 = d2(x0, y0);
        float y3 = d3(x0, y0);
        
        Y = y0 + h*y1 + h*h*y2/2 + h*h*h*y3/6;
        cout << "Prediction in step "<<i<<" : " << Y << endl;
        x0 = X;
        y0 = Y;
        X += h;
    }
    
    cout << "Prediction of " << p << " : " << Y << endl;
    return 0;
}