#include <bits/stdc++.h>
using namespace std;

//define fuction as asked in question
#define f(x) (1/x)

int main() {
    float l, u, h = 0, Y = 0, I[6];
    int n=2;
    
    cout << "Enter lower limit: ";
    cin >> l;
    cout << "Enter upper limit: ";
    cin >> u;
    
    for(int k=0;k<3;k++){
        h = (u - l) / n;
        float y[n+1], x = l;
        
        for(int i = 0; i <= n; i++, x += h) {
            y[i] = f(x);
            cout << "f(" << x << ") = " << y[i] << endl;
        }
        
        Y = y[0] + y[n];
        for(int i = 1; i < n; i++) Y += 2*y[i];
        Y *= h/2;
        I[k]=Y;
        cout << fixed << setprecision(4);
        cout << "Integration I"<<k+1<<" : " << Y << endl;
        cout <<endl;
        n=n*2;
    }  
    
    I[3]=I[1]+(I[1]-I[0])/3;
    cout << "Integration I[3]: "<< I[3] << endl;
    I[4]=I[2]+(I[2]-I[1])/3;
    cout << "Integration I[4]: "<< I[4] << endl;
    I[5]=I[4]+(I[4]-I[2])/3;
    cout << "Integration I[5]: "<< I[5] << endl;

    cout << fixed << setprecision(4);
    cout << "Integration using Romberg Rule: " << I[5] << endl;
    return 0;
}