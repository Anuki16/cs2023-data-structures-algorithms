#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int arrays[5][20000];
int array_lengths[5] = {500, 2000, 7500, 12000, 20000};



void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int cur_element = arr[i];
        int j = i - 1;
        while (arr[j] >= cur_element && j >= 0){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = cur_element;
    }
}

void bubble_sort(int* arr, int n) {
    int temp;
    for (int i = n; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void optimized_bubble_sort(int* arr, int n) {
    int temp;
    bool swapped = false;
    //print_array(arr, n);
    for (int i = n; i > 1; i--) {
        swapped = false;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swapped = true;
            }
        }
        //print_array(arr, n);
        if (!swapped) break;
    }
}

void opt_sort(int* arr, int array_size) {
    int i,j,value;
    bool swap = false;
    print_array(arr, array_size);
    for (i = 0; i < array_size - 1; i++){
        for (j = i; j < array_size - 1; j++){
            if(arr[j + 1] > arr[j]){
                value = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = value;
                swap = true;
            }
        }
        print_array(arr, array_size);
        if (!swap){
            break;
        }
    }
}

void selection_sort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = arr[i];
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_idx] = temp;
    }
}



int main() {

    int num;
    clock_t start, end;
    double time_spent;
    
    cout << "Bubble Sort" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < array_lengths[i]; j++) {
            num = rand() % 100;
            arrays[i][j] = num;
        }
        printf("Total elements in the array: %d\n", array_lengths[i]);
        start = clock();
        bubble_sort(arrays[i], array_lengths[i]);
        end = clock();
        time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken is %.6f s\n", time_spent);
    }
    return 0;
}