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

int main() {
  int SIZE;
  
  cout << "Enter no of elements: ";
  cin >> SIZE;
  
  int arr[SIZE];

  cout << "Enter the elements: " << endl;
  for (int i = 0; i < SIZE; i++) {
    cin >> arr[i];
  }

  quicksort(arr, 0, SIZE - 1);

  cout << "Sorted array: ";
  for(int i = 0; i < SIZE; i++) {
    cout << (i == 0 ? "" : " ") << arr[i];
  }
  cout << endl;

  return 0;
}
