#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int info)
    {
        data = info;
        left = NULL;
        right = NULL;
    }
};
// to make a binary search tree we will use recursion
void insert(node *&root, int data)
{
    if (root == NULL)
    {
        node *n = new node(data);
        root = n;
        return;
    }
    node *temp = root;
    if (temp->data > data)
        insert(temp->left, data);
    if (temp->data < data)
        insert(temp->right, data);
        return;
}
bool search(node* root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (root->data < key)
        search(root->right, key);
    else if (root->data > key)
        search(root->left, key);
    else
        return false;
}
// depth first search
void printDFS(node *root) 
{
    if (root == NULL)
        return;
    // preorder traversal
    cout << root->data << " ";
    printDFS(root->left);
    printDFS(root->right);
    // we can make this inorder or postorder traversal just based on the sequence of the above 3 lines
    //  Fun fact: inoder gives us the BST in a sorted fashion
}
// breadth first search
void printLevelOrder(node *root)
{ 
    queue<node *> q;
    if (root == NULL)
        cout << "-1";
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        cout << current->data << " ";
        q.pop();
    }
}
//Min value in the BST
int findMin(node *root)
{ // we can also do this through recursion
    // int min = root->data;
    while (root->left != NULL)
    {
        root = root->left;
        // if (root->data < min)
        //     min = root->data;
    }
    return root->data;
}
//Max value in the BST
int findMax(node *root)
{ // we can also do this through recursion
    int max = root->data;
    while (root->right != NULL)
    {
        root = root->right;
        // if (root->data > max)
        //     max = root->data;
    }
    return root->data;
}
int heightBST(node *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = heightBST(root->left);
    int rightHeight = heightBST(root->right);
    return max(leftHeight, rightHeight) + 1;
}
// To check if the given Binary Tree is an BST
// we will make three functions for this, we will use recursion for this algo
bool isSubTreeLesser(node *compare, int value) //(root->left,root->data)
{
    if (compare == NULL)
        return true;
    if (compare->data <= value)
        return true;
    else
        return false;
}
bool isSubTreeGreater(node *compare, int value) //(root->right,root->data)
{
    if (compare == NULL)
        return true;
    if (compare->data >= value)
        return true;
    else
        return false;
}
int checkBST(node *root)
{
    // base case
    if (root == NULL)
        return true;
    // recursive calls
    if (isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && checkBST(root->left) 
    && checkBST(root->right))
        return true;
    else
        return false;
}
int main()
{
    node *root = NULL;
    insert(root, 1);
    insert(root, 2);
    insert(root, 6);
    insert(root, 5);
    insert(root, 9);
    insert(root, 3);
    insert(root, 4);
    insert(root, 15);
    bool ans = search(root, 15);
    cout << "Number you searched for is present in the tree : ";
    (ans == 1) ? cout << "true" : cout << "false";
    cout << endl;
    cout << "Your BST \n";
    printDFS(root);
    cout << endl;
    int min = findMin(root);
    cout << "The minimum number in BST is " << min << endl;
    int max = findMax(root);
    cout << "The maximum number in BST is " << max << endl;
    int height = heightBST(root);
    cout << height << endl;
    printLevelOrder(root);
    bool result = checkBST(root);
    cout << endl
         << result;
    return 0;
}