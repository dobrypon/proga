#include <iostream> // Подключение библиотеки iostream


static void task1()
{
    setlocale(LC_ALL, "Russian"); // Используем русскую локаль для корректного отображения кириллицы

    std::cout << "First string" << std::endl; // Выводим строку "First string" на английском и переводим строку (\n)
    std::cout << "Первая строка\nВторая строка" << std::endl; // Выводим строки "Первая строка" и "Вторая строка" на русском и переводим строку (\n)
    std::cout << "Спецсимволы \"\\\"" << std::endl; // Выводим строку с экранированными специальными символами
}

static void task2()
{
    int x = 150;
    float y = 15.933f;
    unsigned char z = 250;

    std::cout << "x = 150" << std::endl;
    std::cout << "y = 15.933" << std::endl;
    std::cout << "z = 250" << std::endl;

    unsigned char d = 6;
    const char* m = "Июля";
    int g = 2006;

    printf("Моя дата рождения: %d %s %d года\n", d, m, g);

    const unsigned char a = 2;
    const unsigned char b = 3;
    const char* os = "WINDOWS";

    printf("%d %d %s\n", a, b, os);
}
int main() // Главная функция программы
{
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите номер задания" << std::endl;
    std::cin >> n;

    if (n == 1)
        task1();
    else
        task2();

    return 0;
} // Обозначает конец тела функции main
