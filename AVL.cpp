#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height;

    Node(int v)
    {
        value = v;
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    int getHeight(Node *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    int getBalance(Node *n)
    {
        if (n == NULL)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
            return new Node(value);

        if (value < node->value)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            return node; // No duplicates allowed
        }

        // Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // Balance the tree
        if (balance > 1 && value < node->left->value)
        { // Left Left Case
            return rightRotate(node);
        }
        if (balance < -1 && value > node->right->value)
        { // Right Right Case
            return leftRotate(node);
        }
        if (balance > 1 && value > node->left->value)
        { // Left Right Case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->value)
        { // Right Left Case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node *remove(Node *root, int value)
    {
        if (root == NULL)
            return root;

        if (value < root->value)
        {
            root->left = remove(root->left, value);
        }
        else if (value > root->value)
        {
            root->right = remove(root->right, value);
        }
        else
        {
            if ((root->left == NULL) || (root->right == NULL))
            {
                Node *temp = root->left ? root->left : root->right;
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = remove(root->right, temp->value);
            }
        }

        if (root == NULL)
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->value << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void remove(int value)
    {
        root = remove(root, value);
    }
};

int main()
{
    AVL tree;
    char command;
    int value;

    while (cin >> command)
    {
        if (command == 'a')
        {
            cin >> value;
            tree.insert(value);
        }
        else if (command == 'd')
        {
            cin >> value;
            tree.remove(value);
        }
        else if (command == 'p')
        {
            tree.preOrder(tree.root);
            cout << endl;
        }
        else if (command == 'x')
        {
            break;
        }
    }

    return 0;
}
