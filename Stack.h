// for handling undeflow error
#include<exception>

template<class T>
class Stack {
    private: 
        // Stack's node
        class Node {
            public: 
                T data;
                Node* next;  
                Node() : data{}, next(nullptr){}
                Node(T x) : data(x), next(nullptr){} 
        };

        // pointer to top node of the stack
        Node * top;

    public: 
        Stack<T>() : top(nullptr){}
        
        ~Stack<T>() {
            while(top != nullptr) {
                Node *ptr = top;
                top = top->next;
                delete ptr;
            }
        }
        
        bool isEmpty();     // check if stack if empty
        void push(T);       // insert node into the stack 
        void pop();         // delete node from the stack
        T getTop();         // returns the data of top node of the stack
};


// Function to check if stack if empty
template<class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr)
        return true;
    else 
        return false;
}

// Function to push a node in the stack
template<class T>
void Stack<T>::push(T val) {
    Node* ptr = new Node(val);

    if (this->isEmpty()) {
        top = ptr;
        return;
    }

    ptr->next = top;
    top = ptr;
}

// Function to pop a node from the stack
template<class T>
void Stack<T>::pop() {
    if (this->isEmpty())
        throw std::underflow_error("Stack underflow!");

    Node* ptr = top;
    top = top->next;
    delete(ptr);
}

// Function to return the data of top node of the stack
template<class T>
T Stack<T>::getTop() {
    if (this->isEmpty())
        throw std::underflow_error("Stack underflow!");

    return top->data;
}
