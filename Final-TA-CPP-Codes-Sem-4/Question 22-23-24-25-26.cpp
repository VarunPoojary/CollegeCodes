// 1.	Create Binary Search tree for 12 nodes and display mirror image of the same.
// 2.	Create Binary Search tree and find the height of it.
// 3.	Create Binary Search tree and get the depth of it.
// 4.	Create Binary Search tree and display the level of tree. *
// 5.	Create Binary Search tree and display level wise nodes.
// 6.	Create Binary Search tree and count the number of leaf node.
// 7.	Create Binary Search tree and count the number of nodes with only one child.



#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

Node* insertion(Node* root, int item)  
{  
    if (root == NULL)  
        return create(item);
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  

    return root;  
}  


// Mirror Of An Image
void mirror(Node* node)
{
    if (node == NULL)
        return;
    else
    {
         Node* temp;
         
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
     
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

//Height of Binary Search Tree (Height-Traversing to the deepest possible leaf.)
int BSTHeight(Node* root)
{
    if(root == NULL)
    return 0;

    int leftHeight = BSTHeight(root->left);
    int rightHeight = BSTHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Minimum Depth of Binary Search Tree
int minDepth(Node *root)
{
if (root == NULL)
return 0;
if (root->left == NULL && root->right == NULL)
return 1;
int l = INT_MAX, r = INT_MAX;
if (root->left)
l = minDepth(root->left);
if (root->right)
r = minDepth(root->right);
return min(l , r) + 1;
}


//Level Order Traversal
void printLevelOrder(Node* root)
{
    if (root == NULL) 
    return;
    queue<Node*> q;
    q.push(root);

    while (q.empty() == false)
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}



// Number of Leaf Nodes
int getLeafCount(Node* node)
{
    if(node == NULL)    
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;        
    else
        return getLeafCount(node->left)+ getLeafCount(node->right);
}



// Number of Nodes with 1 child
int getLeafCount(Node* node)
{
    if(node == NULL)    
        return 0;
    if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
        return 1;        
    else
        return getLeafCount(node->left)+ getLeafCount(node->right);
}




int main()
{
    Node* root = NULL;
    root = insertion(root, 45);  
    root = insertion(root, 30);  
    root = insertion(root, 50);  
    root = insertion(root, 25);  
    root = insertion(root, 35);  
    root = insertion(root, 45);  
    root = insertion(root, 60);  
    root = insertion(root, 4);  
    root = insertion(root, 5);  
    root = insertion(root, 3);  
    root = insertion(root, 40);  
    root = insertion(root, 52);  
    return 0;
}
