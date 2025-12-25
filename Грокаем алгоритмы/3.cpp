#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void task1() {
    const int SIZE = 1000;
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; 
    }

    auto quickSort = [](int* a, int low, int high, auto&& quickSortRef) -> void {
        if (low < high) {
            int pivot = a[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (a[j] < pivot) {
                    i++;
                    swap(a[i], a[j]);
                }
            }
            swap(a[i + 1], a[high]);
            int pi = i + 1;
            quickSortRef(a, low, pi - 1, quickSortRef);
            quickSortRef(a, pi + 1, high, quickSortRef);
        }
        };

    quickSort(arr, 0, SIZE - 1, quickSort);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < 1000; i++) cout << arr[i] << " ";
    cout << "...\n";
}

void task2() {
    const int SIZE = 20;
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 50 + rand() % 51; 
    }


    auto quickSort = [](int* a, int low, int high, auto&& quickSortRef) -> void {
        if (low < high) {
            int pivot = a[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (a[j] < pivot) {
                    i++;
                    swap(a[i], a[j]);
                }
            }
            swap(a[i + 1], a[high]);
            int pi = i + 1;
            quickSortRef(a, low, pi - 1, quickSortRef);
            quickSortRef(a, pi + 1, high, quickSortRef);
        }
        };

    quickSort(arr, 0, SIZE - 1, quickSort);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
    cout << endl;
}

void task3() {
    const int ROWS = 5;
    const int COLS = 4;
    int arr[ROWS][COLS];

    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 5 + rand() % 57; 
        }
    }


    auto quickSort = [](int a[][4], int low, int high, auto&& quickSortRef) -> void {
        if (low < high) {
            int pivot = a[high][0];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (a[j][0] < pivot) {
                    i++;
                    for (int k = 0; k < 4; k++) swap(a[i][k], a[j][k]);
                }
            }
            for (int k = 0; k < 4; k++) swap(a[i + 1][k], a[high][k]);
            int pi = i + 1;
            quickSortRef(a, low, pi - 1, quickSortRef);
            quickSortRef(a, pi + 1, high, quickSortRef);
        }
        };

    quickSort(arr, 0, ROWS - 1, quickSort);

    cout << "Отсортированный массив по первому столбцу:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}


struct Student {
    char name[50];
};

int compareStudents(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

void task4() {
    Student group[5] = { {"Ivan"}, {"Anna"}, {"Petr"}, {"Olga"}, {"Sergey"} };

    qsort(group, 5, sizeof(Student), compareStudents);

    cout << "Список студентов по алфавиту:\n";
    for (int i = 0; i < 5; i++) cout << group[i].name << endl;
}


int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int choice;
    cout << "Выберите задачу (1-4): ";
    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: task4(); break;
    default: cout << "Неверный выбор!\n";
    }

    return 0;
}
