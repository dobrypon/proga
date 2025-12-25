#include <iostream>
#include <cmath>
using namespace std;

// ------------------------------
// 1. Вывести все числа от 1 до n
// ------------------------------
void print1toN(int n, int current = 1) {
    if (current > n) return;
    cout << current << " ";
    print1toN(n, current + 1);
}

// ------------------------------
// 2. Вывести все числа от A до B
// ------------------------------
void printAtoB(int A, int B) {
    cout << A << " ";
    if (A == B) return;
    if (A < B) printAtoB(A + 1, B);
    else printAtoB(A - 1, B);
}

// ------------------------------
// 3. Сумма цифр числа N
// ------------------------------
int sumDigits(int N) {
    N = abs(N);  // делаем число положительным
    if (N == 0) return 0;
    return N % 10 + sumDigits(N / 10);
}

// ------------------------------
// 4. Простые делители числа n (>1), рекурсивно
// ------------------------------
void printUniquePrimeDivisors(int n, int d = 2) {
    if (n <= 1) return; // если число <= 1, ничего не делаем

    if (n % d == 0) {   // нашли простой делитель
        cout << d << " ";
        while (n % d == 0) n /= d; // убираем все кратные текущему делителю
    }

    printUniquePrimeDivisors(n, d + 1); // проверяем следующий делитель
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int choice;
    cout << "Выберите задачу:\n";
    cout << "1 - Числа от 1 до n\n";
    cout << "2 - Числа от A до B\n";
    cout << "3 - Сумма цифр числа N\n";
    cout << "4 - Простые делители числа n\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int n;
        cout << "Введите n: ";
        cin >> n;
        print1toN(n);
        cout << endl;
        break;
    }
    case 2: {
        int A, B;
        cout << "Введите A и B: ";
        cin >> A >> B;
        printAtoB(A, B);
        cout << endl;
        break;
    }
    case 3: {
        int N;
        cout << "Введите N: ";
        cin >> N;
        cout << "Сумма цифр: " << sumDigits(N) << endl;
        break;
    }
    case 4: {
        int n;
        cout << "Введите n (>1): ";
        cin >> n;
        cout << "Простые делители: ";
        printUniquePrimeDivisors(n);
        cout << endl;
        break;
    }
    default:
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}
