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
    //int array[SIZE]={25,57,48,37,12,92,86,33};
    //exchange sorting i =0 and j = i+1 
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[i] > array[j]){
            swap(array[i] , array[j]);
            }
        }
    }   
    //
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
