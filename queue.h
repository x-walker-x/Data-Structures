// To throw queue underflow error
#include<exception>

template<class T>
class Queue {
    private: 
        // Queue's node
        class Node {
            public: 
                T data;
                Node* next;
                Node() : data{}, next(nullptr){}
                Node(T x) : data(x), next(nullptr){} 
        };

        // Pointer to front of the queue
        Node *front;
        // Pointer to rear of the queue
        Node *rear;

    public: 
        Queue<T>() : front(nullptr), rear(nullptr){}
        
        bool isEmpty();         // checks if queue is empty
        void enqueue(T val);    // enqueue a node in queue
        void dequeue();         // dequeue a node in queue
        T getFront();           // return data of front node
};

// Function to check whether queue is empty or not
template<class T>
bool Queue<T>::isEmpty() {
    if (front == nullptr)
        return true;
    else 
        return false;
}

// Function to insert a node at rear of the queue
template<class T>
void Queue<T>::enqueue(T val) {
    Node* ptr = new Node(val);
    if (front == nullptr) {
        front = rear = ptr;
    }
    else {
        rear->next = ptr;
        rear = ptr;
    }
}

// Function to delete a node from front of the queue
template<class T>
void Queue<T>::dequeue() {
    if (front == nullptr) {
        throw std::underflow_error("Queue underflow!");
    }
    else {
        Node *ptr = front;
        front = front->next;
        delete ptr;
    }
}

// Function to return the data of the front node of the queue
template<class T>
T Queue<T>::getFront() {
    if (front == nullptr) {
        throw std::underflow_error("Queue underflow!");
    }
    else {
        return front->data;
    }
}