#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int arrays[5][100000];
int array_lengths[5] = {20000, 40000, 60000, 80000, 100000};



void merge(int arr[], int left, int mid, int right) {
    int n = right - left + 1;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1 + 1];
    int right_arr[n2 + 1];

    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left+i];
    }
    for (int i = 0; i < n2; i++) {
        right_arr[i] = arr[mid+1+i];
    }
    left_arr[n1] = INT_MAX;
    right_arr[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = 0; k < n; k++) {
        if (left_arr[i] <= right_arr[j]) {
            arr[left + k] = left_arr[i];
            i++;
        } else {
            arr[left + k] = right_arr[j];
            j++;
        }
    }
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    //cout << left << " " << right<<endl;
    //print_array(arr, 10);
}

void iter_merge_sort(int arr[], int n) {
    // sort parts of length 1, 2, 4, 8 etc
    int len = 1;
    int start, end, mid;
    while (len < n) {
        for (int i = 0; i < n; i += 2*len) {
            start = i;
            mid = i + len - 1;
            end = i + 2*len - 1;
            if (mid+1 >= n) break;
            if (end >= n) end = n - 1;
            merge(arr, start, mid, end);
        }
        len = len * 2;
    }
}

int main() {

    int num;
    clock_t start, end;
    double time_spent;
    
    cout << "Iterative Merge Sort" << endl;
    cout << "No. of elements" << "\t" << "Time" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        start = clock();
        //print_array(arrays[i], array_lengths[i]);
        
        //merge_sort(arrays[i], 0, array_lengths[i] - 1);
        iter_merge_sort(arrays[i], array_lengths[i]);
        //print_array(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / (double)CLOCKS_PER_SEC;
        printf("%d\t\t%.6f s\n", array_lengths[i], time_spent);
    }

    return 0;
}