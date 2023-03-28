#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_array(int* arr, int n) {
    cout << "[";
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << "]" << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;    // last swapped element
    int temp;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;    
            // swap
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        // else do nothing - then the larger element will get swapped with a smaller one that's higher up
    }
    temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;    //now pivot is at the correct place
    return i + 1;   // new position of pivot
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

double median(int arr[], int len) {
    int mid = len/2;
    double med;
    if (len % 2 == 0) {
        med = (float) (arr[mid - 1] + arr[mid]) / 2;
    } else {
        med = arr[mid];
    }
    return med;
}

int main() {

    int n, val;
    double med;

    cout << "Enter length of input stream: " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter numbers: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> val;
        arr[i] = val;
        quick_sort(arr, 0, i);
        cout << "Sorted: ";
        print_array(arr, i+1);
        cout << "Median: ";
        med = median(arr, i+1);
        printf("%.1f\n", med);
    }

    return 0;
}