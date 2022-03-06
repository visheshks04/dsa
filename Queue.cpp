#include <iostream>

using std::cin;
using std::cout;
using std::endl;



class LinearQueue{
    int *q, MAX, f, r;

    public:

    LinearQueue(){
        cout<<"Enter the max size of the queue: ";
        cin>>MAX;
        f = -1;
        r = -1;
        q = new int[MAX];
    }

    LinearQueue(int size){
        MAX = size;
        f = -1;
        r = -1;
        q = new int[MAX];
    }

    void enqueue(int item){
        if(f == -1 && r == -1){
            f = 0;
            r = 0;
            q[r] = item;
            return;
        }

        if(r == MAX-1){
            cout<<"Queue is full.\n";
            return;
        }

        r++;
        q[r] = item;
    }

    int dequeue(){
        if(f == -1 && r == -1){
            cout<<"Queue is empty.\n";
            return -1;
        }

        if(f == r){
            int item = q[f];
            f = -1;
            r = -1;
            return item;
        }

        int item = q[f];
        f++;
        return item;
    }

    void display(){
        if(f == -1 && r==-1){
            cout<<"Queue is empty.\n";
            return;
        }

        for(int i=f;i<=r;i++){
            cout<<q[i]<<"\t";
        }
        cout<<endl;
        cout<<"^F";
        for(int i=f+1;i<=r;i++){
            cout<<"\t";
        }
        cout<<"^R\n";
    }

    void interface(){
        int choice=0, item;

        while(choice != -1){
            cout<<"1) Enqueue\n";
            cout<<"2) Dequeue\n";
            cout<<"3) Display\n";
            cout<<"-1) Exit\n";

            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                        cout<<"Enter a number to enqueue: ";
                        cin>>item;
                        enqueue(item);
                        break;

                case 2:
                        cout<<"Element that was dequeued: "<<dequeue()<<endl;
                        break;
                    
                case 3:
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




class LinearQueueLL{
    struct Node{
        int data;
        Node* next;
    }*f, *r;

    public:

    LinearQueueLL(){
        f = NULL;
        r = NULL;
    }

    void enqueue(int item){
        if(f == NULL and r == NULL){
            r = new Node;
            if(r == NULL){
                cout<<"Overflow!\n";
                return;
            }
            r->data = item;
            f = r;
            return;
        }
        r->next = new Node;
        if(r->next == NULL){
            cout<<"Overflow!\n";
            return;
        }
        r->next->data = item;
        r = r->next;
    }

    int dequeue(){
        if(f == NULL && r == NULL){
            cout<<"The queue is empty.\n";
            return -1;
        }

        if(f == r){
            int item = f->data;
            Node *temp = f;
            f = NULL;
            r = NULL;
            delete temp;
            return item;
        }

        int item = f->data;
        Node *temp = f;
        f = f->next;
        delete temp;
        return item;
    }

    void display(){
        if(f == NULL && r == NULL){
            cout<<"Empty Queue.\n";
            return;
        }

        Node *temp = f;
        while(temp != NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
        cout<<"^F";
        temp = f->next;
        while(temp != NULL){
            cout<<"\t";
            temp = temp->next;
        }
        cout<<"^R";
        cout<<endl;
    }

    void interface(){
        int choice=0, item;

        while(choice != -1){
            cout<<"1) Enqueue\n";
            cout<<"2) Dequeue\n";
            cout<<"3) Display\n";
            cout<<"-1) Exit\n";

            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                        cout<<"Enter a number to enqueue: ";
                        cin>>item;
                        enqueue(item);
                        break;

                case 2:
                        cout<<"Element that was dequeued: "<<dequeue()<<endl;
                        break;
                    
                case 3:
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
    LinearQueueLL q;
    q.interface();
    return 0;
}