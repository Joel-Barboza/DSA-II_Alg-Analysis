#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <cmath>
#include <chrono>
void bubbleSort(int array[], int size) {

    // loop to access each array element
    for (int step = 0; step < size -1; ++step) {

        // loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {

                // swapping elements if elements
                // are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int left,
           int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    int L[n1], R[n2];

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int bblSortTheoreticalWorst(int n){
    return n*n;
}

int** bblSortEmpiricalWorst() {
    // Allocate matrix
    int** matrix = new int*[4];
    for (int i = 0; i < 5; ++i) {
        matrix[i] = new int[2];
    }

    int arr[100000];

    // Sort and time for various sizes
    matrix[0][0] = 0;
    matrix[0][1] = 0;
    auto timeSortAndRecord = [&](int size, int index) {
        for (int var = 1; var < size; ++var) {
            arr[var] = rand();
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        // bubbleSort(arr, size);
        mergeSort(arr, 0, size - 1);
        auto t2 = std::chrono::high_resolution_clock::now();

        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::microseconds;

        duration<double, std::micro> ms_double = t2 - t1;
        matrix[index][0] = size;
        matrix[index][1] = ms_double.count();
    };



    //timeSortAndRecord(pow(2,9), 0);
    timeSortAndRecord(pow(2,10), 1);
    timeSortAndRecord(pow(2,12), 2);
    timeSortAndRecord(pow(2,15), 3);
    // timeSortAndRecord(1000000, 4);

    return matrix;
}

void deleteMatrix(int** matrix) {
    for (int i = 0; i < 4; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

#endif // BUBBLESORT_H
