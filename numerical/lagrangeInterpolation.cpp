#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float p;
    
    cout << "Enter no of complete data and point X of interpolation: " << endl;
    cin >> n >> p;
    float X[n], Y[n], term[n], sum = 0;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter value of x and y of term " << i + 1 << endl;
        cin >> X[i] >> Y[i];
    }
    
    for (int i = 0; i < n; i++) {
        term[i] = Y[i]; 
        for (int j = 0; j < n; j++) { 
            if (i != j) { 
                term[i] *= (p - X[j]) / (X[i] - X[j]); 
            }
        }
        cout << "Term " << i + 1 << " : " << term[i] << endl;
        sum += term[i];
    }
    
    cout << "Total prediction: " << sum << endl;
    
    return 0;
}