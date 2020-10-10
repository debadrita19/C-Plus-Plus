#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int idx = 0;
Node *create(vector<int> &arr)
{
    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return NULL;
    }

    Node *nnode = new Node(arr[idx], NULL, NULL);
    idx++;
    nnode->left = create(arr);
    nnode->right = create(arr);
    return nnode;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";

    str += node->left == nullptr ? "." : to_string(node->left->data);
    str += " -> " + to_string(node->data) + " <- ";
    str += node->right == nullptr ? "." : to_string(node->right->data);
    cout << str << endl;

    display(node->left);
    display(node->right);
}
