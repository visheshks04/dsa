#include <iostream>

using namespace std;

class BinaryTree{

    struct Node{
        int data;
        Node* left;
        Node* right;
    }*root;

    protected:

    Node* createNode(int data){
        Node *newNode = new Node;
        if(newNode == NULL){
            cout<<"Overflow!\n";
            return NULL;
        }
        newNode -> data = data;
        return newNode;
    }

    void createTree(Node** root){
        int data;
        cin>>data;

        if(data == -1){
            return;
        }

        (*root) = createNode(data);
        cout<<"Enter data for left of "<<data<<": ";
        createTree(&(*root) -> left);
        cout<<"Enter data for right of "<<data<<": ";
        createTree(&(*root) -> right);
    }

    public:

    BinaryTree(){
        cout<<"Enter data for the root: ";
        root = NULL;
        createTree(&root);
    }

    Node* getRoot(){
        return root;
    }

    void inorderTraversal(Node* root){
        if(root == NULL){
            return;
        }

        inorderTraversal(root -> left);
        cout<<root->data<<" ";
        inorderTraversal(root -> right);
    }

    void preorderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        cout<<root -> data<<" ";
        preorderTraversal(root -> left);
        preorderTraversal(root -> right);
    }

    void postorderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        cout<<root -> data<<" ";
    }
};



class BST{

};



int main(){
    BinaryTree bt;
    bt.inorderTraversal(bt.getRoot());
    return 0;
}