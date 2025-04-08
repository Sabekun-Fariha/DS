#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int price;
};

Book findMaxPricedBook(Book books[], int size) {
    Book maxBook = books[0]; 
    for (int i = 1; i < size; i++) {
        if (books[i].price > maxBook.price) {
            maxBook = books[i];
        }
    }
    return maxBook;
}

int main() {
    int n;
    cin >> n; 
    Book books[n];

    for (int i = 0; i < n; i++) {
        cin >> books[i].title >> books[i].author >> books[i].price;
    }
    
    Book maxBook = findMaxPricedBook(books, n);
    
    cout << maxBook.title << " " << maxBook.author << " " << maxBook.price << endl;
    
    return 0;
}
