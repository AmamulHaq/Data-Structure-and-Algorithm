#include <iostream>
using namespace std;

int main() {
    int SIZE,min=0;
    cout<<"Enter no of elements: ";
    cin>>SIZE;
    int array[SIZE];
    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < SIZE; i++) {
        cin >>array[i];
    }
    //bubble sort with i =0 , j=0
    for (int i = 0; i < SIZE-1; i++)
    {
        for (int j = 0; j < SIZE-i-1; j++)
        {
            if (array[j] > array[j+1]){
            swap(array[j] , array[j+1]);
            }
        }
    }//
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
