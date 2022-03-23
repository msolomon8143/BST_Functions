/********************************************
 * Name: Michael Solomon
 * File: Assignment 4 - Binary Search Trees
 * Class: COP4415.01
 * Date: 3/21/22
 * *******************************************/
/********************************************
* Test Case
* 1 Insert - 90 5 16 2 27 38
* 2 Inorder traversal - 2 5 16 27 38 90
* 3 Number of Nodes: 6
* 4 Find 3rd smallest - 16
* *******************************************/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, Node* element);
void inorder(Node* root);
int numNodes(Node* root);
int findKthSmallest(Node* root, int k);
int menu();

//Gets a node and the root of the Binary search tree
//Insert the node into the BST
//Return the root after insertion
Node* insert(Node* root,Node* element) {
    if (root == NULL){ // Inserting into an empty tree.
        return element;
    }else {
        if (element->data > root->data) { // element should be inserted to the right.
            if (root->right != NULL)// There is a right subtree to insert the node.
                root->right = insert(root->right, element);
            else// Place the node directly to the right of root.
                root->right = element;
        }else { // element should be inserted to the left.
            if (root->left != NULL) // There is a left subtree to insert the node.
                root->left = insert(root->left, element);// Place the node directly to the left of root.
            else
                root->left = element;
        }return root;// Return the root pointer of the updated tree.
    }
}
//Prints the inorder traversal of the tree pointed to by root
void inorder(Node* root) {
    if (root != NULL) { // Only traverse the node if it's not null.
        inorder(root->left); // Go Left.
        cout<<" "<<root->data; // Print the root.
        inorder(root->right); // Go Right.
    }
}
// Returns the number of nodes in the tree pointed to by root.
int numNodes(Node* root) {
    int count = 1;
    if (root == NULL){ //if root has nothing in it return nothing
        return 0;
    }
    if (root->left != NULL){ //if left has something add count numnodes implemented recursively
        count += numNodes(root->left);
    }
    if (root->right != NULL){//if right has something add count numnodes implemented recursively
        count += numNodes(root->right);
    }
    return count;
}
// Returns the kth smallest value in the BST pointed to by root
// Guaranteed that k is in between 1 and the number of nodes in the tree
// pointed to by root.
int findKthSmallest(Node* root, int k) {
    int count = 0;
    if (root == NULL || count >= k ) {//if root is null return nothing
        return 0;
    }
    if (findKthSmallest(root->left, k) != NULL)//if left isn't empty
        return findKthSmallest(root->left, k); //return left
    k--; //decrement ranked item number
    if (k == 0){ //if ranked item = 0
        return root->data; //return root
    }
    return findKthSmallest(root->right, k);//search right
}
// Prints out the menu of choices for the user and returns their choice.
int menu() {
    int ans;
    cout<<"Here are your choices.\n";
    cout<<"1. Insert an item into your tree.\n";
    cout<<"2. Print out an inorder traversal.\n";
    cout<<"3. Print the number of the nodes. \n";
    cout<<"4. Finding kth smallest element.\n";
    cout<<"5. Exit.\n";
    cin>> ans;
    return ans;
}
int main() {
    /* Test Case
     * 2 5 16 27 38 90
     */
    Node *myRoot=NULL;
    Node* tempNode;
    int nNodes;
    int val;
    int ans;
    int rank;
    char m;

    ans = menu();
    while (ans<5) {
        if (ans == 1) {
            // Get value to insert.
            cout<<"What value would you like to insert?";
            cin>>val;
            tempNode = new Node(val); // Create the node.
            // Insert the value.
            myRoot = insert(myRoot, tempNode);
        }
        if (ans == 2) {

            // Print the values in tree.
            cout<<"Here is an inorder traversal of your tree: ";
            inorder(myRoot);
            cout<<"\n";
        }
        if (ans == 3) {
            nNodes = numNodes(myRoot);
            cout<<nNodes;
            cout<<"\n";

        }
        if (ans == 4) {
            cout<<"Which ranked item would you like to find?\n";
            cin>>rank;

            cout<<"The item is:"<< findKthSmallest(myRoot, rank);
            cout<<"\n";
            cout<<"Which ranked item would you like to find?\n";
        }
        // See if they want to insert more nodes.
        ans = menu();
    }
    return 0;
}