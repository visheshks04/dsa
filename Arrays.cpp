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
    }




};

int main(){



    return 0;
}