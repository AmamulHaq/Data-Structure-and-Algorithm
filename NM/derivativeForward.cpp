#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    float y1,y2, h, d[10];
    cout<<"Given datas x and y and find velocity and accelaration"<<endl;
    cout << "Enter interval h and no of column deltaY: " << endl;
    cin >> h >> n;
    cout << "Enter values of deltaY : "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    y1=(d[0]-d[1]/2+d[2]/3-d[3]/4)/h;
    cout << "First derivative (velocity): " << y1 << endl;
    y2=(d[1]-d[2]-d[3]*11/12)/(h*h);
    cout << "Second derivative (accelaration): " << y2 << endl;
    return 0;
}