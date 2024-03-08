#include <iostream>
#include <vector>

// Структура вузлів для зв'язаного списку (стеку)
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

// Структура стеку
struct Stack {
    Node* top;

    Stack() : top(nullptr) {}

    ~Stack() {
        Node* current = top;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Push новий вузол у стек
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Витягнути та повернути верхню вершину зі стеку
    int pop() {
        if (top == nullptr) {
            return -1; // Повернути сторожове значення для порожнього стека
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Перевірка чи стек є пустий
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    int n, k;
    std::cout << "Enter the number of items: ";
    std::cin >> n;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::vector<int> arr(n);
    std::cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    Stack stack;
    std::vector<int> result;

    for (int i = 0; i < n; i++) {
        if (i % k == 0) {
            // Push наступний елемент K у стек
            for (int j = 0; j < k && i + j < n; j++) {
                stack.push(arr[i + j]);
            }

            // Витягнути елементи зі стека та додати їх до результату
            while (!stack.isEmpty()) {
                result.push_back(stack.pop());
            }
        }
    }

    std::cout << "Output: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}