#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class implementing linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack
    int size;   // To keep track of the stack size
    
public:
    Stack() {
        top = nullptr;
        size = 0;
    }
    
    // Push operation: Add an element to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    // Pop operation: Remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return -1;  // Return a sentinel value or throw an exception
        }
        
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }
    
    // Peek operation: Return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;  // Return a sentinel value or throw an exception
        }
        return top->data;
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    
    // Get the size of the stack
    int getSize() {
        return size;
    }
    
    // Display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        
        Node* current = top;
        cout << "Stack (top to bottom): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.display();  // Output: 30 20 10
    
    cout << "Top element: " << stack.peek() << endl;  // Output: 30
    cout << "Stack size: " << stack.getSize() << endl;  // Output: 3
    
    cout << "Popped: " << stack.pop() << endl;  // Output: 30
    cout << "Popped: " << stack.pop() << endl;  // Output: 20
    
    stack.display();  // Output: 10
    
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;  // Output: No
    
    stack.pop();
    cout << "Is stack empty now? " << (stack.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes
    
    return 0;
}