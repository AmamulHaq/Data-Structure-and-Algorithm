#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float X[5], Y[5], x, y, d[10];

    cout << "Enter xp interpolation, no of column dY: " << endl;
    cin >> x >> n;
    cout << "Just beside xp, Enter values of dy: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for(int i=0; i<=n; i++) {
        cout << "Enter x" << i << " and y" << i << endl;
        cin >> X[i] >> Y[i];
    }
    
    y = Y[0];
    // Newton Divided Difference InEqual Interval Interpolation
    float product = 1.0;
    for(int i=1; i<=n; i++) {
        product *= (x - X[i-1]);
        y += product * d[i-1];
    }
    
    cout << "Prediction of " << x << " : " << y << endl;
    return 0;
}