#include <bits/stdc++.h>

using namespace std;

class ListADT{

    private:
    int capacity;
    int* array;
    int length = 0;

    void resize(){
        capacity = capacity * 2;
        int* newArray = new int[capacity];
        for(int i=0; i<length; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    public:

    ListADT() : capacity(5), length(0){
        array = new int[capacity];
    }

    ~ListADT(){
        delete[] array;
    }

    void add(int item){
        if(length == capacity){
            resize();
        }
        array[length++] = item;
    }

    void addbegin(int item){
        if(length == capacity){
            resize();
        }
        for(int i=length; i>0; i--){
            array[i] = array[i-1];
        }
        array[0] = item;
        length++;
    }

    void addanypos(int pos, int item){
        if(pos<0 || pos>length){
            return;
        }
        if(length == capacity){
            resize();
        }
        for(int i=length; i>pos; i--){
            array[i] = array[i-1];
        }
        array[pos] = item;
        length++;
    }

    bool contains(int item){
        for(int i=0; i<length; i++){
            if(array[i] == item){
                return true;
            }
        }
        return false;
    }

    int size(){
        return length;
    }

    bool isEmpty(){
        if(length == 0){
            return true;
        }
        return false;
    }

    int get(int pos){
        if(pos>=0 && pos<length){
            return array[pos];
        }
        return -1;
    }

    int indexOf(int item){
        for(int i=0; i<length; i++){
            if(array[i] == item){
                return i;
            }
        }
        return -1;
    }

    void removefirst(){
        if(length == 0){
            cout<<"List is empty.";
            return;
        }
        for(int i=0; i<length; i++){
            array[i] = array[i+1];
        }
        length--;
    }

    void removelast(){
        if(length>0){
            length--;
        }
    }

    void remove(int pos){
        if(pos<0 || pos>=length){
            return;
        }
        for(int i=pos; i<length-1; i++){
            array[i] = array[i+1];
        }
        length--;
    }

    void reverse(){
        for(int i=0; i<length/2; i++){
            swap(array[i], array[length-i-1]);
        }
    }

    void sort(){
        for(int i=0; i<length; i++){
            for(int j=0; j<length-i-1; j++){
                if(array[j]>array[j+1]){
                    swap(array[j], array[j+1]);
                }
            }
        }
    }

    void display(){
        for(int i=0; i<length; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    ListADT la;
    la.add(10);
    la.add(20);

    la.addbegin(5);

    la.addanypos(2, 15);

    cout<<"List: ";
    la.display();
    cout<<"Size: "<<la.size()<<endl;
    cout<<"Contains 15: "<<la.contains(15)<<endl;
    cout<<"Contains 100: "<<la.contains(100)<<endl;
    cout<<"Index of 15: "<<la.indexOf(15)<<endl;
    la.removefirst();
    cout << "After removing first: ";
    la.display(); 
    la.removelast();
    cout << "After removing last: ";
    la.display(); 
    la.remove(1);
    cout << "After removing at position 1: ";
    la.display(); 
    la.add(30);
    la.add(50);
    cout<<"Before reversing: ";
    la.display();
    la.reverse();
    cout << "After reversing: ";
    la.display();
    la.add(5);
    la.add(3);
    la.sort();
    cout << "After sorting: ";
    la.display(); 
    return 0;
}