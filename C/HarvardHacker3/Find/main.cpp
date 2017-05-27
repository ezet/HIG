#include <iostream>

const int K = 50;

bool RecurSearch(int value, int arr[], int n) {
  int mid = (n - 1) / 2;
  if (n == 0) {
    return false;
  } else if (arr[mid] < value) {
    return RecurSearch(value, arr+mid+1, n/2);
  } else if (arr[mid] > value) {
    return RecurSearch(value, arr, n/2);
  } else {
    return true;
  }
}

bool Search(int value, int arr[], int n) {
  int mid, begin = 0, end = n-1;
  while (begin <= end) {
    mid = begin + (end - begin) / 2;
    if (arr[mid] < value) {
      begin = mid + 1;
    } else if (arr[mid] > value) {
      end = mid - 1;
    } else {
      return true;
    }
  }
  return false;
}

int* Sort(int arr[], int n) {
  int *count = new int[K+1];
  int *out = new int[n];

  for (int i = 0; i <= K; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < n ; ++i) {
    count[arr[i]] += 1;
  }

  for (int i = 1; i <= K; ++i) {
    count[i] += count[i-1];
  }


  for (int i = n-1; i >= 0; --i) {
    out[count[arr[i]]-1] = arr[i];
    count[arr[i]] -= 1;
  }
  delete[] count;

  return out;
}

int main(int argc, char *argv[]) {
  //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  //std::cout << RecurSearch(1, arr, 10);
  //std::cout << RecurSearch(1, arr, 10) << '\n'
  //  << RecurSearch(2, arr, 10) << '\n'
  //  << RecurSearch(3, arr, 10) << '\n'
  //  << RecurSearch(4, arr, 10) << '\n'
  //  << RecurSearch(5, arr, 10) << '\n'
  //  << RecurSearch(6, arr, 10) << '\n'
  //  << RecurSearch(7, arr, 10) << '\n'
  //  << RecurSearch(8, arr, 10) << '\n'
  //  << RecurSearch(9, arr, 10) << '\n'
  //  << RecurSearch(10, arr, 10) << '\n';

  int arr2[] = { 50, 0, 2, 5, 20, 10, 50, 40, 10, 20, 5, 1 };
  int *arr3 = Sort(arr2, 12);
  for (int i = 0; i < 12; ++i) {
    std::cout << arr3[i] << '\n';
  }


  return 0;
}