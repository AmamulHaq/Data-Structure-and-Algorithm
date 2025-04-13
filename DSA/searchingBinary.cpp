#include <iostream>
using namespace std;

void quicksort(int arr[], int st, int end) {
  if(st < end) {
    int sep = st;
    for(int i = st + 1; i <= end; i++) {
      if(arr[st] > arr[i]) {
        swap(arr[++sep], arr[i]);
      }
    }
    swap(arr[st], arr[sep]);
    quicksort(arr, st, sep - 1);
    quicksort(arr, sep + 1, end);
  }
}

void binarySearch(int arr[], int st, int end, int s) {
    if (st <= end) {
        int mid = (st + end) / 2;
        if (arr[mid] == s) {
            cout << "Element: " << s << " found at index: " << mid << endl;
            return;
        }
        if (arr[mid] > s) {
            binarySearch(arr, st, mid - 1, s);
        } else {
            binarySearch(arr, mid + 1, end, s);
        }
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    int n, s;
    cout << "Enter no of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    //int n = 8;
    //int array[n]={25,57,48,37,12,92,86,33};

    quicksort(array, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << (i == 0 ? "" : " ") << array[i];
    }
    cout << endl;

    cout << "Element to search: ";
    cin >> s;
    binarySearch(array, 0, n - 1, s);

    return 0;
}
