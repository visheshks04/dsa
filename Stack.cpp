#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class StackArr{
    int *stack, top, MAX;

    public:

    StackArr(){
        cout<<"Enter the max size of the Stack: ";
        cin>>MAX;
        top = -1;
        stack = new int[MAX];
    }

    StackArr(int size){
        MAX = size;
        top = -1;
        stack = new int[MAX];
    }

    void push(int item){
        if(top == MAX-1){
            cout<<"Overflow!\n";
            return;
        }

        top++;
        stack[top] = item;
    }

    int pop(){
        if(top == -1){
            cout<<"Underflow\n";
            return -1;
        }

        int item = stack[top];
        top --;

        return item;
    }

    int peek(){
        if(top == -1){
            cout<<"Empty.\n";
            return -1;
        }

        return stack[top];
    }

    void display(){
        if(top == -1){
            cout<<"Empty\n";
            return;
        }

        for(int i=top;i>=0;i--){
            cout<<stack[i];
            if(i == top)
                cout<<" <-- TOP";

            cout<<endl;
        }
    }

    void interface(){
        int choice=0, item;

        while(choice != -1){
            cout<<"1) Push\n";
            cout<<"2) Pop\n";
            cout<<"3) Peek\n";
            cout<<"4) Display\n";
            cout<<"-1) Exit\n";

            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                        cout<<"Enter a number to push: ";
                        cin>>item;
                        push(item);
                        break;

                case 2:
                        cout<<"Element that was popped: "<<pop()<<endl;
                        break;

                case 3:
                        cout<<"The top element is: "<<peek()<<endl;
                        break;
                    
                case 4:
                        display();
                        break;

                case -1:
                        break;

                default:
                        cout<<"Invalid choice!\n";
            }
        }
    }
};




class StackLL{
    struct Node{
        int data;
        Node* next;
    }*top;

    public:

    StackLL(){
        top = NULL;
    }

    void push(int item){
        if(top == NULL){
            top = new Node;
            if(top == NULL){
                cout<<"Overflow\n";
                return;
            }
            top->data = item;
            top->next = NULL;
        }

        Node *temp = new Node;
        if(temp == NULL){
            cout<<"Overflow\n";
            return;
        }

        temp->data = item;
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == NULL){
            cout<<"Underflow\n";
            return -1;
        }

        int item = top->data;
        top = top->next;
        return item;
    }

    int peek(){
        if(top == NULL){
            cout<<"Empty Stack.\n";
            return -1;
        }

        return top->data;
    }

    void display(){
        if(top == NULL){
            cout<<"Empty Stack.\n";
            return;
        }

        Node *temp = top;
        cout<<temp->data<<" <-- TOP"<<endl;
        temp = temp->next;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

    void interface(){
        int choice=0, item;

        while(choice != -1){
            cout<<"1) Push\n";
            cout<<"2) Pop\n";
            cout<<"3) Peek\n";
            cout<<"4) Display\n";
            cout<<"-1) Exit\n";

            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                        cout<<"Enter a number to push: ";
                        cin>>item;
                        push(item);
                        break;

                case 2:
                        cout<<"Element that was popped: "<<pop()<<endl;
                        break;

                case 3:
                        cout<<"The top element is: "<<peek()<<endl;
                        break;
                    
                case 4:
                        display();
                        break;

                case -1:
                        break;

                default:
                        cout<<"Invalid choice!\n";
            }
        }
    }
};



int main(){
    StackLL s;
    s.interface();

    return 0;
}