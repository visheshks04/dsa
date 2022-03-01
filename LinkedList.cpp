#include <iostream>
#include <climits>

using std::cout;
using std::cin;
using std::endl;

class SinglyLinkedList{

    struct Node{
        int data;
        Node* next;
    }*head;

    public:

    void insertFromHead(int item){

        if (head == NULL){ // Empty case
            head = new Node;
            if (head == NULL){ // Overflow check
                cout<<"Overflow!\n";
                return;
            }
            head->data = item;
            head->next = NULL;
            return;
        }

        Node *temp = new Node;
        if(temp == NULL){ // Overflow check
            cout<<"Overflow!\n";
            return;
        }

        temp->data = item;
        temp->next = head;
        head = temp;
    }

    void insertFromTail(int item){

        if (head == NULL){ // Empty case
            head = new Node;
            if (head == NULL){ // Overflow check
                cout<<"Overflow!\n";
                return;
            }
            head->data = item;
            head->next = NULL;
            return;
        }

        Node *temp = new Node;
        if(temp == NULL){ // Overflow check
            cout<<"Overflow!\n";
            return;
        }

        Node *tail = head;

        while(tail->next != NULL){
            tail = tail->next;
        }

        tail->next = temp;
        temp->data = item;
        temp->next = NULL;
    }

    void insertAtIndex(int item, int index){ //Not working for 

        if(head == NULL){ //Not working
            head = new Node;
            if(head == NULL){
                cout<<"Overflow!\n";
                return;
            }
            head->data = item;
            return;
        }

        if(index == 0){
            Node *temp = new Node;
            if(temp == NULL){
                cout<<"Overflow\n";
                return;
            }
            temp->data = item;
            temp->next = head;
            head = temp;
            return;
        }        

        int i=1;
        Node *temp = head;
        while(i!=index){
            temp = temp->next;
            i++;
        }

        Node *create = new Node;
        if(create == NULL){
            cout<<"Overflow!\n";
            return;
        }
        create->data = item;
        create->next = temp->next;
        temp->next = create;
    }

    void deleteFromHead(){

        if(head == NULL){ // Underflow check
            cout<<"Underflow!\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromTail(){

        if(head == NULL){ // Underflow check
            cout<<"Underflow!\n";
            return;
        }

        if(head->next == NULL){ // special case
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtIndex(int index){ // Not working

        if (head == NULL){
            cout<<"Underflow!\n";
            return;
        }

        if(index == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int i=1;
        Node *temp = head;
        while(i!=index){
            temp = temp->next;
            i++;
        }

        Node *del = temp->next;
        temp = temp->next;
        delete del;
    }
    
    void traverse(){

        if(head == NULL){
            cout<<"Empty List.\n";
            return;
        }

        Node *temp = head;

        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL\n";
    }

    void reverse(){


    }

    int min(){

        if(head == NULL){
            cout<<"Empty List.";
            return INT_MAX;
        }

        Node *temp = head;
        int min = INT_MAX;

        while(temp != NULL){
            if(min > temp->data){
                min = temp->data;
            }

            temp = temp->next;
        }

        return min;
    }

    int countAllOccurancesOf(int x){

        int count = 0;
        Node *temp = head;

        while(temp != NULL){
            if(temp->data = x)
                count++;
        }

        return count;
    }

    int max(){

        if(head == NULL){
            cout<<"Empty List.";
            return INT_MIN;
        }

        Node *temp = head;
        int max = INT_MIN;

        while(temp != NULL){
            if(max < temp->data){
                max = temp->data;
            }
            temp = temp->next;
        }

        return max;
    }

    ~SinglyLinkedList(){
        Node *temp = head;

        while(temp->next = NULL){
            Node *del = temp;
            temp = temp->next;
            delete del;
        }

        cout<<"Bye!\n";
    }

    void interface(){
        int choice=0, item, index;

        while(choice != -1){
            cout<<"1) Insert from Head\n";
            cout<<"2) Insert from Tail\n";
            cout<<"3) Insert at an Index\n";
            cout<<"4) Delete from Head\n";
            cout<<"5) Delete from Tail\n";
            cout<<"6) Delete at an Index\n";
            cout<<"7) Traverse the list\n";
            cout<<"8) Reverse\n";
            cout<<"-1) Exit\n";
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                        cout<<"Enter a number to insert: ";
                        cin>>item;
                        insertFromHead(item);
                        break;

                case 2:
                        cout<<"Enter a number to insert: ";
                        cin>>item;
                        insertFromTail(item);
                        break;

                case 3:
                        cout<<"Enter a number to insert: ";
                        cin>>item;
                        cout<<"Enter the index to insert on: ";
                        cin>>index;
                        insertAtIndex(item, index);
                        break;

                case 4:
                        deleteFromHead();
                        break;
                
                case 5:
                        deleteFromTail();
                        break;
                
                case 6:
                        cout<<"Enter the index to delete from: ";
                        cin>>index;
                        deleteAtIndex(index);
                        break;

                case 7: 
                        traverse();
                        break;

                case 8:
                        

                case -1:
                        break;

                default:
                        cout<<"Invalid choice!\n";
            }
        }
    }

};



// class DoublyLinkedList{
//     struct Node{
//         int data;
//         Node* next;
//         Node* prev;
//     }*head;

//     public:

//     void insertFromHead(){

//     }

//     void traverse(){

//         if(head == NULL){
//             cout<<"Empty List.";
//             return;
//         }

//         Node *temp = head;

//         while(temp->next == NULL){
//             cout<<temp->data<<" -> ";
//             temp = temp->next;
//         }

//         cout<<"NULL\n";
//     }


    
//     void interface(){
//         int choice=0, item, index;

//         while(choice != -1){
//             cout<<"1) Insert from Head\n";
//             cout<<"2) Insert from Tail\n";
//             cout<<"3) Insert at an Index\n";
//             cout<<"4) Delete from Head\n";
//             cout<<"5) Delete from Tail\n";
//             cout<<"6) Delete at an Index\n";
//             cout<<"7) Traverse the list\n";
//             cout<<"-1) Exit\n";
//             cout<<"Enter your choice: ";
//             cin>>choice;

//             switch(choice){
//                 case 1:
//                         cout<<"Enter a number to insert: ";
//                         cin>>item;
//                         insertFromHead(item);
//                         break;

//                 case 2:
//                         cout<<"Enter a number to insert: ";
//                         cin>>item;
//                         insertFromTail(item);
//                         break;

//                 case 3:
//                         cout<<"Enter a number to insert: ";
//                         cin>>item;
//                         cout<<"Enter the index to insert on: ";
//                         cin>>index;
//                         insertAtIndex(item, index);
//                         break;

//                 case 4:
//                         deleteFromHead();
//                         break;
                
//                 case 5:
//                         deleteFromTail();
//                         break;
                
//                 case 6:
//                         cout<<"Enter the index to delete from: ";
//                         cin>>index;
//                         deleteAtIndex(index);
//                         break;

//                 case 7: 
//                         traverse();
//                         break;

//                 default:
//                         cout<<"Invalid choice!";
//             }
//         }
//     }

// };



int main(){
    SinglyLinkedList SLL;
    SLL.interface();
    return 0;
}