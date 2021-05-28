/*

 AVL TREE
      - Implemented in C++

 References 
      - Data Structures in C - Reema Theraja
      - GeeksforGeeks
      - Programiz
             
*/

#include <iostream>

class Node
{
    public:
        int data;
        int height;
        Node *left;
        Node *right;

        Node() : data(0), height(1), left(nullptr), right(nullptr) {}
        Node(int x) : data(x), height(1), left(nullptr), right(nullptr) {}
};

class AVL
{
    private:
        Node *tree;
        int max(int a, int b) { return (a > b) ? a : b; }
        int getHeight(Node *);
        int getBalance(Node *);
        Node *rightRotate(Node *);
        Node *leftRotate(Node *);
        Node *insert(Node *, int);
        Node *delNode(Node *, int);
        void inorder(Node *);
        void postorder(Node *);
        void preorder(Node *);

    public:
        AVL() : tree(nullptr){};

        void insert(int key)
        {
            tree = insert(tree, key);
        }

        void delNode(int key)
        {
            tree = delNode(tree, key);
        }

        void inorder()
        {
            inorder(tree);
        }

        void postorder()
        {
            postorder(tree);
        }

        void preorder()
        {
            preorder(tree);
        }
};

int AVL::getHeight(Node *curr)
{
    if (curr == nullptr)
        return 0;
    return curr->height;
}

int AVL::getBalance(Node *curr)
{
    if (curr == nullptr)
        return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

Node *AVL::leftRotate(Node *y)
{
    /*
           x
         /   \
        y     a
       / \ 
      d   z
         / \ 
        b   c

    */

    Node *z = y->right;
    Node *b = z->left;
    // Perform Rotation
    z->left = y;
    y->right = b;
    // update height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    return z;
}

Node *AVL::rightRotate(Node *y)
{
    /*
           x
         /   \
        a     y
             / \ 
            z   d
           / \ 
          b   c

    */

    Node *z = y->left;
    Node *c = z->right;
    // Perform Rotation
    z->right = y;
    y->left = c;
    // update height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    return z;
}

Node *AVL::insert(Node *root, int key)
{
    if (root == nullptr)
    {
        root = new Node(key);
        return root;
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else    // equal data are not allowed
    {
        return root;
    }
    //update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalance(root);
    // Left Left Case
    if (balanceFactor > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }
    // Right Right Case
    else if (balanceFactor < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }
    // Left Right Case
    else if (balanceFactor > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    else if (balanceFactor < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // If node is balanced, then return
    return root;
}

Node *AVL::delNode(Node *root, int key)
{   
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            Node *temp = root;
            root = (root->left) ? root->left : root->right;
            free(temp);
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;
            root->data = temp->data;
            root->right = delNode(root->right, temp->data);
        }
    }
    if (root == nullptr)
        return root;
    // update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balanceFactor = getBalance(root);
    // Left Left Case
    if (balanceFactor > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    // Right Right Case
    else if (balanceFactor < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    // Left Right Case
    else if (balanceFactor > 1 && getBalance(root) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    else if (balanceFactor < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // If root is already balanced
    return root;
}

void AVL::inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void AVL::postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void AVL::preorder(Node *root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
