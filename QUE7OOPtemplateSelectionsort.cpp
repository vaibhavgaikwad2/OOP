
#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Original integer array: ";
    printArray(intArray, intSize);

    // Sort integer array
    selectionSort(intArray, intSize);
    cout << "Sorted integer array: ";
    printArray(intArray, intSize);

    // Float array
    float floatArray[] = {64.5, 25.1, 12.7, 22.8, 11.9};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "Original float array: ";
    printArray(floatArray, floatSize);

    // Sort float array
    selectionSort(floatArray, floatSize);
    cout << "Sorted float array: ";
    printArray(floatArray, floatSize);

    return 0;
}
