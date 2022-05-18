#include <iostream>
  using namespace std;
  class Heap{
 public:
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
   
      heapify(arr, n, largest);
    }
   
  }
  
  // main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
           cout<<"Swapping Elements";
      for(int i=0;i<n;i++){
          cout<<" "<<arr[i];
      }
      cout<<endl;
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    
    }
  }
  
  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }
  };
  // Driver code
  int main() {
    Heap h;
    int size;
    cout<<"Enter No Of Vertex ";
    cin>>size;
     int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter "<<i<<"th Vertex";
        cin>>arr[i];
    }
   
    
   
    h.heapSort(arr, size);
  
    cout << "Sorted array is \n";
    h.printArray(arr, size);
  }




