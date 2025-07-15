#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest=i;
    int l=(i<<1)+1;
    int r=(i<<1)+2;

    if(l<n&&arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n&&arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }   
}

int main(){
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    heapSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
        }
    return 0;
}