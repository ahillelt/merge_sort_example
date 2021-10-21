#include<iostream>
using namespace std;
//merge sort

//driver function (the controller, sets up the function)
void merge_sort(int array[], int size);

void merge_sort(int array[], int start, int end);

void merge(int array[], int low_left, int high_left, int high_right);

void display_array(int array[], int size);

int main() {
    int size = 10;

    int* array = new int[size] {8,6,1,9,7,4,3,58,-5,-50};

    //merge sort call
    merge_sort(array,size);

    //display function
    display_array(array,size);

    delete [] array;
    return 0;
}

//driver
void merge_sort(int array[], int size){
    int start, end;

    start = 0;
    end = size -1;

    merge_sort(array,start,end);
}

void merge_sort(int array[], int start, int end){
   if(start<end){
    int mid = (start+end)/2;

    //left side
    merge_sort(array,start,mid);

    //right side
    merge_sort(array,mid+1,end);


    // 8 7 6 94 68 12 345 334
    // 8 7 6 94 left
    // 68 12 345 334 rhs

    //merge left and right side together in order
    merge(array,start,mid,end);

   }

}

void merge(int array[], int low_left, int high_left, int high_right){
    int low_right = high_left +1;

    int array1_size = high_left - low_left +1;
    int array2_size = high_right - low_right +1;

    int* array1 = new int[array1_size];
    int* array2 = new int[array2_size];

    for(int i =0; i<array1_size; i++){
        array1[i] = array[i+low_left];
    }

    for(int j =0; j<array2_size; j++){
        array2[j] = array[j+low_right];
    }

    int i = 0; //array1_index position
    int j = 0; //array2_index position

    int k = low_left;


    while(i < array1_size && j <array2_size){

        if(array1[i] <= array2[j]){
            array[k] = array1[i];
            i++;
        } else{
            array[k] = array2[j];
            j++;
        }
        k++;
    }

    //cleaning up

    //remaining array 1 elements

    while(i < array1_size){
        array[k] = array1[i];
        i++;
        k++;
    }

    //remaining array 2 elements

    while(j < array2_size){
        array[k] = array2[j];
        j++;
        k++;
    }


    delete [] array1;
    delete [] array2;
}

void display_array(int array[], int size) {
    cout << "[ ";

    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            cout << array[i] << ", ";
        } else {
            cout << array[i] << " ";
        }
    }

    cout << "]" << endl;
}





