#include <bits/stdc++.h>
using namespace std;
//define function as asked in question
#define f(x) (x * x * x - 2 * x - 5)
#define e 0.001f

void bisection(float a, float b) {  
    int step = 0;
    float x, fx;
    
    cout << fixed << setprecision(3);
    cout <<"step    a       b       x       fx"<<endl;
    
    do {
        x = (a + b) / 2;
        fx = f(x);
        
        cout << step << "   " << a << "   " << b << "   " << x << "   " << fx << endl;
        
        if (fx < 0) {
            a = x;
        } else {
            b = x;
        }
        step++;
    } while (abs(b - a) > e);  
    
    cout << "Root is: " << x << endl;
}

int main() {
    float x1 = 2, x2 = 3;
    
    if (f(x1) * f(x2) < 0) {  
        bisection(x1, x2);
    } else {
        cout << "No root exists in the given interval" << endl;
    }
    
    return 0;
}