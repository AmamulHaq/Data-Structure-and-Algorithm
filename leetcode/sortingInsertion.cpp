#include <iostream>
using namespace std;

int main() {
    int SIZE;
    cout<<"Enter no of elements: ";
    cin>>SIZE;
    int array[SIZE];
    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < SIZE; i++) {
        cin >>array[i];
    }
    //insertion algorithm
    for (int i = 1; i < SIZE; i++) {
        if (array[i - 1] > array[i]) {
            for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            swap(array[j - 1] , array[j]);
            }
        }
    }
    //
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
