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

};

int main(){

    

    return 0;
}