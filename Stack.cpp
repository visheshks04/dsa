#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Stack{
    int *stack, top, MAX;

    public:

    Stack(){
        cout<<"Enter the max size of the Stack: ";
        cin>>MAX;
        top = -1;
        stack = new int[MAX];
    }

    Stack(int size){
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
                cout<<" <- TOP";

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

int main(){
    Stack s;
    s.interface();

    return 0;
}