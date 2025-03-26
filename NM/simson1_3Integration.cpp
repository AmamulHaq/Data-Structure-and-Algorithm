#include <bits/stdc++.h>
using namespace std;
//define function as asked in question
#define f(x) (cos((x) * M_PI / 180.0))

int main() {
    float x0, u, l, h, Y = 0;
    int n;

    cout << "Enter lower limit (in degrees): ";
    cin >> l;
    cout << "Enter upper limit (in degrees): ";
    cin >> u;
    cout << "Enter number of intervals: ";
    cin >> n;

    h = (u - l) / n;
    float y[n+1];  
    x0 = l;

    for (int i = 0; i <= n; i++) {
        y[i] = f(x0);
        cout << "f(" << x0 << ") = " << y[i] << endl;
        x0 += h;
    }

    // Simpson 1/3 Rule
    Y = y[0] + y[n];
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {  // Odd indices (1, 3, 5,...)
            Y += 2 * y[i];
        } else {           // Even indices (2, 4, 6,...)
            Y += 4 * y[i];
        }
    }
    Y *= h / 3;

    cout << "Integration using Simpson 1/3 Rule: " << Y << endl;
    return 0;
}