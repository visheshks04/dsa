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

    /**
     * isStrictlyBinaryTree
     * isCompleteBinaryTree
     * isExtendedBinaryTree
     */

    int depth(Node* root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(depth(root->left), depth(root->right));
    }

    int zeroChildCount(Node* root){
        if(root == NULL){
            return 0;
        }

        else if(root->left == NULL && root->right == NULL){
            return 1;
        }

        return zeroChildCount(root->left) + zeroChildCount(root->right);
    }


    bool isExtendedBinary(Node* root){

        if(root->left == NULL && root->right == NULL)
            return true;

        if(root->left == NULL || root->right == NULL)
            return false;

        return isExtendedBinary(root->left) && isExtendedBinary(root->right);
    }

    /**
     *      5 
     *    6   8
     *   7     9
     * 
     */

    // bool isCompleteBinary(Node* root){
        
    // }

    // bool isExtendedBinary(){
        
    // }

};



// class BST : public BinaryTree{

//     protected:

//     void createTree(Node** root, int key){

//         start:

//         int data;
//         cin>>data;

//         if(data == -1){
//             return;
//         }

//         else if()

//         (*root) = createNode(data);
//         cout<<"Enter data for left of "<<data<<": ";
//         createTree(&(*root) -> left);
//         cout<<"Enter data for right of "<<data<<": ";
//         createTree(&(*root) -> right);
//     }
// };



int main(){
    BinaryTree bt;
    cout<<bt.isExtendedBinary(bt.getRoot());
    return 0;
}