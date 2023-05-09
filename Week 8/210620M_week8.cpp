#include <iostream>
using namespace std;

int left(int a){
   return a*2+1;
}
int right(int a){
   return a*2+2;
}
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int l = left(root);
  int r = right(root);
  int largest;
  if(l<=n-1 && arr[l]>arr[root]){
      largest = l;
  }
  else{
      largest = root;
  }
  if (r<=n-1 && arr[r]>arr[largest]){
      largest = r;
  }
  if (largest != root){
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;
      heapify(arr,n,largest);
      
  }
}

void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

void buildHeap(int arr[], int n){
   int b = n/2;
   for (int i=b-1;i>=0;i--){
      heapify(arr,n,i);
   }
}  


// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int a = n;
   buildHeap(arr,n);
   // extracting elements from heap one by one
   for(int i=n-1;i>=1;i--){
      //displayArray(arr,a);
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      n = n-1;
      heapify(arr,n,0);
      //cout<<arr[0]<<endl;
   } 
}
/* print contents of array */


// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   cout<<"user input"<<endl;
   cout<<"enter the number of elements in the array:"<<endl;
   int N;
   int arr[N];
   cin>>N;
   for(int i=0;i<N;i++){
      cout<<"enter "<<i+1<<" entry: ";
      int x;
      cin>>x;
      arr[i]=x;
   }
   displayArray(arr,N);
   cout<<"Input array"<<endl;
   displayArray(arr,N);
  
   heapSort(arr, N);
  
   cout << "Sorted array"<<endl;
   displayArray(arr, N);

}
