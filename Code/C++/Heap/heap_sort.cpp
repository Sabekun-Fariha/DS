#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(vector<int> &heap, int size, int i){
    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if(leftChild < size && heap[leftChild] > heap[largest])
    {
        largest = leftChild;
    }
    if(rightChild<size && heap[rightChild] > heap[largest]){
        largest = rightChild;
    }
    if(largest != i){
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(vector<int> &heap, int size){ // void builMaxHeap(int heap[], int size)
    for(int i = (size/2)-1; i>=0; i--){
        maxHeapify(heap, size, i);
    }
}

void printHeap(vector<int> &heap){
    for(int i: heap){
        cout << i << " ";
    }
    cout<<endl;
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
    cout<<heap[index]<<" ";
    heap[index] = heap.back();
    heap.pop_back();
    size--;
    buildMaxHeap(heap, size);
}


void heapSort(vector<int>&heap, int size){
    buildMaxHeap(heap, size);
    for(int i:heap){
        deleteNode(heap, i);
    }
}

int main()
{

    vector<int> heap = {3, 9, 2, 1, 4, 5};
    int size = heap.size();

    cout << "Original Array:" << endl;
    printHeap(heap);
    

    heapSort(heap, size);

    

    return 0;

}
