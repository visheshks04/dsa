#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief 
 * arr pointer to the base
 * currentSize track
 * MAX size to be allocated at the start
 * update
 * append
 * insert
 * delete
 * rotate
 * reverse
 * traverse
 * max
 * min
 * argmax
 * argmin
 * countAllOccurancesOf
 * Searching
 *      Linear Search
 *      Binary Search
 * Sorting
 *      Selection Sort
 *      Bubble Sort
 *      Insertion Sort
 *      Merge Sort
 *      Quick Sort
 */

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

    Array(const Array &a){ // copy constructor
        cout<<"Copying Array object.\n";
        currentSize = a.currentSize;
        MAX = a.MAX;
        arr = new int[MAX];
        for(int i=0;i<currentSize;i++){
            arr[i] = a.arr[i];
        }
    }

    void insert(int, int);
    void update(int, int);
    void append(int);
    void del(int);
    void traverse();
    int min();
    int max();
    int argmin();
    int argmax();
    void reverse();
    int countAllOccurancesOf(int);
    void rotate(int);


    int linearSearch(int);
    int binarySearch(int);


    void selectionSort();
    void bubbleSort();
    void insertionSort();

    void merge();
    void mergeSort();

    void partition();
    void quickSort();

    ~Array(){
        delete arr;
        cout<<"Good bye :)\n";
    }

    void interface(){
        int choice=0, item, index;

        while(choice != -1){
            cout<<"1) Insert at an index\n";
            cout<<"2) Update an index\n";
            cout<<"3) Append\n";
            cout<<"4) Delete from an index\n";
            cout<<"5) Traversal\n";
            cout<<"6) Min\n";
            cout<<"7) Max\n";
            cout<<"8) ArgMin\n";
            cout<<"9) ArgMax\n";
            cout<<"10) Reverse\n";
            cout<<"11) Count All Occurances of a number\n";
            cout<<"12) Rotate\n";
            cout<<"13) Linear Search\n";
            cout<<"14) Binary Search\n";
            cout<<"15) Selection Sort\n";
            cout<<"16) Bubble Sort\n";
            cout<<"17) Insertion Sort\n";
            cout<<"18) Merge Sort\n";
            cout<<"19) Quick Sort\n";
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
                        cout<<"Enter the index to update: ";
                        cin>>index;
                        cout<<"Enter the new value: ";
                        cin>>item;
                        update(index, item);
                        break;


                case 3:
                        cout<<"Enter the number to append: ";
                        cin>>item;
                        append(item);
                        break;

                case 4:
                        cout<<"Enter the index to delete from: ";
                        cin>>index;
                        del(index);
                        break;

                case 5:
                        traverse();
                        break;

                case 6:
                        cout<<"Minimum value is" << min() << endl;
                        break;

                case 7:
                        cout<<"Maximum value is" << max() << endl;
                        break;

                case 8:
                        cout<<argmin()<<endl;
                        break;
                
                case 9:
                        cout<<argmax()<<endl;
                        break;
                
                case 10:
                        reverse();
                        break;

                case 11: 
                        cout<<"Enter a number to find: ";
                        cin>>item;
                        cout<<countAllOccurancesOf(item)<<endl;
                        break;

                case 12:
                        cout<<"Enter number of times to rotate left: ";
                        cin>>item;
                        rotate(item);
                        break;

                case 13:
                        cout<<"Enter an item to search: ";
                        cin>>item;
                        cout<<"The item was found on index: "<<linearSearch(item);
                        break;

                case 14:
                        cout<<"Enter an item to search: ";
                        cin>>item;
                        cout<<"The item was found on index: "<<binarySearch(item);
                        break;

                case 15:
                        selectionSort();
                        break;

                case 16:
                        bubbleSort();
                        break;

                case 17:
                        insertionSort();
                        break;

                case 18:
                        mergeSort();
                        break;

                case 19:
                        quickSort();
                        break;

                default:
                        cout<<"Invalid choice!";
            }
        }
    }

};

void Array::insert(int index, int value){

    if(index>MAX-1){
        cout<<"Index out of max size limit.\n";
        return;
    }

    if(index>currentSize-1){
        cout<<"Index out of current size limit.\n";
        return;
    }

    if(currentSize == MAX-1){
        cout<<"Overflow!\n";
        return;
    }

    currentSize++;

    for(int i=currentSize-1;i>index;i--){
        arr[i] = arr[i-1];
    }

    arr[index] = value;
}

void Array::update(int index, int value){

    if(index>currentSize-1 || index<0)
        return;

    arr[index] = value;
}

void Array::append(int value){
    if (currentSize > MAX-1){
        cout<<"Overflow!\n";
        return;
    }

    currentSize++;
    arr[currentSize] = value;
}

void Array::del(int index){
    if(index > currentSize-1){
        cout<<"Accessing index out of bounds.\n";
        return;
    }

    for(int i=index;i<currentSize-1;i++){
        arr[i] = arr[i+1];
    }

    currentSize--;
}

void Array::traverse(){
    for(int i=0;i<currentSize;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int Array::min(){
    int x = INT_MAX;

    for(int i=0;i<currentSize;i++){
        if(x > arr[i])
            x = arr[i];
    }

    return x;
}

int Array::max(){
    int x = INT_MIN;

    for(int i=0;i<currentSize;i++){
        if(x < arr[i])
            x = arr[i];
    }

    return x;
}

int Array::argmin(){
    int x = 0;

    for(int i=1;i<currentSize;i++){
        if(arr[x] > arr[i])
            x = i;
    }

    return x;
}

int Array::argmax(){
    int x = 0;

    for(int i=1;i<currentSize;i++){
        if(arr[x] < arr[i])
            x = i;
    }

    return x;
}

void Array::reverse(){
    int temp;
    for(int i=0; i<currentSize/2;i++){
        temp = arr[i];
        arr[i] = arr[currentSize-i];
        arr[currentSize-i] = temp;
    }
}


int Array::countAllOccurancesOf(int x){
    int count = 0;

    for(int i=0;i<currentSize;i++){
        if(arr[i] == x)
            count++;
    }

    return count;
}

void Array::rotate(int n){

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


int Array::linearSearch(int value){
    for(int i=0;i<currentSize;i++){
        if(arr[i] == value){
            return i;
        }
    }

    return -1;
}

int Array::binarySearch(int value){

    cout<<"NOTE: Make sure the array is in non decreasing order.\n";

    int hi=currentSize-1, lo=0, mid;

    while(hi>lo){
        mid = (hi+lo)/2;
        
        if(arr[mid] == value){
            return mid;
        }

        else if(arr[mid] > value){
            hi = mid-1;
        }

        else{
            lo = mid+1;
        }
    }

    return -1;
}


void Array::selectionSort(){
    int min = 0;
    for(int i=0;i<currentSize;i++){
        for(int j=0;j<currentSize;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void Array::bubbleSort(){

    for(int i=0;i<currentSize;i++){
        for(int j=0;j<currentSize-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void Array::insertionSort(){

    int i, j;
    
    for(i=1;i<currentSize;i++){

        int key = arr[i];

        for (j=i; j>=0; j--){
            if(arr[j-1] > key){
                arr[j] = arr[j-1];
            }
            else{
                break;
            }
        }
        arr[j] = key;
    }
}

void Array::merge(){

}

void Array::mergeSort(int *ar, int l, int h){

    if(l<r){
        int m = (l+h)/2;
        mergeSort(l, m+1);

    }
    
}

int main(){

    Array a;
    a.interface();

    return 0;
}