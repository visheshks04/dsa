#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

class Array{
    int *arr, currentSize, MAX;

    public:

    Array(){ // default constructor
        cout<<"Enter the max capacity of Array: ";
        cin>>MAX;
        arr = new int[MAX];
        currentSize = 0;
    }

    Array(int size){ // param constructor
        MAX = size;
        arr = new int[MAX];
        currentSize = 0;
    }

    Array(const Array &a){
        cout<<"Copying Array object.\n";
        arr = a.arr;
        currentSize = a.currentSize;
        MAX = a.MAX;
    }

    void insert(int index, int value){

    }

    void del(int index){

    }

    void traverse(){
        for(int i=0;i<currentSize;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }

    int min(){
        int x = INT_MAX;

        for(int i=0;i<currentSize;i++){
            if(x > arr[i])
                x = arr[i];
        }

        return x;
    }

    int max(){
        int x = INT_MIN;

        for(int i=0;i<currentSize;i++){
            if(x < arr[i])
                x = arr[i];
        }

        return x;
    }

    int argmin(){
        int x = 0;

        for(int i=1;i<currentSize;i++){
            if(arr[x] > arr[i])
                x = i;
        }

        return x;
    }

    int argmax(){
        int x = 0;

        for(int i=1;i<currentSize;i++){
            if(arr[x] < arr[i])
                x = i;
        }

        return x;
    }

    void reverse(){
        int temp;
        for(int i=0; i<currentSize/2;i++){
            temp = arr[i];
            arr[i] = arr[currentSize-i];
            arr[currentSize-i] = temp;
        }
    }

    int countAllOccurancesOf(int x){
        int count = 0;

        for(int i=0;i<currentSize;i++){
            if(arr[i] == x)
                count++;
        }

        return count;
    }

    void update(int num, int index){

        if(index>currentSize-1 || index<0)
            return;

        arr[index] = num;
    }

    void rotate(int n){

        char side = 'l';
        if (n > currentSize / 2){
            n = currentSize - n;
            side = 'r';
        }

        int temp;

        switch (side){
        case 'l':
            while (n--)
            {
                temp = arr[0];
                for (int i = 0; i < currentSize - 1; i++)
                {
                    arr[i] = arr[i+1];
                }
                arr[currentSize-1] = temp;
            }
            break;
        case 'r':
            while (n--)
            {
                temp = arr[currentSize - 1];
                for (int i = currentSize - 1; i > 0; i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[0] = temp;
            }
        }
    }

    void interface(){
        int choice=0, item, index;

        while(choice != -1){
            cout<<"1) Insert at an index\n";
            cout<<"2) Delete from an index\n";
            cout<<"3) Traversal\n";
            cout<<"4) Min\n";
            cout<<"5) Max\n";
            cout<<"6) ArgMin\n";
            cout<<"7) ArgMax\n";
            cout<<"8) Reverse\n";
            cout<<"9) Count All Occurances of a number\n";
            cout<<"10) Update a value at an index\n";
            cout<<"11) Rotate\n";
            cout<<"-1) Exit\n";
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){

                case 1:
                        cout<<"Enter the index to insert on: ";
                        cin>>index;
                        cout<<"Enter the number to insert: ";
                        cin>>item;
                        insert(index, item);
                        break;

                case 2:
                        cout<<"Enter the index to delete from: ";
                        cin>>index;
                        del(index);
                        break;


                case 3:
                        traverse();
                        break;

                case 4:
                        cout<<"Minimum value is" << min() << endl;
                        break;

                case 5:
                        cout<<"Maximum value is" << max() << endl;
                        break;

                case 6:
                        cout<<argmin()<<endl;
                        break;
                
                case 7:
                        cout<<argmax()<<endl;
                        break;
                
                case 8:
                        reverse();
                        break;

                case 9: 
                        cout<<"Enter a number to find: ";
                        cin>>item;
                        countAllOccurancesOf(item);
                        break;

                case 10:
                        cout<<"Enter index to update: ";
                        cin>>index;
                        cout<<"Enter value to update";
                        cin>>item;
                        update(item, index);
                        break;

                case 11:
                        cout<<"Enter number of times to rotate left: ";
                        cin>>item;
                        rotate(item);
                        break;

                default:
                        cout<<"Invalid choice!";
            }
        }
    }

};

int main(){

    Array a;
    a.interface();

    return 0;
}