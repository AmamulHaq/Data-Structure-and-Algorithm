#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float x0, y0, x, y, h, p, d[10];

    cout << "Enter xp interpolation, interval h and no of column dY: " << endl;
    cin >> x >> h >> n;
    cout << "Enter x0, y0 and values of dY : ";
    cin >> x0 >> y0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    p = (x - x0) / h;
    y = y0;
    float P = p;
    int fact = 1;
    
    // Newton Forward Interpolation formula
    for (int i = 1; i <= n; i++) {
        y += P * d[i-1] / fact;
        P *= (p - i);
        fact = fact*(i + 1);
    }
    
    cout << "Prediction of " << x << " : " << y << endl;
    return 0;
}