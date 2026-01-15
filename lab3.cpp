#include <iostream>

int sumArray(int* begin, int* end) {
    int sum = 0;
    for (int* p = begin; p != end; ++p)
        sum += *p;
    return sum;
}

int sum(int a, int b) {
    return a + b;
}

int diff(int a, int b) {
    return a - b;
}

typedef int(*FuncPtr)(int, int);

FuncPtr chooseFunc(char c) {
    if (c == '+') return sum;
    else return diff;
}

int main() {
    int var = 10;
    int* ptr = &var;
    std::cout << ptr << " " << *ptr << std::endl;
    *ptr = 20;
    std::cout << var << std::endl;

    int arr[5] = { 1,2,3,4,5 };
    int* pArr = arr;
    for (int i = 0; i < 5; ++i)
        std::cout << *(pArr + i) << " ";
    std::cout << std::endl;

    int n = 5;
    int* const ptrConst = &n;
    *ptrConst = 10;
    std::cout << n << std::endl;

    std::cout << sumArray(arr, arr + 5) << std::endl;

    FuncPtr f = chooseFunc('+');
    std::cout << f(7, 3) << std::endl;

    float* fptr = new float(3.14);
    std::cout << fptr << std::endl;
    delete fptr;

    return 0;
}
