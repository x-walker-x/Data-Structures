/*

    SINGLY LINKED LIST 
            --- Language: C++

*/


#include <iostream>

template <class T>
class LinkedList 
{
    private:
        // Node of the linked list 
        class Node
        {
            public:
                T data;         // data of the current node
                Node *next;     // pointer to the next node

                Node(T val) : data(val), next(nullptr) {}
                Node() : data{}, next(nullptr) {}
        };

        // points to start of the linked list
        Node *head;

        // creates new node 
        Node* newNode(T);

    public:
        LinkedList() : head(nullptr) {}
        ~LinkedList();
        bool isEmpty();             // Returns true if list is empty, otherwise false
        void display();             // Traverses and prints the linked list
        void insertBeg(T);          // Inserts a node at the beginning of the linked list
        void insertEnd(T);          // Inserts a node at the end of the linked list
        void insertBefore(T, T);    // Inserts a node before the node with given data
        void insertAfter(T, T);     // Inserts a node after the node with given data
        bool search(T);             // Returns true if a node with given data is found  
        int totalNodes();           // Returns total number of node in the linked list 
        void deleteBeg();           // Delete a node from the beginning of the linked list 
        void deleteEnd();           // Delete a node from the emd of the linked list 
};

// creates and returns new node of the linked list
template<class T>
LinkedList<T>::Node* LinkedList<T>::newNode(T val)
{
    Node* ptr = new Node(val);
    
    if (ptr == nullptr)
    {
        cout << "Overflow!!!" << endl;
        exit(1)
    }

    return ptr;
}

// Returns true if linked list is empty - O(1)
template<class T>
bool LinkedList<T>::isEmpty() 
{
    if (head == nullptr)
        return true;
    else 
        return false;
}

// Traverse and print the linked list - O(n)
template<class T>
void LinkedList<T>::display()
{
    if (this->isEmpty())
    {
        cout << "List is empty!!!" << endl;
        return;
    }

    Node* ptr = head;
    
    while(ptr != nullptr) 
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Inserts the node at the beginning of the linked list - O(1)
template<class T>
void LinkedList<T>::insertBeg(T val)
{
    Node* ptr = newNode(val);
    ptr->next = head;
    head = ptr;
}

// Inserts the node at the end of the linked list - O(n)
template<class T>
void LinkedList<T>::insertEnd(T val) 
{
    Node* ptr = newNode(val);
    Node* curr = head;

    if (this->isEmpty) 
    {
        head = ptr;
        return;
    }

    while(curr->next != nullptr)
        curr = curr->next;
    
    curr->next = ptr;
}

// Inserts the node before the node with the given data - O(n)
template<class T>
void LinkedList<T>::insertBefore(T val, T data) 
{
    if (this->isEmpty() || head->data == data)
    {
        this->insertBeg(val);
        return;
    }

    Node* ptr = newNode(val);
    Node* curr = head;
    Node* prev = nullptr;
    
    while (curr != nullptr && curr->data != data) 
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) 
    {
        cout << "No node present with data equals " << data << "!!!" << endl;
        return;
    }

    prev->next = ptr;
    ptr->next = curr;
}

// Inserts the node after the node with given data - O(n)
template<class T>
void LinkedList<T>::insertAfter(T val, T data) 
{
    if (this->isEmpty() || head->data == data) 
    {
        this->insertEnd(val);
        return;
    }

    Node* ptr = newNode(val);
    Node* curr = head;

    while (curr != nullptr && curr->data != data) 
        curr = curr->next;

    if (curr == nullptr) 
    {
        cout << "No node present with data equals " << data << "!!!" << endl;
        return;
    }

    ptr->next = curr->next;
    curr->next = ptr;
}

// Returns true if a node with data equals val is found - O(n)
template<class T>
bool LinkedList<T>::search(T val) 
{
    if (this->isEmpty()) 
        return false;

    Node* curr = head;

    while(curr != nullptr) 
    {
        if (val == curr->data)
            return true;
        else 
            curr = curr->next;
    }

    return false;
}

// Returns the count of total number of nodes present - O(n)
template<class T>
int LinkedList<T>::totalNodes() 
{
    int count = 0;
    Node* curr = head;
    
    while (curr != nullptr) 
    {
        count++;
        curr = curr->next;
    }
    
    return count;
}

// Deletes a node from the beginning of the linked list - O(1)
template <class T>
void LinkedList<T>::deleteBeg() 
{
    if (this->isEmpty()) 
    {
        cout << "Underflow!!!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    
    delete temp;
}

// Deletes a node from the end of the linked list - O(n) 
template <class T>
void LinkedList<T>::deleteEnd() 
{
    if (this->isEmpty()) 
    {
        cout << "Underflow!!!" << endl;
        return;
    }

    if (head->next == nullptr) 
    {
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr->next != nullptr) 
    {
        prev = curr; 
        curr = curr->next;
    }

    prev->next = nullptr;
    delete curr;
}

// Destructor of the LinkedList class
template <class T>
LinkedList<T>::~LinkedList()
{
    Node *temp = nullptr;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
}