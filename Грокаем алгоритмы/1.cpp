#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  
#include <ctime>   
#include <sstream>  

using namespace std;


void selectionSortAsc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}


void selectionSortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        swap(arr[i], arr[max_idx]);
    }
}

int phoneToInt(const string& phone) {
    string digits;
    for (char c : phone) {
        if (isdigit(c))
            digits += c;
    }
    return stoi(digits);
}

void selectionSortPhones(vector<string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (phoneToInt(phones[j]) < phoneToInt(phones[min_idx]))
                min_idx = j;
        }
        swap(phones[i], phones[min_idx]);
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    srand(time(0));  
    vector<int> arr1(10);
    for (int& x : arr1)
        x = rand() % 102 + 2; // [2, 103]

    cout << "Массив [2,103] до сортировки: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    selectionSortAsc(arr1);

    cout << "Массив [2,103] после сортировки по возрастанию: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n";

  
    vector<int> arr2(10);
    for (int& x : arr2)
        x = rand() % 101; // [0,100]

    cout << "Массив [0,100] до сортировки: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    selectionSortDesc(arr2);

    cout << "Массив [0,100] после сортировки по убыванию: ";
    for (int x : arr2) cout << x << " ";
    cout << "\n\n";

    vector<string> phones = { "23-45-67", "12-34-56", "99-00-01", "55-44-33" };

    cout << "Список телефонов до сортировки: ";
    for (auto& p : phones) cout << p << " ";
    cout << endl;

    selectionSortPhones(phones);

    cout << "Список телефонов после сортировки по возрастанию: ";
    for (auto& p : phones) cout << p << " ";
    cout << endl;

    return 0;
}
