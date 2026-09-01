// Cesar Cardenas - A00844803

#include <iostream>
using namespace std;

// void insertionSort(int list[], int size) {

// }

void selectionSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }

        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

void printList(const int list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {15,7,3,9,12,5,2};
    // int data2[] = {14,2,9,3,10,23,5}
    int size = sizeof(data) / sizeof(data[0]);
    // int size2 = sizeof(data2) / sizeof(data2[0]);


    // cout << "Lista de numeros desordenada: ";
    // printList(data, size);

    // insertionSort(data, size);

    // cout << "Lista de numeros ordenada con insertion Sort:   ";
    // printList(data, size);


    cout << "Lista de numeros desordenada: ";
    printList(data, size);

    selectionSort(data, size);

    cout << "Lista de numeros ordenada con selection Sort: ";
    printList(data, size);

    return 0;
}
