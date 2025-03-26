#include <iostream>
using namespace std;

int main() {
    int SIZE;
    cout << "Enter no of elements: ";
    cin >> SIZE;
    int array[SIZE];

    cout << "Enter elements: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> array[i];
    }
// selection sort for min index
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(array[i],array[min]);
        }
    }
//
    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
