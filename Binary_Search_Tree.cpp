/*

 BINARY SEARCH TREE 
    using C++

Templates and Generic Programming are used.

*/

#include <iostream>
#include <queue>

template<class T>
class BST {     
    private:
           class Node {         // Node of the Binary Search Tree
            public:
                T data;
                Node* left;
                Node* right;
                Node() : data{}, left(nullptr), right(nullptr){}
                Node(T x, Node* l, Node* r) : data(x), left(l), right(r){}
                Node(T x) : data(x), left(nullptr), right(nullptr){}
        };
    
        Node* tree;     

        bool search(Node*, T);
        bool update(Node*, T, T);
        Node* insert(Node*, T);
        Node* remove(Node*, T);
        int height(Node*);
        int totalNodes(Node*);
        int totalInternalNodes(Node*);
        int totalExternalNodes(Node*);
        T minimum(Node*);
        T maximum(Node*);
        void inorder(Node*);
        void postorder(Node*);
        void preorder(Node*);
        void levelorder(Node*);

    public:
        BST<T>() : tree(nullptr){}
        ~BST<T>(){ delete tree; }
        
        bool search(T target) {         // search a node and return true if found otherwise false
            return search(tree, target);
        } 

        bool update(T oldVal, T newVal) {           // update the value of a node
            return update(tree, oldVal, newVal);
        }

        void insert(T val) {            // insert a node
            tree = insert(tree, val);
        }

        void remove(T val) {        // delete a node
            tree = remove(tree, val);
        }         

        int height() {          // find height 
            return height(tree);
        }       

        int totalNodes() {      // count total number of nodes
            return totalNodes(tree);
        }

        int totalInternalNodes() {          // count total number of internal nodes
            return totalInternalNodes(tree);
        }

        int totalExternalNodes() {          // count total number of external nodes
            return totalExternalNodes(tree);
        }

        T minimum() {           // find minimum
            if (tree == nullptr) {
                return {};
            }
            return minimum(tree);
        }

        T maximum() {       // find maximum
            if (tree == nullptr) {
                return {};
            }
            return maximum(tree);
        }

        void inorder() {        // print inorder traversal
            inorder(tree);
        }

        void postorder(){       // print postorder traversal
            postorder(tree);
        }

        void preorder(){        // print preorder traversal
            preorder(tree);
        }

        void levelorder(){      // print levelorder traversal
            levelorder(tree);
        }
};

template<class T>
bool BST<T>::search(Node* root, T target) {
    if (root == nullptr) {
        return false;
    } else if (root->data == target) {
        return true;
    } else if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

template<class T>
bool BST<T>::update(Node* root, T oldVal, T newVal) {
    if (root == nullptr) {
        return false;
    } else if (root->data == oldVal) {
        root->data = newVal;
        return true;
    } else if (oldVal < root->data) {
        return update(root->left, oldVal, newVal);
    } else {
        return update(root->right, oldVal, newVal);
    }
}

template<class T>
typename BST<T>::Node* BST<T>::insert(Node* root, T val) {
    if (root == nullptr) {
        root = new Node(val);
    }
    else if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

template<class T>
typename BST<T>::Node* BST<T>::remove(Node* root, T val){
    if (root == nullptr) {
        return root;
    } else if (val < root->data) {
        root->left = remove(root->left, val);
        return root;
    } else if (val >= root->data) {
        root->right = remove(root->right, val);
        return root;
    } else {
        if (root->left == nullptr) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        } else if (root->right == nullptr) {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        } else {
            Node* parentSucc = root;
            Node* succ = root->right;    // replacing with inorder successor
            while (succ->left != nullptr) {
                parentSucc = succ;
                succ = succ->left;
            }
            if (parentSucc != root) {
                parentSucc->left = succ->right;
            } else {
                parentSucc->right = succ->right;
            }
            root->data = succ->data;
            delete succ;
            return root;
        }
    }
}

template<class T>
int BST<T>::height(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return max(height(root->left), height(root->right)) + 1;
    }
}

template<class T>
int BST<T>::totalNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
}

template<class T>
int BST<T>::totalInternalNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 0;
    } else {
        return totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1;
    }
}

template<class T>
int BST<T>::totalExternalNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        return totalExternalNodes(root->left) + totalExternalNodes(root->right);
    }
}

template<class T>
T BST<T>::minimum(Node* root) {
    if (root->left == nullptr) {
        return root->data;
    } else {
        minimum(root->left);
    }
}

template<class T>
T BST<T>::maximum(Node* root) {
    if (root->right == nullptr) {
        return root->data;
    } else {
        maximum(root->right);
    }
} 

template<class T>
void BST<T>::inorder(Node *root) {
    if (root == nullptr) 
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

template<class T>
void BST<T>::postorder(Node *root) {
     if (root == nullptr) 
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

template<class T>
void BST<T>::preorder(Node *root) {
     if (root == nullptr) 
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

template<class T>
void BST<T>::levelorder(Node *root) {
    if (root == nullptr)
        return;
    std::queue<T> que;
    que.push(root);
    while (!que.empty()) {
        Node* curr = que.front();
        que.pop();
        std::cout << curr->data << " ";
        if (curr->left != nullptr)
            que.push(curr->left);
        if (curr->right != nullptr)
            que.push(curr->right);
    }
}
