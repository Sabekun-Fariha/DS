#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(vector<int> &heap, int size, int i){
    int smallest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if(leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if(rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}


void buildMinHeap(vector<int> &heap, int size){
    for(int i = (size/2)-1; i >= 0; i--){
        minHeapify(heap, size, i);
    }
}

void printHeap(vector<int> &heap){
    for(int i: heap){
        cout << i << " ";
    }
    cout<<endl;
}

void insertNode(vector<int> &heap, int value){
    heap.push_back(value);             // Add at the end
    int index = heap.size() - 1;

    // Heapify upward
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent] > heap[index]){
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void deleteNode(vector<int> &heap, int value){
    int size = heap.size();
    int index = -1;

    // Find the index of the node to delete
    for(int i = 0; i < size; i++){
        if(heap[i] == value){
            index = i;
            break;
        }
    }

    if(index == -1){
        cout << "Value not found in heap." << endl;
        return;
    }

    // Replace with last element and remove last
    heap[index] = heap.back();
    heap.pop_back();
    size--;

    buildMinHeap(heap, size);

}

vector<int> heapSortIncreasing(vector<int> arr){
    int size = arr.size();
    buildMinHeap(arr, size);
    vector<int> sorted;

    for(int i = 0; i < size; i++){
        sorted.push_back(arr[0]);
        arr[0] = arr.back();
        arr.pop_back();
        minHeapify(arr, arr.size(), 0);
    }

    return sorted;
}



int main()
{
    vector<int> heap = {3, 9, 2, 1, 4, 5};
    int size = heap.size();

    cout << "Original Array:" << endl;
    printHeap(heap);

    buildMinHeap(heap, size);

    cout << "Min Heap after build:" << endl;
    printHeap(heap);

    // Insert a new node
    int newValue = 0;
    cout << "\nInserting value: " << newValue << endl;
    insertNode(heap, newValue);
    printHeap(heap);

    /*
    // User Input
    cout<<"Enter a number: ";
    int num;
    cin>>num;
    insertNode(heap, num);
    */

    // Delete a node
    int deleteValue = 0;
    cout << "\nDeleting value: " << deleteValue << endl;
    deleteNode(heap, deleteValue);
    printHeap(heap);


    vector<int> arr = {5, 3, 8, 1, 2, 9};

    cout << "Before Sorting: ";
    for(int i : arr) cout << i << " ";
    cout << endl;

    vector<int> incSorted = heapSortIncreasing(arr);
    cout << "Increasing Order: ";
    for(int i : incSorted) cout << i << " ";
    cout << endl;


    return 0;

}

