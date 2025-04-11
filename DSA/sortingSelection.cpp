#include <iostream>
using namespace std;

int main() {
    int SIZE = 8;
    int array[8] ={25,57,48,37,12,92,86,33};
/* selection sort for min index
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
*/
    // Selection sort for max index
    for (int i = SIZE-1; i >= 0; i--) {
        int max = 0;
        for (int j = 1; j <=i ; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        swap(array[max], array[i]);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
