#include <iostream>

using namespace std;

class BinaryTree{

    protected:
    struct Node{
        int data;
        Node* left;
        Node* right;
    }*root;


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

    // BinaryTree(){
    //     cout<<"Enter data for the root: ";
    //     root = NULL;
    //     createTree(&root);
    // }

    Node* getRoot(){
        return root;
    }

    static void inorderTraversal(Node* root){
        if(root == NULL){
            return;
        }

        inorderTraversal(root -> left);
        cout<<root->data<<" ";
        inorderTraversal(root -> right);
    }

    static void preorderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        cout<<root -> data<<" ";
        preorderTraversal(root -> left);
        preorderTraversal(root -> right);
    }

    static void postorderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        cout<<root -> data<<" ";
    }

    /**
     * isStrictlyBinaryTree
     * isCompleteBinaryTree
     * isExtendedBinaryTree
     */

    static int depth(Node* root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(depth(root->left), depth(root->right));
    }

    static int zeroChildCount(Node* root){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            return 1;
        }

        return zeroChildCount(root->left) + zeroChildCount(root->right);
    }


    static bool isFullBinary(Node* root){

        if(root->left == NULL && root->right == NULL)
            return true;

        if(root->left == NULL || root->right == NULL)
            return false;

        return isFullBinary(root->left) && isFullBinary(root->right);
    }

    /**
     *      5 
     *    6   8
     *   7     9
     */

    // bool isCompleteBinary(Node* root){
        
    // }

    // bool isExtendedBinary(){
        
    // }

};



class BST{

    public:

    struct Node{
        int data;
        Node* left;
        Node* right;
    }*root;

    Node* createNode(int data){
        Node *newNode = new Node;
        if(newNode == NULL){
            cout<<"Overflow!\n";
            return NULL;
        }
        newNode -> data = data;
        return newNode;
    }

    BST(){
        root = NULL;
    }

    BST(int rootItem){
        root = createNode(rootItem);
    }

    void _insertNode(Node** root, int item){

        if(*root == NULL){
            *root = createNode(item);
        }

        else if((*root)->data >= item){
            _insertNode(&(*root)->left, item);
        }

        else{
            _insertNode(&(*root)->right, item);
        }
    }

    void insertNode(Node* root, int item){
        _insertNode(&root, item);
    }

    Node* getRoot(){
        return root;
    }

    static void inorderTraversal(Node* root){
        if(root == NULL){
            return;
        }

        inorderTraversal(root -> left);
        cout<<root->data<<" ";
        inorderTraversal(root -> right);
    }

};



int main(){
    BST bst;
    bst.insertNode(bst.getRoot(), 5);
    bst.insertNode(bst.getRoot(), 6);
    bst.insertNode(bst.getRoot(), 4);
    bst.inorderTraversal(bst.getRoot());
    return 0;
}