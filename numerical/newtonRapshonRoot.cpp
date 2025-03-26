#include <bits/stdc++.h>
using namespace std;
// define question as asked in question
#define f(x) (x * x * x - 2 * x - 5)
#define g(x) (3 * x * x - 2)  
#define e 0.001f

void newtonRaphson(float x0) {
    int step = 0;
    float x, fx, gx;
    
    cout << fixed << setprecision(3);
    cout << "step    x       fx       gx      xn" << endl;

    do {
        fx = f(x0);
        gx = g(x0);
        
        x = x0 - (fx / gx);  
        
        cout << step << "    " << x0 << "    " << fx << "    " << gx << "    " << x << endl;
        
        step++;
        x0 = x;
    } while (abs(fx) > e);  
    
    cout << "Root is: " << x << endl;
}

int main() {
    float x0 = 3.0f;  
    newtonRaphson(x0);
    return 0;
}