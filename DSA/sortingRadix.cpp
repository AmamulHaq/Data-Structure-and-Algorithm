#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void radixSort(int arr[], int size) {
    stack<int> buckets[10];
    int maxDigits = 3;
    int divisor = 1;
    
    for (int pass = 0; pass < maxDigits; pass++) {
        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / divisor) % 10;
            buckets[digit].push(arr[i]);
        }
        
        int index = 0;
        for (int i = 0; i < 10; i++) {
            vector<int> temp;
            while (!buckets[i].empty()) {
                temp.push_back(buckets[i].top());
                buckets[i].pop();
            }
            for (int j = temp.size() - 1; j >= 0; j--) {
                arr[index++] = temp[j];
            }
        }
        
        divisor *= 10;
    }
}

int main() {
    int SIZE;
    
    cout << "Enter number of elements: ";
    cin >> SIZE;
    
    int arr[SIZE];

    cout << "Enter the elements: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }
    
    radixSort(arr, SIZE);

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << (i == 0 ? "" : " ") << arr[i];
    }
    cout << endl;

    return 0;
}
