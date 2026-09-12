// Cesar Cardenas - A00844803

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Estructura para contar comparaciones e intercambios
struct Stats {
    long long comparisons = 0;
    long long swaps = 0;
};

//Algoritmos de ordenamiento. 

// 1. Swap Sort
void swapSort(vector<int>& list, Stats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    int size = list.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            stats.comparisons++;
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                stats.swaps++;
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(vector<int>& list, Stats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    int size = list.size();

    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            stats.comparisons++;
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = list[i];
            list[i] = list[min];
            list[min] = temp;
            stats.swaps++;
        }
    }
}

// 3. Bubble Sort
void bubbleSort(vector<int>& list, Stats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    int size = list.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            stats.comparisons++;
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                stats.swaps++;
            }
        }
    }
}

// 4. Insertion Sort
void insertionSort(vector<int>& list, Stats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    int size = list.size();

    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;

        while (j >= 0) {
            stats.comparisons++;
            if (list[j] > key) {
                list[j + 1] = list[j];
                stats.swaps++;
                j--;
            } else {
                break;
            }
        }
        list[j + 1] = key;
    }
}

// 5. Merge Sort
void merge(vector<int>& list, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = list[left + i];
    for (int j = 0; j < n2; j++) R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { list[k] = L[i]; i++; k++; }
    while (j < n2) { list[k] = R[j]; j++; k++; }
}

void mergeSortHelper(vector<int>& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(list, left, mid);
        mergeSortHelper(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

void mergeSort(vector<int>& list) {
    if (!list.empty()) {
        mergeSortHelper(list, 0, list.size() - 1);
    }
}

// 6. Quick Sort
int partition(vector<int>& list, int low, int high) {
    int pivot = list[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    int temp = list[i + 1];
    list[i + 1] = list[high];
    list[high] = temp;
    return (i + 1);
}

void quickSortHelper(vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSortHelper(list, low, pi - 1);
        quickSortHelper(list, pi + 1, high);
    }
}

void quickSort(vector<int>& list) {
    if (!list.empty()) {
        quickSortHelper(list, 0, list.size() - 1);
    }
}

// 7. Shell Sort (Algoritmo extra)
void shellSort(vector<int>& list) {
    int n = list.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = list[i];
            int j;
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap) {
                list[j] = list[j - gap];
            }
            list[j] = temp;
        }
    }
}

// --- FUNCIONES AUXILIARES ---

void generateRandomVector(vector<int>& vec, int size) {
    vec.resize(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % 100000;
    }
}

void printList(const vector<int>& list) {
    int limit = list.size() < 20 ? list.size() : 20;
    for (int i = 0; i < limit; i++) {
        cout << list[i] << " ";
    }
    if (list.size() > 20) cout << "...";
    cout << endl;
}

int main() {
    srand(time(0));
    vector<int> currentList;
    int option = 0;

    do {
        cout << "\nMenu" << endl;
        cout << "1. Crear lista aleatoria" << endl;
        cout << "2. Swap Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Bubble Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Quick Sort" << endl;
        cout << "8. Shell Sort" << endl;
        cout << "9. Generar reporte comparativo" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> option;

        if (option == 1) {
            int size;
            cout << "Cantidad de elementos (1000, 10000, 100000): ";
            cin >> size;
            generateRandomVector(currentList, size);
            cout << "Lista generada: ";
            printList(currentList);
        }
        else if (option >= 2 && option <= 8) {
            if (currentList.empty()) {
                cout << "Primero crea una lista con la opcion 1." << endl;
                continue;
            }

            vector<int> temp = currentList;
            Stats stats;

            auto start = chrono::high_resolution_clock::now();

            switch (option) {
                case 2: swapSort(temp, stats); break;
                case 3: selectionSort(temp, stats); break;
                case 4: bubbleSort(temp, stats); break;
                case 5: insertionSort(temp, stats); break;
                case 6: mergeSort(temp); break;
                case 7: quickSort(temp); break;
                case 8: shellSort(temp); break;
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            cout << "\nLista ordenada: ";
            printList(temp);
            cout << "Tiempo de ejecucion: " << duration << " ns" << endl;

            if (option >= 2 && option <= 5) {
                cout << "Comparaciones: " << stats.comparisons << endl;
                cout << "Intercambios: " << stats.swaps << endl;
            }
        }
        else if (option == 9) {
            int sizes[] = {1000, 10000, 100000};
            string names[] = {"SwapSort", "SelectionSort", "BubbleSort", "InsertionSort", "MergeSort", "QuickSort", "ShellSort"};

            cout << "\nalgoritmo, tipo de dato, tiempo1000, tiempo10000, tiempo100000" << endl;

            for (int a = 0; a < 7; a++) {
                cout << names[a] << ", int";
                for (int s = 0; s < 3; s++) {
                    // Evita congelar la consola con ordenamientos O(n^2) en 100,000 elementos
                    if (a <= 3 && sizes[s] == 100000) {
                        cout << ", N/A";
                        continue;
                    }

                    vector<int> testVec;
                    generateRandomVector(testVec, sizes[s]);
                    Stats dummyStats;

                    auto start = chrono::high_resolution_clock::now();
                    switch (a) {
                        case 0: swapSort(testVec, dummyStats); break;
                        case 1: selectionSort(testVec, dummyStats); break;
                        case 2: bubbleSort(testVec, dummyStats); break;
                        case 3: insertionSort(testVec, dummyStats); break;
                        case 4: mergeSort(testVec); break;
                        case 5: quickSort(testVec); break;
                        case 6: shellSort(testVec); break;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
                    cout << ", " << duration;
                }
                cout << endl;
            }
        }
    } while (option != 0);

    return 0;
}