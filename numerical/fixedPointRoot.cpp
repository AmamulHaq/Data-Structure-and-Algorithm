#include <bits/stdc++.h>
using namespace std;
// for quadratic and periodic function

#define f(x) (1/(x-1))  // Rearranged from x² - x - 1 = 0 → x = 1/x-1
#define e 0.001f

void fixedPoint(float x0) {
    int step = 0;
    float x_prev, x_next;
    
    cout << fixed << setprecision(3);
    cout << "step    x0      xn" << endl;
    
    do {
        x_prev = x0;
        x_next = f(x0);
        
        cout << step << "    " << x_prev << "    " << x_next << endl;
        x0 = x_next;
        step++;
    } while (fabs(x_next - x_prev) > e);  
    cout << "Approximate root: " << x_next << endl;
}

int main() {
    float x0 = 0;  
    fixedPoint(x0);
    return 0;
}