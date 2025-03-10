#include <iostream>
#include <string>
using namespace std;

void toh(char source, char auxiliary, char sink, int n) {
    if (n == 0) {
        return;
    }
    toh(source, sink, auxiliary, n - 1);
    cout<<"Move disk: "<<n<<" from: "<<source<<" to: "<<sink<<endl;
    toh(auxiliary, source, sink, n - 1);
}
int main(){
    int n=3;
    toh('A','B','C',n);
}