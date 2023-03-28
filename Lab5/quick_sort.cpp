#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int arrays[5][100000];
//int array_lengths[5] = {3, 5, 7, 10, 15};
int array_lengths[5] = {20000, 40000, 60000, 80000, 100000};


void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

void iter_quick_sort(int arr[], int n) {
    int stack[n];
    int top = -1;
    top++;
    stack[top] = 0;
    top++;
    stack[top] = n - 1;
    int pivot, low, high;
    bool st = top >=0;

    while (top >= 0) {
        high = stack[top];
        top--;
        low = stack[top];
        top--;
        if (low >= high) continue;
        pivot = partition(arr, low, high);
        top++;
        stack[top] = low;
        top++;
        stack[top] = pivot - 1;
        top++;
        stack[top] = pivot + 1;
        top++;
        stack[top] = high;
    }
}

int main() {

    int num;
    clock_t start, end;
    double time_spent;
    
    cout << "Recursive Quick Sort" << endl;
    cout << "No. of elements" << "\t" << "Time" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        start = clock();
        //print_array(arrays[i], array_lengths[i]);
        
        quick_sort(arrays[i], 0, array_lengths[i] - 1);
        //iter_quick_sort(arrays[i], array_lengths[i]);
        //print_array(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / (double)CLOCKS_PER_SEC;
        printf("%d\t\t%.6f s\n", array_lengths[i], time_spent);
    }

    return 0;
}