#include <bits/stdc++.h>
using namespace std;
// define function as asked in question
#define f(x) (x * x * x - 2 * x - 5)
#define e 0.001f

void secant(float a, float b) { 
    int step = 0;
    float x, fx;

    cout << fixed << setprecision(3);
    cout << "step    a       b      fa      fb      x" << endl;

    do {
        float fa = f(a);
        float fb = f(b);
        x = (a * fb - b * fa) / (fb - fa);  
        fx = f(x);

        cout << step << "   " << a << "   " << b << "   " << fa << "   " << fb << "   " << x << endl;
        a=b;
        b=x;
        step++;
    } while (fabs(fx) > e);

    cout << "Root is: " << x << endl;
}

int main() {
    float x1 = 2, x2 = 3;

    if (f(x1) * f(x2) < 0) {
        secant(x1, x2);
    } else {
        cout << "No root exists in the given interval" << endl;
    }

    return 0;
}