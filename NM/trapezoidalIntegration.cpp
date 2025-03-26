#include <bits/stdc++.h>
using namespace std;

//define fuction as asked in question
#define f(x) (cos((x) * M_PI / 180.0))

int main() {
    float l, u, h = 0, Y = 0;
    int n;
    
    cout << "Enter lower limit: ";
    cin >> l;
    cout << "Enter upper limit: ";
    cin >> u;
    cout << "Enter number of data points: ";
    cin >> n;

    h = (u - l) / n;
    float y[n+1], x = l;
    
    for(int i = 0; i <= n; i++, x += h) {
        y[i] = f(x);
        cout << "f(" << x << ") = " << y[i] << endl;
    }
    
    Y = y[0] + y[n];
    for(int i = 1; i < n; i++) Y += 2*y[i];
    Y *= h/2;
    
    cout << fixed << setprecision(4);
    cout << "Integration using Trapezoidal Rule: " << Y << endl;
    return 0;
}