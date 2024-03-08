#include <iostream>
#include <cstring>

using namespace std;

struct Book {
    char title[100];
    int pages; 
    Book* next; // Вказівник на наступну книгу у стеку
};

struct Stack {
    Book* top; // Вказівник на верхній елемент стеку
    int size; // Кількість книг у стеку

    // Конструктор для ініціалізації порожнього стеку
    Stack() {
        top = nullptr;
        size = 0;
    }

    ~Stack() {
        releaseStack();
    }

    // Функція для додавання нової книги до стеку
    void addItem(const char* title, int pages) {
        Book* newBook = new Book;
        strcpy_s(newBook->title, sizeof(newBook->title), title);
        newBook->pages = pages;
        newBook->next = top;
        top = newBook;
        size++ ;
    }

    void deleteItem() { // Видалення книги зі стеку
        if (isEmpty()) {
            cout << "Error: Stack is empty." << endl;
            return;
        }
        Book* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void viewStack() { // Перегляд стеку
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Book* curr = top;
        cout << "Number of books in the stack: " << size << endl;
        while (curr != nullptr) {
            cout << "Title: " << curr->title << ", Pages: " << curr->pages << endl;
            curr = curr->next;
        }
    }

    int getSize() { // Отримання кількості книг у стеку
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void releaseStack() { // Видалення всіх книг зі стеку
        Book* curr = top;
        while (curr != nullptr) {
            Book* temp = curr;
            curr = curr->next;
            delete temp;
        }
        top = nullptr;
        size = 0;
    }
};

int main() {
    Stack myStack;
    int choice;
    char title[100];
    int pages;

    do {
        cout << "1. Add book\n2. Delete book\n3. View stack\n4. Release stack\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // Кейси для вибору операції
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter number of pages: ";
            cin >> pages; ;
            myStack.addItem(title, pages) ;
            break;
        case 2:
            myStack.deleteItem();
            break;
        case 3:
            myStack.viewStack();
            break;
        case 4:
            myStack.releaseStack();
            cout << "Stack released." << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); 

    return 0;
}
