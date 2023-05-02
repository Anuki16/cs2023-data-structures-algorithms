#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int arr[], int i, int j) {
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root + 1;
   int right = 2*root + 2;
   int maxi = root;
   
   if (left < n && arr[maxi] < arr[left]) {
      maxi = left;
   } if (right < n && arr[maxi] < arr[right]) {
      maxi = right;
   }
   if (maxi != root) {
      swap(arr, maxi, root);
      heapify(arr, n, maxi);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2; i >= 0; i--) {
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   
   while (n > 1) {
      swap(arr, 0, n-1);
      n -= 1;
      heapify(arr, n, 0);
   }
}
  
// main program
int main()
{
   int n = 12;
   int heap_arr[n];
   for (int i = 0; i < n; i++) {
      heap_arr[i] = rand()%41;
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}